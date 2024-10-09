#ifndef EZC_PPM_H
#define EZC_PPM_H

#include <stdint.h>
#include <stdio.h>
typedef enum {
    EPF_RGB8, // u8, u8, u8
    EPF_RGB_HEX, //0x00RRGGBB
    EPF_RGB16, // u16, u16, u16
    EPF_RGBF32 // float, float, float (0 >= n <= 1)
} EZC_PPM_Format;

int EZC_PPM_write(FILE* fd, void* pixels, size_t width, size_t height, EZC_PPM_Format format);

#ifdef EZC_PPM_IMPL

static void _EZC_PPM_write_header(FILE* fd, size_t w, size_t h, size_t max_val) {
    fprintf(fd, "P3\n");
    fprintf(fd, "%zu %zu\n", w, h);
    fprintf(fd, "%zu\n", max_val);
}
static int _EZC_clamp_int(int val, int low, int high) {
    if (val > high) return high;
    if (val < low) return low;
    return val;
}
// `pixels`: buffer of the specified format in `format`
int EZC_PPM_write(FILE* fd, void* pixels, size_t width, size_t height, EZC_PPM_Format format) {
    if (format == EPF_RGB8) {
        unsigned char* pix = (unsigned char*)pixels;
        _EZC_PPM_write_header(fd, width, height, UINT8_MAX);
        for (int i = 0; i < width * height * 3; i++) fprintf(fd, "%d ", pix[i]);
    } else if (format == EPF_RGB_HEX) {
        uint32_t* pix = (uint32_t*)pixels;
        _EZC_PPM_write_header(fd, width, height, UINT8_MAX);
        for (int i = 0; i < width * height; i++) {
            uint8_t r = (pix[i] >> 8 * 2) & 0xff;
            uint8_t g = (pix[i] >> 8 * 1) & 0xff;
            uint8_t b = pix[i] & 0xff;
            fprintf(fd, "%d %d %d \n", r, g, b);
        }
    } else if (format == EPF_RGB16) {
        uint16_t* pix = (uint16_t*)pixels;
        _EZC_PPM_write_header(fd, width, height, UINT16_MAX);
        for (int i = 0; i < width * height * 3; i++) fprintf(fd, "%d", pix[i]);
    } else if (format == EPF_RGBF32) {
        float* pix = (float*)pixels;
        _EZC_PPM_write_header(fd, width, height, UINT8_MAX);
        for (int i = 0; i < width * height * 3; i++) {
            uint8_t val = _EZC_clamp_int(pix[i] * 255, 0, 255);
            fprintf(fd, "%d", val);
        }
        
    }
    
    return 0;
}
#endif

#endif
