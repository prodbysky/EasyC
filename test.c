#include <stdio.h>
#define EZC_IMPL
#include "ez_cstr.h"

int main() {
    String str = EZC_String_make_default();

    EZC_String_c_str(&str, "Hi!");
    String clone = EZC_String_clone(&str);


    printf(EZC_STR_FMT"\n", EZC_STR_ARG(clone));
    return 0;
}
