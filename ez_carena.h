#ifndef EZC_ARENA_H
#define EZC_ARENA_H

#include <stddef.h>
#include <string.h>
#ifndef EZC_ASSERT
  #include <assert.h>
  #define EZC_ASSERT(cond, msg) assert((cond) && (msg))
#endif

#ifndef EZC_MALLOC
  #include <stdlib.h>
  #define EZC_MALLOC(size) malloc(size) 
#endif

#ifndef EZC_REALLOC
  #include <stdlib.h>
  #define EZC_REALLOC(size) realloc(size) 
#endif

typedef struct {
    char* data;
    size_t cap;
    size_t used;
} Arena;

Arena EZC_Arena_new(size_t capacity_bytes);
void* EZC_Arena_alloc(Arena* arena, size_t size_bytes);
void EZC_Arena_clear(Arena* arena);

#ifdef EZC_ARENA_IMPL

Arena EZC_Arena_new(size_t capacity_bytes) {
    char* data = (char*)EZC_MALLOC(capacity_bytes);
    if (data == NULL) {
        return (Arena) {.data = NULL, .cap = 0, .used = 0};
    }
    memset(data, 0, capacity_bytes);

    return (Arena){
        .data = data,
        .cap = capacity_bytes,
        .used = 0,
    };
}

void* EZC_Arena_alloc(Arena* arena, size_t size_bytes) {
    const size_t aligned = (size_bytes + 7) & ~ 7;
    EZC_ASSERT(arena != NULL, "Passed in NULL in `EZC_Arena_alloc`");
    EZC_ASSERT(arena->used + aligned < arena->cap, "EZC_Arena overflow!");
    void* obj = (void*)arena->data + arena->used;
    arena->used += aligned;
    return obj;
}
void EZC_Arena_clear(Arena* arena) {
    EZC_ASSERT(arena != NULL, "Passed in NULL in `EZC_Arena_alloc`");
    memset(arena->data, 0, arena->cap);
    arena->used = 0;
}

#endif

#endif
