#include "code_api.h"
#include <stdio.h>

class CodeTrace {
  public:
    CodeTrace() { printf("CodeTrace()\n"); }
    ~CodeTrace() { printf("~CodeTrace()\n"); }
    void SetOption(void *);
    void Log(void *ctx, int level, const char *string);

  private:
    LogTraceFunc m_fpTrace = nullptr;
};
