#ifndef WELS_ALIGN
#define WELS_ALIGN(x, n) (((x) + (n)-1) & ~((n)-1))
#endif

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef unsigned long long uintptr_t;

#define LD64(a) (*((uint64_t *)(a)))
#define ST16(a, b) *((uint16_t *)(a)) = (b)
#define ST32(a, b) *((uint32_t *)(a)) = (b)
#define ST64(a, b) *((uint64_t *)(a)) = (b)
#define ENFORCE_STACK_ALIGN_1D(_tp, _nm, _sz, _al)                             \
    _tp _nm##_tEmP[(_sz) + (_al)-1];                                           \
    _tp *_nm =                                                                 \
        _nm##_tEmP + ((_al)-1) -                                               \
        (((uintptr_t)(_nm##_tEmP + ((_al)-1)) & ((_al)-1)) / sizeof(_tp));

#define PADDING_LENGTH 32
#define MAX_DEPENDENCY_LAYER 4
