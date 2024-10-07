#ifndef EZC_H
#define EZC_H

#include <stdint.h>

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

#ifndef EZC_DEFAULT_INIT_CAP
  #define EZC_DEFAULT_INIT_CAP 16
#endif

#define EZC_STR_FMT "%.*s"
#define EZC_STR_ARG(str) (str).len, (str).str

#define EZC_STR_MALLOC_ERR 1

#include <stddef.h>

// Owned C String
typedef struct {
    char* str;
    char* head;
    size_t len;
    size_t cap;
    uint8_t create_error;
} EzCStr;

EzCStr EzCStr_make_string_default();
void EzCstr_pushc(EzCStr* str, char c);

#ifdef EZC_IMPL
EzCStr EzCStr_make_string_default() {
    char* str = (char*)EZC_MALLOC(sizeof(char) * EZC_DEFAULT_INIT_CAP);

    if (str == NULL) {
        return (EzCStr){
            .create_error = EZC_STR_MALLOC_ERR
        };
    }
    return (EzCStr){
        .str = str,
        .head = str,
        .len = 0,
        .cap = EZC_DEFAULT_INIT_CAP
    };
}

void EzCstr_pushc(EzCStr* str, char c) {
    if (str->len + 1 == str->cap) {
        str->str = (char*)realloc(str->str, str->cap * 1.5);
        str->head = str->str + str->len;
        str->cap *= 1.5;
    }

    *str->head = c;
    str->head++;
    str->len++;
}

#endif

#endif
