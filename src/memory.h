#pragma once

#include <erl_nif.h>

#ifndef CALLOC_WRAP
#define CALLOC_WRAP(n,sz)\
    size_t total_size = n * sz;\
    void* ptr = enif_alloc(total_size);\
    if (ptr) {\
        memset(ptr, 0, total_size);\
    }\
    return ptr;
#endif

#ifndef RL_MALLOC
    #define RL_MALLOC(sz)       enif_alloc(sz)
#endif
#ifndef RL_CALLOC
    #define RL_CALLOC(n,sz)     CALLOC_WRAP(n, sz)
#endif
#ifndef RL_REALLOC
    #define RL_REALLOC(ptr,sz)  enif_realloc(ptr,sz)
#endif
#ifndef RL_FREE
    #define RL_FREE(ptr)        enif_free(ptr)
#endif