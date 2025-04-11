#pragma once

#include <erl_nif.h>

void* calloc_wrap(int n, size_t sz) {
    size_t total_size = n * sz;
    void* ptr = enif_alloc(total_size);
    if (ptr) {
        memset(ptr, 0, total_size);
    }
    return ptr;
}

#ifndef RL_MALLOC
    #define RL_MALLOC(sz)       enif_alloc(sz)
#endif
#ifndef RL_CALLOC
    #define RL_CALLOC(n,sz)     calloc_wrap(n, sz)
#endif
#ifndef RL_REALLOC
    #define RL_REALLOC(ptr,sz)  enif_realloc(ptr,sz)
#endif
#ifndef RL_FREE
    #define RL_FREE(ptr)        enif_free(ptr)
#endif