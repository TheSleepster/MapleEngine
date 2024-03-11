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
//******************

// NOTE: Simple test to see if this file gets read (quite important)

//*******************

    void handleRendering(Maple::game::windowData *appWindow) {   
        renderPlayer(appWindow);
        renderEnemy(appWindow);
    }

    void renderPlayer(Maple::game::windowData *appWindow) {

    }

    void renderEnemy(Maple::game::windowData *appWindow) {

    }
}
