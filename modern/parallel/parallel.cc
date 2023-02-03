#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <thread>

using std::thread;

static void convertOnePiece(uint8_t *yuv_y, uint8_t *yuv_u, uint8_t *yuv_v,
                            uint32_t hStart, uint32_t width, uint32_t height) {
    int R, G, B = 0;
    int yIndex = hStart * width;
    int uIndex = hStart * width;
    int vIndex = hStart * width;
    const int Y = ((66 * R + 129 * G + 25 * B + 128) >> 8) + 16;
    const int U = ((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128;
    const int V = ((112 * R - 94 * G - 18 * B + 128) >> 8) + 128;

    auto start = std::chrono::high_resolution_clock::now();

    for (uint32_t i = hStart; i < hStart + height; ++i) {
        for (uint32_t j = 0; j < width; ++j) {
            std::cout << "yIndex=" << yIndex << ", uIndex=" << uIndex
                      << ", vIndex=" << vIndex << std::endl;
            yuv_y[yIndex++] =
                static_cast<uint8_t>((Y < 0) ? 0 : ((Y > 255) ? 255 : Y));
            if (i % 2 == 0 && j % 2 == 0) {
                yuv_u[uIndex++] =
                    static_cast<uint8_t>((U < 0) ? 0 : ((U > 255) ? 255 : U));
                yuv_v[vIndex++] =
                    static_cast<uint8_t>((V < 0) ? 0 : ((V > 255) ? 255 : V));
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "thread" << std::this_thread::get_id() << ", time taken: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                       start)
                     .count()
              << "ms";
}

static void convertRGBToI420Sequence(uint8_t *yuv_y, uint8_t *yuv_u,
                                     uint8_t *yuv_v, uint32_t width,
                                     uint32_t height, int threadNum) {
    int cnt = 1;
    int R, G, B = 0;
    int yIndex, uIndex, vIndex = 0;

    const int Y = ((66 * R + 129 * G + 25 * B + 128) >> 8) + 16;
    const int U = ((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128;
    const int V = ((112 * R - 94 * G - 18 * B + 128) >> 8) + 128;

    for (uint32_t i = 0; i < height; ++i) {
        for (uint32_t j = 0; j < width; ++j) {
            yuv_y[yIndex++] =
                static_cast<uint8_t>((Y < 0) ? 0 : ((Y > 255) ? 255 : Y));
            if (i % 2 == 0 && j % 2 == 0) {
                yuv_u[uIndex++] =
                    static_cast<uint8_t>((U < 0) ? 0 : ((U > 255) ? 255 : U));
                yuv_v[vIndex++] =
                    static_cast<uint8_t>((V < 0) ? 0 : ((V > 255) ? 255 : V));
            }
            if (yIndex == cnt * ((width * height) / threadNum)) {
                cnt += 1;
                std::cout << "yIndex = " << yIndex << ", uIndex = " << uIndex
                          << ", vIndex = " << vIndex << std::endl;
            }
        }
    }
}

// thread num = 4;
// width % 2 == 0;
// height % 2 == 0;
void convertRGBToI420(uint8_t *yuv_y, uint8_t *yuv_u, uint8_t *yuv_v,
                      uint32_t width, uint32_t height) {
    uint height_split = 4;
    auto splited_height = height / height_split;
    std::cout << "splited_height=" << splited_height << std::endl;
    thread t1(convertOnePiece, yuv_y, yuv_u, yuv_v, 0 * splited_height, width,
              splited_height);
    thread t2(convertOnePiece, yuv_y, yuv_u, yuv_v, 1 * splited_height, width,
              splited_height);
    thread t3(convertOnePiece, yuv_y, yuv_u, yuv_v, 2 * splited_height, width,
              splited_height);
    thread t4(convertOnePiece, yuv_y, yuv_u, yuv_v, 3 * splited_height, width,
              splited_height);
    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();
    if (t3.joinable())
        t3.join();
    if (t4.joinable())
        t4.join();
}

int main(int argc, char *argv[]) {
    const uint32_t width = 1920;
    const uint32_t height = 1920;
    uint8_t yuv_y[width * height] = {0};
    uint8_t yuv_u[width * height] = {0};
    uint8_t yuv_v[width * height] = {0};
    /* convertRGBToI420(yuv_y, yuv_u, yuv_v, width, height); */
    convertRGBToI420Sequence(yuv_y, yuv_u, yuv_v, width, height, 2);
    /* for (int i = 0; i < 1296 * 1440; ++i) { */
    /*     int value = static_cast<int>(yuv_u[i]); */
    /*     if (value != 0) { */
    /*         std::cout << "yuv_u[" << i << "]:" << value << " "; */
    /*     } */
    /* } */
    return 0;
}
