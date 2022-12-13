#include "macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *CommonMalloc(const uint32_t kuiSize, const char *kpTag,
                   const uint32_t kuiAlign) {
    const int32_t kiSizeOfVoidPointer = sizeof(void **);
    const int32_t kiSizeOfInt = sizeof(int32_t);
    const int32_t kiAlignedBytes = kuiAlign - 1;
    const int32_t kiTrialRequestedSize =
        kuiSize + kiAlignedBytes + kiSizeOfVoidPointer + kiSizeOfInt;
    const int32_t kiActualRequestedSize = kiTrialRequestedSize;
    const uint32_t kiPayloadSize = kuiSize;

    uint8_t *pBuf = (uint8_t *)malloc(kiActualRequestedSize);
    if (NULL == pBuf) {
        return NULL;
    }
    uint8_t *pAlignedBuffer;
    pAlignedBuffer = pBuf + kiAlignedBytes + kiSizeOfVoidPointer + kiSizeOfInt;
    pAlignedBuffer -= ((uintptr_t)pAlignedBuffer & kiAlignedBytes);
    *((void **)(pAlignedBuffer - kiSizeOfVoidPointer)) = pBuf;
    *((int32_t *)(pAlignedBuffer - kiSizeOfVoidPointer - kiSizeOfInt)) =
        kiPayloadSize;

    return (void *)pAlignedBuffer;
}

void *WelsMalloc(const uint32_t kuiSize, const char *kpTag) {
    const uint32_t kuiAlign = 16;
    void *pPointer = CommonMalloc(kuiSize, kpTag, kuiAlign);
    return pPointer;
}

void *WelsMallocz(const uint32_t kuiSize, const char *kpTag) {
    void *pPointer = WelsMalloc(kuiSize, kpTag);
    if (NULL == pPointer) {
        return NULL;
    }
    memset(pPointer, 0, kuiSize);
    return pPointer;
}

void WelsGetEncBlockStrideOffset(int32_t *pBlock, const int32_t kiStrideY,
                                 const int32_t kiStrideUV) {
    int32_t i, j, k, r;
    for (j = 0; j < 4; j++) {
        i = j << 2;
        k = (j & 0x01) << 1;
        r = j & 0x02;
        pBlock[i] = (0 + k + (0 + r) * kiStrideY) << 2;
        pBlock[i + 1] = (1 + k + (0 + r) * kiStrideY) << 2;
        pBlock[i + 2] = (0 + k + (1 + r) * kiStrideY) << 2;
        pBlock[i + 3] = (1 + k + (1 + r) * kiStrideY) << 2;

        pBlock[16 + j] = pBlock[20 + j] = ((j & 0x01) + r * kiStrideUV) << 2;
    }
}

void WelsFree(void *pPointer, const char *kpTag) {
    if (pPointer) {
        free(*(((void **)pPointer) - 1));
    }
}

int main(int argc, char *argv[]) {
    const int kiVideoWidth = 1296;
    const int kiVideoHeight = 1440;

    struct {
        int iMbWidth;
        int iCountNum;
        int iSizeAllMbAlignCache;
    } sMbSizeMap[MAX_DEPENDENCY_LAYER] = {{0}};
    int iLineSizeY[MAX_DEPENDENCY_LAYER][2] = {{0}};
    int iLineSizeUV[MAX_DEPENDENCY_LAYER][2] = {{0}};
    int iMapSpatialIdx[MAX_DEPENDENCY_LAYER][2] = {{0}};

    int iSizeEnc = 0;
    int iSizeDec = 0;
    int iCountLayersNeedCs[2] = {0};
    const int kiUnit1Size = 24 * sizeof(int);
    const int kiNumSpatialLayers = 1;
    int iUnit2Size = 0;
    int iNeedAllocSize = 0;
    int iRowSize = 0;
    int iMaxMbWidth = 0;
    int iMaxMbHeight = 0;
    int i = 0;
    int iSpatialIdx = 0;
    int iTemporalIdx = 0;
    int iCntTid = 1;

    uint8_t *pBase = NULL;
    uint8_t *pBaseDec = NULL, *pBaseEnc = NULL, *pBaseMbX = NULL,
            *pBaseMbY = NULL;
    int16_t *pMbIndexX[MAX_DEPENDENCY_LAYER];
    int16_t *pMbIndexY[MAX_DEPENDENCY_LAYER];
    int16_t *pTmpRow = NULL, *pRowX = NULL, *pRowY = NULL, *p = NULL;

    iSpatialIdx = 0;
    while (iSpatialIdx < kiNumSpatialLayers) {
        const int kiTmpWidth = (kiVideoWidth + 15) >> 4;
        const int kiTmpHeight = (kiVideoHeight + 15) >> 4;
        int iNumMb = kiTmpWidth * kiTmpHeight;

        sMbSizeMap[iSpatialIdx].iMbWidth = kiTmpWidth;
        sMbSizeMap[iSpatialIdx].iCountNum = iNumMb;

        printf("kiTmpWidth = %d, kiTmpHeight = %d, iNumMb = %d\n", kiTmpWidth,
               kiTmpHeight, iNumMb);

        iNumMb *= sizeof(short);
        sMbSizeMap[iSpatialIdx].iSizeAllMbAlignCache = iNumMb;
        iUnit2Size += iNumMb;
        ++iSpatialIdx;
    }

    iTemporalIdx = 0;
    while (iTemporalIdx < iCntTid) {
        const bool kbBaseTemporalFlag = (iTemporalIdx == 0);
        iSpatialIdx = 0;
        while (iSpatialIdx < kiNumSpatialLayers) {

            const int kiWidthPad =
                WELS_ALIGN(kiVideoWidth, 16) + (PADDING_LENGTH << 1);
            iLineSizeY[iSpatialIdx][kbBaseTemporalFlag] =
                WELS_ALIGN(kiWidthPad, 32);
            iLineSizeUV[iSpatialIdx][kbBaseTemporalFlag] =
                WELS_ALIGN((kiWidthPad >> 1), 16);

            iMapSpatialIdx[iCountLayersNeedCs[kbBaseTemporalFlag]]
                          [kbBaseTemporalFlag] = iSpatialIdx;

            printf("kiWidthPad = %d %d %d\n", kiWidthPad,
                   iLineSizeY[iSpatialIdx][kbBaseTemporalFlag],
                   iLineSizeUV[iSpatialIdx][kbBaseTemporalFlag]);

            ++iCountLayersNeedCs[kbBaseTemporalFlag];
            ++iSpatialIdx;
        }
        ++iTemporalIdx;
    }
    iSizeDec = kiUnit1Size * (iCountLayersNeedCs[0] + iCountLayersNeedCs[1]);
    iSizeEnc = kiUnit1Size * kiNumSpatialLayers;

    iNeedAllocSize = iSizeDec + iSizeEnc + (iUnit2Size << 1);

    printf("kiUnit1Size = %d, iUnit2Size = %d, iSizeEnc = %d, iSizeDec = %d, "
           "iNeedAllocSize = %d\n",
           kiUnit1Size, iUnit2Size, iSizeEnc, iSizeDec, iNeedAllocSize);

    pBase = (uint8_t *)WelsMallocz(iNeedAllocSize, "pBase");
    if (NULL == pBase) {
        printf("pBase == NULL\n");
        return 1;
    } else {
        printf("pBase == %p\n", pBase);
    }

    pBaseDec = pBase;
    pBaseEnc = pBaseDec + iSizeDec;
    pBaseMbX = pBaseEnc + iSizeEnc;
    pBaseMbY = pBaseMbX + iUnit2Size;

    iTemporalIdx = 0;
    while (iTemporalIdx < iCntTid) {
        const bool kbBaseTemporalFlag = (iTemporalIdx == 0);
        iSpatialIdx = 0;
        while (iSpatialIdx < iCountLayersNeedCs[kbBaseTemporalFlag]) {
            const int32_t kiActualSpatialIdx =
                iMapSpatialIdx[iSpatialIdx][kbBaseTemporalFlag];
            const int32_t kiLumaWidth =
                iLineSizeY[kiActualSpatialIdx][kbBaseTemporalFlag];
            const int32_t kiChromaWidth =
                iLineSizeUV[kiActualSpatialIdx][kbBaseTemporalFlag];

            WelsGetEncBlockStrideOffset((int32_t *)pBaseDec, kiLumaWidth,
                                        kiChromaWidth);

            pBaseDec += kiUnit1Size;
            ++iSpatialIdx;
        }
        ++iTemporalIdx;
    }

    iSpatialIdx = 0;
    while (iSpatialIdx < kiNumSpatialLayers) {
        const int32_t kiAllocMbSize =
            sMbSizeMap[iSpatialIdx].iSizeAllMbAlignCache;

        pMbIndexX[iSpatialIdx] = (int16_t *)pBaseMbX;
        pMbIndexY[iSpatialIdx] = (int16_t *)pBaseMbY;

        pBaseEnc += kiUnit1Size;
        pBaseMbX += kiAllocMbSize;
        pBaseMbY += kiAllocMbSize;
        ++iSpatialIdx;
    }

    while (iSpatialIdx < MAX_DEPENDENCY_LAYER) {
        pMbIndexX[iSpatialIdx] = NULL;
        pMbIndexY[iSpatialIdx] = NULL;

        ++iSpatialIdx;
    }

    iMaxMbWidth = sMbSizeMap[kiNumSpatialLayers - 1].iMbWidth;
    iMaxMbWidth = WELS_ALIGN(iMaxMbWidth, 4);
    iRowSize = iMaxMbWidth * sizeof(int16_t);
    printf("iMaxMbWidth = %d, iRowSize = %d\n", iMaxMbWidth, iRowSize);

    pTmpRow = (int16_t *)WelsMallocz(iRowSize, "pTmpRow");
    if (NULL == pTmpRow) {
        printf("pTmpRow is NULL\n");
        return 1;
    } else {
        printf("pTmpRow is %p\n", pTmpRow);
    }
    pRowX = pTmpRow;
    pRowY = pRowX;

    i = 0;
    p = pRowX;
    while (i < iMaxMbWidth) {
        *p = i;
        *(p + 1) = 1 + i;
        *(p + 2) = 2 + i;
        *(p + 3) = 3 + i;
        p += 4;
        i += 4;
    }

    iSpatialIdx = kiNumSpatialLayers;
    while (--iSpatialIdx >= 0) {
        int16_t *pMbX = pMbIndexX[iSpatialIdx];
        const int32_t kiMbWidth = sMbSizeMap[iSpatialIdx].iMbWidth;
        const int32_t kiMbHeight =
            sMbSizeMap[iSpatialIdx].iCountNum / kiMbWidth;
        const int32_t kiLineSize = kiMbWidth * sizeof(int16_t);
        i = 0;
        while (i < kiMbHeight) {
            memcpy(pMbX, pRowX, kiLineSize);
            pMbX += kiMbWidth;
            ++i;
        }
        i = 0;
    }

    memset(pRowY, 0, iRowSize);
    iMaxMbHeight = sMbSizeMap[kiNumSpatialLayers - 1].iCountNum /
                   sMbSizeMap[kiNumSpatialLayers - 1].iMbWidth;
    i = 0;
    for (;;) {
        ENFORCE_STACK_ALIGN_1D(int16_t, t, 4, 16);

        int32_t t32 = 0;
        int16_t j = 0;

        for (iSpatialIdx = kiNumSpatialLayers - 1; iSpatialIdx >= 0;
             --iSpatialIdx) {
            const int32_t kiMbWidth = sMbSizeMap[iSpatialIdx].iMbWidth;
            const int32_t kiMbHeight =
                sMbSizeMap[iSpatialIdx].iCountNum / kiMbWidth;
            const int32_t kiLineSize = kiMbWidth * sizeof(int16_t);
            int16_t *pMbY = pMbIndexY[iSpatialIdx] + i * kiMbWidth;

            if (i < kiMbHeight) {
                memcpy(pMbY, pRowY, kiLineSize);
            }
        }
        ++i;
        if (i >= iMaxMbHeight) {
            break;
        }

        t32 = i | (i << 16);
        ST32(t, t32);
        ST32(t + 2, t32);

        p = pRowY;
        while (j < iMaxMbWidth) {
            ST64(p, LD64(t));
            p += 4;
            j += 4;
        }
    }
    WelsFree(pTmpRow, "pTmpRow");
    pTmpRow = NULL;

    FILE *fpx = fopen("mb_index_x.txt", "w");
    for (int idx = 0; idx < sMbSizeMap[0].iCountNum; idx++) {
        fprintf(fpx, "pMbIndexX[0][%d] = %d\n", idx, pMbIndexX[0][idx]);
    }
    fclose(fpx);

    FILE *fpy = fopen("mb_index_y.txt", "w");
    for (int idx = 0; idx < sMbSizeMap[0].iCountNum; idx++) {
        fprintf(fpy, "pMbIndexY[0][%d] = %d\n", idx, pMbIndexY[0][idx]);
    }
    fclose(fpy);

    return 0;
}
