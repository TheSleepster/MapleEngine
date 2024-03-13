/*
    Maple is a primarily 2D game engine being developed by yours truly made in C/C++
*/
#ifndef define

#include "Precompiled.hpp"

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

int Maple_main(int argc, char *argv[]) {
    const int fps = 60;
    const int frameDelay = 1000 / fps;
    local_persist u32 startTime = SDL_GetTicks();
    int deltaTime = SDL_GetTicks() - startTime;
    
    renderAwake(&wData);

    // NOTE: GAMELOOP

    while(!wData.closeRequest) {
        glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

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

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(wData.window);

        deltaTime = SDL_GetTicks() - startTime;

        if(deltaTime < frameDelay) {
            SDL_Delay(frameDelay - deltaTime);
        } 
    }
    
    SDL_DestroyWindow(wData.window);
    SDL_GL_DeleteContext(wData.OpenGLContext);

    SDL_Quit();

    return 0;
}
