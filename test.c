#include <stdint.h>
#include <stdio.h>
#define EZC_STRING_IMPL
#include "ez_cstr.h"

#define EZC_ARENA_IMPL
#include "ez_carena.h"

#define EZC_PPM_IMPL
#include "ez_ppm.h"

#define EZC_PNG_IMPL
#include "ez_png.h"

int main() {
    // EZC_CSTR_TEST
    {
        String str = EZC_String_make_default();
        EZC_String_c_str(&str, "Hi!");
        String clone = EZC_String_clone(&str);
        printf(EZC_STR_FMT"\n", EZC_STR_ARG(clone));
    }


    char asd[16];

    // EZC_ARENA_TEST
    {
        Arena arena = EZC_Arena_new(1024);
        int* test_int = EZC_Arena_alloc(&arena, sizeof(int));
        *test_int = 69420;
        printf("%d\n", *test_int);
    }


    // EZC_PPM_TEST
    {
        uint32_t pixels[]= {
            0xffffff,
            0xffffff,
            0xffffff,
            0xffffff,
            0xffffff,
            0xffffff,
            0xffffff,
            0xffffff,
            0xffffff,
        };
        const size_t w = 3;
        const size_t h = 3;
        FILE* file = fopen("test.ppm", "wb");
        EZC_PPM_write(file, pixels, w, h, EPF_RGB_HEX);
        fclose(file);
    }

    // EZC_PNG_TEST
    {
        FILE* file = fopen("test.png", "rb");
        PngImage img = EZC_LoadPng(file);
    }


    return 0;
}
