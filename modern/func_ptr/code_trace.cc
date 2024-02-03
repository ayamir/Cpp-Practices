#include "code_trace.h"
#include <cstdio>

static void fileTrace(void *ctx, int level, const char *string) {
    FILE *fp;
    fp = fopen("log.txt", "a+");
    fprintf(fp, "%s\n", string);
    fclose(fp);
}

void CodeTrace::SetOption(void *pFunc) {
    fprintf(stdout, "pFunc address = %p\n", pFunc);
    // LogTraceFunc callback = *((LogTraceFunc *)pFunc);
    LogTraceFunc callback = (LogTraceFunc)pFunc;
    m_fpTrace = callback;
    fprintf(stdout, "callback set, address = %p\n", callback);
}

void CodeTrace::Log(void *ctx, int level, const char *string) {
    if (m_fpTrace != nullptr) {
        fprintf(stdout, "log with m_fpTrace, address = %p\n", m_fpTrace);
        m_fpTrace(ctx, level, string);
    }
}
