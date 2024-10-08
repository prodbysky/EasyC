#include <stdio.h>
#define EZC_STRING_IMPL
#include "ez_cstr.h"

#define EZC_ARENA_IMPL
#include "ez_carena.h"

#define EZC_PPM_IMPL
#include "ez_ppm.h"

int main() {
    // EZC_CSTR_TEST
    String str = EZC_String_make_default();
    EZC_String_c_str(&str, "Hi!");
    String clone = EZC_String_clone(&str);
    printf(EZC_STR_FMT"\n", EZC_STR_ARG(clone));

    // EZC_ARENA_TEST
    Arena arena = EZC_Arena_new(1024);
    int* test_int = EZC_Arena_alloc(&arena, sizeof(int));
    *test_int = 69420;
    printf("%d\n", *test_int);


    // EZC_PPM_TEST
    unsigned char pixels[]= {
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
    };
    const size_t w = 3;
    const size_t h = 3;
    FILE* file = fopen("test.ppm", "wb");
    EZC_PPM_write(file, pixels, w, h, EPF_RGB8);
    fclose(file);

    return 0;
}
