#include <stdio.h>
#define EZC_IMPL
#include "ez_cstr.h"

int main()
{
    EzCStr str = EzCStr_make_string_default();

    for (int i = 0; i < 16; i++) EzCstr_pushc(&str,'a');


    printf(EZC_STR_FMT, EZC_STR_ARG(str));


    return 0;
}
