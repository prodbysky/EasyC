#ifndef EZC_VECTORS_H
#define EZC_VECTORS_H

#include <stdint.h>
#include <math.h>
#ifndef EZC_ASSERT
  #include <assert.h>
  #define EZC_ASSERT(cond, msg) assert((cond) && (msg))
#endif


#ifndef EZC_VECTORS_FLOAT_TYPE
#define EZC_VECTORS_FLOAT_TYPE double
#endif

typedef union {
    struct {
        uint32_t x;
        uint32_t y;
    };
    struct {
        uint32_t u;
        uint32_t v;
    };
    struct {
        uint32_t w;
        uint32_t h;
    };
} Vec2u;

Vec2u EZC_Vec2u_Zero();
Vec2u EZC_Vec2u_One();
Vec2u EZC_Vec2u_Add(Vec2u a, Vec2u b);
Vec2u EZC_Vec2u_Sub(Vec2u a, Vec2u b);
Vec2u EZC_Vec2u_Mul(Vec2u a, Vec2u b);
Vec2u EZC_Vec2u_Div(Vec2u a, Vec2u b);
uint32_t EZC_Vec2u_Dot(Vec2u a, Vec2u b);
Vec2u EZC_Vec2u_Square(Vec2u a);
Vec2u EZC_Vec2u_Sqrt(Vec2u a);

#ifdef EZC_VECTORS_IMPL
Vec2u EZC_Vec2u_Zero() {
    return (Vec2u){0, 0};
}
Vec2u EZC_Vec2u_One() {
    return (Vec2u){1, 1};
}
Vec2u EZC_Vec2u_Add(Vec2u a, Vec2u b) {
    return (Vec2u){a.x + b.x, a.y + b.y};
}
Vec2u EZC_Vec2u_Sub(Vec2u a, Vec2u b) {
    return (Vec2u){a.x - b.x, a.y - b.y};
}
Vec2u EZC_Vec2u_Mul(Vec2u a, Vec2u b) {
    return (Vec2u){a.x * b.x, a.y * b.y};
}
Vec2u EZC_Vec2u_Div(Vec2u a, Vec2u b) {
    return (Vec2u){a.x / b.x, a.y / b.y};
}
uint32_t EZC_Vec2u_Dot(Vec2u a, Vec2u b) {
    return a.x * b.x + a.y * b.y;
}
Vec2u EZC_Vec2u_Square(Vec2u a) {
    return (Vec2u){a.x * a.x, a.y * a.y};
}

#endif
#endif
