/*
* BSD 2-Clause License
*
* Copyright (c) 2021, Abb1x
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "log.h"
#include <stdlib.h>
#include <string.h>

void helium_log(helium_logging_level status, char *file, int line, char *format, ...)
{
    char *string;
    va_list vl;
    va_start(vl, format);

    switch (status)
    {
    case INFO:
        string = "\033[1;34mINFO \033[0m";
        break;
    case TEST:
        string = "\033[1;32mTEST \033[0m";
        break;
    case DEBUG:
        string = "\033[1;36mDEBUG \033[0m";
        break;
    case WARNING:
        string = "\033[1;33mWARNING \033[0m";
        break;
    case ERROR:
        string = "\033[1;31mERROR \033[0m";
        break;
    default:
        string = " string";
    };

    char *target = malloc(strlen(format) + 128);

    vsprintf(target, format, vl);

    printf("%s\033[1;30m%s:%d\033[0m %s\n", string, file, line, target);

    va_end(vl);
}
