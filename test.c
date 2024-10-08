#include <stdio.h>
#define EZC_STRING_IMPL
#include "ez_cstr.h"

#define EZC_ARENA_IMPL
#include "ez_carena.h"

int main() {
    String str = EZC_String_make_default();
    EZC_String_c_str(&str, "Hi!");
    String clone = EZC_String_clone(&str);
    printf(EZC_STR_FMT"\n", EZC_STR_ARG(clone));

    Arena arena = EZC_Arena_new(1024);
    int* test_int = EZC_Arena_alloc(&arena, sizeof(int));
    *test_int = 69420;
    printf("%d\n", *test_int);

    return 0;
}
