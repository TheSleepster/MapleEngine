#pragma once

#ifndef define

#include "Precompiled.hpp"
#include "vector.hpp"

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

    // NOTE: Everything to do with the Window 
    // and it's current state

    struct game {
        struct windowData {
            SDL_Window *window;
            SDL_Renderer *renderer;
            SDL_Texture *texture;
            bool closeRequest;
        };
    };
}

