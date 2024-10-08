#ifndef EZC_H
#define EZC_H

#include <stdio.h>
#include <string.h>
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
#define EZC_STR_ARG(a) (a).len, (a).str


#include <stddef.h>

typedef enum {
    SCE_MALLOC,
} EZC_StringCreateError;

// Owned C String (String in Rust)
typedef struct {
    char* str;
    char* head;
    size_t len;
    size_t cap;
    EZC_StringCreateError create_error;
} String;

// Non owning string ref (&str in Rust)
typedef struct {
    const char* str;
    size_t len;
} StringView;

String EZC_String_make_default();
String EZC_String_make_with_cap(size_t cap);
String EZC_String_clone(String* str);
void EZC_String_push_c(String* str, char c);
char EZC_String_pop(String* str);
void EZC_String_c_str(String *str, char* s);
StringView EZC_StringView_from_String(String str);

#ifdef EZC_IMPL

String EZC_String_make_with_cap(size_t cap) {
    char* str = (char*)EZC_MALLOC(sizeof(char) * cap);

    if (str == NULL) {
        return (String){
            .create_error = SCE_MALLOC
        };
    }
    return (String){
        .str = str,
        .head = str,
        .len = 0,
        .cap = cap
    };

}

String EZC_String_make_default() {
    return EZC_String_make_with_cap(EZC_DEFAULT_INIT_CAP);
}

String EZC_String_clone(String* str) {
    String result = EZC_String_make_with_cap(str->cap);
    memcpy(result.str, str->str, str->cap);
    result.len = str->len;
    return result;
}

void EZC_String_push_c(String* str, char c) {
    if (str->len + 1 == str->cap) {
        str->str = (char*)realloc(str->str, str->cap * 1.5);
        str->head = str->str + str->len;
        str->cap *= 1.5;
    }

    *str->head = c;
    str->head++;
    str->len++;
}

char EZC_String_pop(String* str) {
    char c = *str->head;
    str->head--;
    str->len--;
    return c;
}

void EZC_String_c_str(String *str, char* s) {
    while (*s != 0) {
        EZC_String_push_c(str, *s);
        s++;
    }
}

StringView EZC_StringView_from_String(String str) {
    return (StringView){
        .str = str.str,
        .len = str.len
    };        
}

#endif

#endif
