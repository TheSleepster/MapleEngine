#pragma once

#ifndef define

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cstddef>
#include <string>
#include <memory>
#include <time.h>
#include <math.h>
#include <cmath>
#include <cassert>
#include <string>
#include <fstream>
#include <cstdint>
#include <glad/glad.h>
#include <flecs.h>
#include <SDL.h>

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
const char *getShaderFromFile(const char *filepath);
void MapleCreateWindow();
void handleEvents();
void handleInput();
void preDraw();
void Draw();
