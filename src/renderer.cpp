#include "renderer.hpp"

// NOTE: This is called when the game starts.
//       Initializes SDL and the OpenGL context.

void renderAwake(game::windowData *wData) {
    SDL_Init(SDL_INIT_VIDEO);
    
    wData->window = NULL;
    wData->renderer = NULL;
    wData->texture = NULL;

// NOTE: Configures OpenGL
    setAttributes();

    wData->window = 
        SDL_CreateWindow (
        "Maple", 
        WINDOW_WIDTH, 
        WINDOW_HEIGHT, 
        SDL_WINDOW_OPENGL);

    wData->renderer = 
        SDL_CreateRenderer (
        wData->window, 
        NULL, 
        SDL_RENDERER_ACCELERATED);

    wData->texture = 
        SDL_CreateTexture (
        wData->renderer, 
        SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_STREAMING, 
        NULL, 
        NULL);

    wData->OpenGLContext = SDL_GL_CreateContext(wData->window);

    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    checkError(wData);
}

void setAttributes() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
}

void checkError(game::windowData *wData) {
    if(!SDL_INIT_VIDEO) {
        fprintf(stderr, "Was not Able to Initialize SDL_INIT_VIDEO! %s\n", SDL_GetError());
        return;
    }

    if(!wData->window) {
        fprintf(stderr, "Was not Able to Create an OpenGL Context! %s\n", SDL_GetError());
        return;
    }

    wData->OpenGLContext = SDL_GL_CreateContext(wData->window);
    if(!wData->window) {
        fprintf(stderr, "Was not Able to Create the Window! %s\n", SDL_GetError());
        return;
    }

    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        fprintf(stderr, "Failed to inititialize GLAD! %s\n", SDL_GetError());
        return;
    }
}
