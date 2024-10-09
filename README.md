# Easy C

This repo is for me since I end up writing these same tools over and over again
so I thought I should write them once and use these.
This is partly in inspiration of Tsoding's SV.h library.
If you decide to use this and find any issues PR's are welcome :)

This is a stb style repo, so to use just #include, and to include implementations
#define EZC_(header)_IMPL in one source file.

## Customization
To set the assert, malloc, realloc functions just define EZC_ASSERT, EZC_MALLOC, EZC_REALLOC
respectively, if not defined it will use libc functions

## Contents:
 - Arena:
    This is a simple bump allocator
 - CString:
    This is a utility for more ease of use with c strings
 - PPM:
    This is a utility for writing and in the future reading PPM files
 - Vectors:
    This is a utility for doing math with Vectors, not C++ vectors :)
 - And more to come!

