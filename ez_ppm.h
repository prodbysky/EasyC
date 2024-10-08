#ifndef EZC_PPM_H
#define EZC_PPM_H

#include <stdio.h>
typedef enum {
    EPF_RGB8
} EZC_PPM_Format;

int EZC_PPM_write(FILE* fd, void* pixels, size_t width, size_t height, EZC_PPM_Format format);

#ifdef EZC_PPM_IMPL
int EZC_PPM_write(FILE* fd, void* pixels, size_t width, size_t height, EZC_PPM_Format format) {
    if (format == EPF_RGB8) {
        unsigned char* pix = (char*)pixels;

        fprintf(fd, "P3\n");
        fprintf(fd, "%zu %zu\n", width, height);
        fprintf(fd, "255\n");
        int i = 0;
        while (i < width * height * 3) {
            fprintf(fd, "%d ", pix[i]);
            i++;
        }
    }
    return 0;
}
#endif

#endif
