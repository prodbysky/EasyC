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

typedef union {
    struct {
        uint32_t x;
        uint32_t y;
        uint32_t z;
    };
    struct {
        uint32_t r;
        uint32_t g;
        uint32_t b;
    };
    struct {
        uint32_t w;
        uint32_t h;
        uint32_t t;
    };
} Vec3u;

Vec2u EZC_Vec2u_Zero();
Vec2u EZC_Vec2u_One();
Vec2u EZC_Vec2u_Add(Vec2u a, Vec2u b);
Vec2u EZC_Vec2u_Sub(Vec2u a, Vec2u b);
Vec2u EZC_Vec2u_Mul(Vec2u a, Vec2u b);
Vec2u EZC_Vec2u_Scale(Vec2u a, EZC_VECTORS_FLOAT_TYPE scalar);
Vec2u EZC_Vec2u_Div(Vec2u a, Vec2u b);
uint32_t EZC_Vec2u_Dot(Vec2u a, Vec2u b);
Vec2u EZC_Vec2u_Square(Vec2u a);

Vec3u EZC_Vec3u_Zero();
Vec3u EZC_Vec3u_One();
Vec3u EZC_Vec3u_Add(Vec3u a, Vec3u b);
Vec3u EZC_Vec3u_Sub(Vec3u a, Vec3u b);
Vec3u EZC_Vec3u_Mul(Vec3u a, Vec3u b);
Vec3u EZC_Vec3u_Scale(Vec3u a, EZC_VECTORS_FLOAT_TYPE scalar);
Vec3u EZC_Vec3u_Div(Vec3u a, Vec3u b);
uint32_t EZC_Vec3u_Dot(Vec3u a, Vec3u b);
Vec3u EZC_Vec3u_Square(Vec3u a);

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

Vec2u EZC_Vec2u_Scale(Vec2u a, EZC_VECTORS_FLOAT_TYPE scalar) {
    return EZC_Vec2u_Mul(a, (Vec2u){.x = scalar, .y = scalar});
}
Vec2u EZC_Vec2u_Div(Vec2u a, Vec2u b) {
    return (Vec2u){a.x / b.x, a.y / b.y};
}
uint32_t EZC_Vec2u_Dot(Vec2u a, Vec2u b) {
    return a.x * b.x + a.y * b.y;
}
Vec2u EZC_Vec2u_Square(Vec2u a) {
    return EZC_Vec2u_Mul(a, a);
}

Vec3u EZC_Vec3u_Zero() {
    return (Vec3u){0, 0, 0};

}
Vec3u EZC_Vec3u_One() {
    return (Vec3u){1, 1, 1};
}
Vec3u EZC_Vec3u_Add(Vec3u a, Vec3u b) {
    return (Vec3u){a.x + b.x, a.y + b.y, a.z, + b.z};

}
Vec3u EZC_Vec3u_Sub(Vec3u a, Vec3u b) {
    return (Vec3u){a.x - b.x, a.y - b.y, a.z, - b.z};
}

Vec3u EZC_Vec3u_Mul(Vec3u a, Vec3u b) {
    return (Vec3u){a.x * b.x, a.y * b.y, a.z, * b.z};
}
Vec3u EZC_Vec3u_Scale(Vec3u a, EZC_VECTORS_FLOAT_TYPE scalar) {
    return EZC_Vec3u_Mul(a, (Vec3u){.x = scalar, .y = scalar, .z = scalar});
}
Vec3u EZC_Vec3u_Div(Vec3u a, Vec3u b) {
    return (Vec3u){a.x / b.x, a.y / b.y, a.z, / b.z};
}
uint32_t EZC_Vec3u_Dot(Vec3u a, Vec3u b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vec3u EZC_Vec3u_Square(Vec3u a) {
    return EZC_Vec3u_Mul(a, a);
}

#endif
#endif
