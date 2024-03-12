#ifndef define

#include "Precompiled.hpp"
#include "componentData.hpp"

#endif

namespace Maple {

    // NOTE: Information inside of this function will only run once 
    // on application startup

    void awake() {

    }
    
    // NOTE: Information in here will update on a per-frame 
    // basis.

    void update(Maple::game::windowData *appWindow) {
        handleRendering(appWindow);

    }
}

