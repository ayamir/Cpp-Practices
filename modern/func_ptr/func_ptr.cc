#include "code_trace.h"
#include <cstdio>

void RTCTrackCallback(void *ctx, int iLevel, const char *string) {
    fprintf(stdout, "%s\n", string);
}

int main(int argc, char *argv[]) {
    CodeTrace codeTrace;
    fprintf(stdout, "RTCTrackCallback address = %p\n", RTCTrackCallback);
    codeTrace.SetOption((void *)(&RTCTrackCallback));
    codeTrace.Log(nullptr, 1, "Hello, World!");
    return 0;
}
