#ifndef EZC_FS_H
#define EZC_FS_H

#include <stddef.h>
#include <stdio.h>

typedef enum {
    FOM_Read = 0,
    FOM_Write = 1,
} FileOpenMode;

const static char* _Modes[] = {
    [FOM_Read] = "rb",
    [FOM_Write] = "wb",
};

typedef struct {
    FILE* c_file;
    size_t len;
} File;

File EZC_Fs_open_file(const char* file, FileOpenMode mode);
char EZC_Fs_read_char(File* file);

#ifdef EZC_FS_IMPL
File EZC_Fs_open_file(const char* file, FileOpenMode mode) {
    File f = {0};
    f.c_file = fopen(file, _Modes[mode]);

    if (f.c_file == NULL) return f;

    fseek(f.c_file, 0, SEEK_END);
    f.len = ftell(f.c_file);
    fseek(f.c_file, 0, SEEK_SET);
    return f;
}

char EZC_Fs_read_char(File* file) {
    char c;
    size_t bytes_read = fread(&c, sizeof(char), 1, file->c_file);
    if (bytes_read != 1) {
        return -1;
    }
    return c;
}

#endif

#endif
