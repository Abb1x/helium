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
#include "vector.h"

static void push_back(void *data, Vector *self)
{
    if (self->size == self->limit)
    {
        self->limit = self->limit * 2;
        self->data = realloc(self->data, sizeof(void *) * self->limit);
    }

    self->data[self->size] = data;
    self->size++;
}

static void remove(int index, Vector *self)
{
    if (index > -1 && index < self->size)
    {
        self->data[index] = self->data[self->size - 1];
        self->data[self->size - 1] = NULL;
        self->size--;
    }
}

static void pop_back(Vector *self)
{
    remove(self->size - 1);
}

Vector Vector_new()
{
    Vector new_vector;

    new_vector.limit = 4;

    new_vector.data = malloc(sizeof(void *) * new_vector.limit);

    new_vector.size = 0;

    new_vector.push_back = push_back;
    new_vector.pop_back = pop_back;
    new_vector.remove = remove;

    return new_vector;
}
