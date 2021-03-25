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

#include <stdlib.h>
#include <string.h>
#include <types/string.h>

static void set_length(String *str, size_t len)
{
    if (!str->buffer)
    {

        str->buffer = malloc(len + 1);
        str->limit = len + 1;
    }
    else if (str->limit < len + 1)
    {

        str->buffer = realloc(str->buffer, len + 1);
        str->limit = len + 1;
    }

    if (str->length(str) > len)
    {
        memset(str->buffer + len, 0, 1);
    }
}

static void append(char *value, String *string)
{
    set_length(string, strlen(value) + string->size);

    strcat(string->buffer, value);
}

static void set(char *value, String *string)
{
    set_length(string, strlen(value));

    strcpy(string->buffer, value);
}

static size_t length(String *str)
{

    str->size = ((str->buffer == NULL) ? (0) : (strlen(str->buffer)));
    return str->size;
}

String String_new()
{
    String new_string;

    new_string.append = append;
    new_string.set = set;
    new_string.length = length;
    new_string.size = 0;
    
    return new_string;
}
