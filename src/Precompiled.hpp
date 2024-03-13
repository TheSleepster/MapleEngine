#pragma once

#ifndef define

#include <cstddef>
#include <cstdint>
#include <cassert>
#include <glad/glad.h>
#include <SDL.h>
#include <struct.h>
#include <memory>
#include <time.h>
#include <cstddef>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <SDL3_image/SDL_image.h>
#include <flecs.h>
#include <cglm.h>
#include <struct.h>

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

// NOTE: These are globals used throughout the entire project
struct game {
    struct windowData {
        SDL_Window *window;

        SDL_GLContext OpenGLContext;
        
        bool closeRequest;
    };
};

global game::windowData wData;

#endif

// NOTE: Function declarations go here
void renderAwake(game::windowData *wData);
