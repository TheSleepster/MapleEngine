/*
    Maple is a primarily 2D game engine being developed by yours truly made in C/C++
*/

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
typedef float f8;
typedef double f16;

#endif

// NOTE: Establishes the window and it's necessary components

int Maple_main(int argc, char *argv[]) {

    const int fps = 60;
    const int frameDelay = 1000 / fps;
    local_persist u32 startTime = SDL_GetTicks();
    int deltaTime = SDL_GetTicks() - startTime;

    Maple::awake();

// NOTE: Initialize SDL 

    SDL_Init(SDL_INIT_VIDEO);
    assert(!SDL_Init(SDL_INIT_VIDEO));
    
    SDL_Init(SDL_INIT_AUDIO);
    assert(!SDL_Init(SDL_INIT_AUDIO));

    SDL_Init(SDL_INIT_CAMERA);
    assert(!SDL_Init(SDL_INIT_CAMERA));

    wData.window = NULL;
    wData.renderer = NULL;
    wData.texture = NULL;

    // TODO: Assess whether OpenGL is the right option for this

    wData.window = 
        SDL_CreateWindow (
        "Maple", 
        WINDOW_WIDTH, 
        WINDOW_HEIGHT, 
        SDL_WINDOW_OPENGL);

    wData.renderer = 
        SDL_CreateRenderer (
        wData.window, 
        NULL, 
        SDL_RENDERER_ACCELERATED);

    wData.texture = 
        SDL_CreateTexture (
        wData.renderer, 
        SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_STREAMING, 
        NULL, 
        NULL);

    // NOTE: GAMELOOP

    while(!wData.closeRequest) {
        startTime = SDL_GetTicks();

        SDL_Event evnt;
        while(SDL_PollEvent(&evnt)) {
            switch(evnt.type) {
                case SDL_EVENT_QUIT:
                    wData.closeRequest = true;
            }
        }

        const u8 *keystate = SDL_GetKeyboardState(NULL);
        if(keystate[SDL_SCANCODE_ESCAPE]) {
            wData.closeRequest = true;
        } 

        SDL_SetRenderDrawColor(wData.renderer, 0, 0, 0, 255);
        SDL_RenderClear(wData.renderer);
   
        Maple::update(&wData);
        
        SDL_RenderPresent(wData.renderer);
        
        deltaTime = SDL_GetTicks() - startTime;

        if(deltaTime < frameDelay) {
            SDL_Delay(frameDelay - deltaTime);
        } 
    }
    return 0;
}
