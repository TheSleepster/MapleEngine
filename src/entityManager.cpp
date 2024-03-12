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
    void createEntity(componentList components) {
        local_persist int id = 0;
        id = EntityCount++;


        components.transformComponents[id].entity_id = id;
        components.totalTransformComponents++;

        components.spriteComponents[id].entity_id = id;
        components.totalSpriteComponents++;

        components.healthComponents[id].entity_id = id;
        components.totalHealthComponents++;

        components.gravityComponents[id].entity_id = id;
        components.totalGravityComponents++;

        printf("An entity has been created!\n Index is: %i\n", id);
    } 

    void updateTransformComponents(transform *transform, componentList *components) {

        if(transform->position.y <= 0) {
            health *health;
            health = &components->healthComponents[transform->entity_id];

            health->currentHealth--;
        }
    }

    void updateSpriteComponents(sprite *sprite, componentList *components) {
         
    }

    void updateHealthComponents(health *health, componentList *components) {
        if(health->currentHealth <= 0 || health->isDead) {
            killEntity(components, health->entity_id);
        }
    }

    void killEntity(componentList *components, int index) {
        EntityCount--;

        componentList entityarray[EntityCount];
    }

}
