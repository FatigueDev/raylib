#pragma once

#include <erl_nif.h>

#ifndef RL_MALLOC
    void *nif_alloc(size_t size)
    {
        return enif_alloc(size);
    }
    #define RL_MALLOC(sz) nif_alloc(sz)
#endif

#ifndef RL_CALLOC
    void *nif_calloc(size_t num, size_t size)
    {
        size_t total_size = num * size;
        void *ptr = enif_alloc(total_size);
        if (ptr)
        {
            memset(ptr, 0, total_size);
        }
        return ptr;
    }
    #define RL_CALLOC(n, sz) nif_calloc(n, sz)
#endif

#ifndef RL_REALLOC
    void *nif_realloc(void *ptr, size_t new_size)
    {
        return enif_realloc(ptr, new_size);
    }
    #define RL_REALLOC(ptr, sz) nif_realloc(ptr, sz)
#endif

#ifndef RL_FREE
    void nif_free(void *ptr)
    {
        enif_free(ptr);
    }
    #define RL_FREE(ptr) nif_free(ptr)
#endif