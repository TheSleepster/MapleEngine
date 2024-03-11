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

    // NOTE: This is really ugly, it's the simplest solution though. If it's 
    // stupid but it works, it isn't stupid.

    struct Entity {
        const char* sprite;
        v2 postion, velocity;
        v2 gravity;

        int currenthealth;
        int maxHealth;
        bool isdead;
    };

    struct player {
        
    };

    // NOTE: ECS 
/*  
    struct tagData {
        enum entityType {
            player,
            enemy,
        };
    };
    
    struct transform {
        int entity_id;
        v2 position;
        v2 velocity;
    };
 
    struct sprite {
        int entity_id;
        SDL_Surface *surface;
        SDL_Texture *texture;
    };

    struct health {
        int entity_id;
        int currentHealth;
        int maxHealth;

        bool isDead;
    };

    struct gravity {
        int entity_id;
        v2 gravity;
    };

    struct componentList {
        tagData tag;

        sprite spriteComponents[100];
        transform transformComponents[100];
        health healthComponents[100];
        gravity gravityComponents[100];

        int totalSpriteComponents;
        int totalTransformComponents;
        int totalHealthComponents;
        int totalGravityComponents;
        
    };

    struct player {

    };

    struct enemy {

    };

    struct goomba : public enemy {

    };
*/
    
}
