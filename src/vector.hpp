#pragma once

#ifndef define

#include "Precompiled.hpp"
#include "componentData.hpp"

#define Maple_main main 
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720 
#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 240

#define global static
#define local_persist static
#define internal static

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef float real16;
typedef double real32;

#endif

namespace Maple {

    union v2{
        struct {
            real32 x, y;
        };
        real32 E[2];
    };

    inline v2 
    V2 (real32 X, real32 Y) {
        v2 result;

        result.x = X;
        result.y = Y;

        return(result);
    }

    inline v2 
    operator+(v2 A, v2 B) {
        v2 result;

        result.x = A.x + B.x;
        result.y = A.y + B.y;

        return(result);
    }

    inline v2 
    operator-(v2 A, v2 B) {
        v2 result;

        result.x = A.x - B.x;
        result.x = A.y - B.y; 

        return(result);
    }

    inline v2 
    operator-(v2 A) {
        v2 result;

        result.x = -A.x;
        result.y = -A.y;

        return result;
    }

    inline v2 
    operator*(v2 A, real32 B) {
        v2 result;

         result.x = A.x * B;
         result.y = A.y * B;

        return(result);
    }

    inline v2 
    operator/(v2 A, real32 B) {
        v2 result;

        result.x = A.x / B;
        result.y = A.y / B;

        return(result);
    }

    inline v2 & 
    operator*=(v2 &A, real32 B) {
         A *= B;  

        return(A);
    }

    inline v2 & 
    operator/=(v2 &A, real32 B) {
         A /= B;  

        return(A);
    }

    inline v2 dist(v2 A, v2 B) {
        v2 result;
        
        result.x = sqrt((A.x * A.x) + (B.x * B.x)); 
        result.y = sqrt((A.y * A.y) + (B.y * B.y));

        return result;
    }

    inline v2 normalize() {
        v2 result;
        return result;
    }

    inline v2 lerp() {
        v2 result;
        return result;
    }

    inline v2 slerp() {
        v2 result;
        return result;
    }

    inline v2 clamp() {
        v2 result;
        return result;
    }
}
