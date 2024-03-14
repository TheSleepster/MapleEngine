#include "windowLayer.hpp"
#include "Precompiled.hpp"

// NOTE: This is called when the game starts.
//       Initializes GLFW and the OpenGL context.

void MapleCreateWindow() {
    MapleEngine Maple;

    if(!glfwInit()) {
        printf("Failed to Initialize GLFW\n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Maple.window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello Window!", NULL, NULL);

    if(!Maple.window) {
        printf("Window not found!\n");
        glfwTerminate();
        
    }
    
    glfwMakeContextCurrent(Maple.window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while(!glfwWindowShouldClose(Maple.window)) {

        //render
        
        glClear(GL_COLOR_BUFFER_BIT);

        //swap buffer
        
        glfwSwapBuffers(Maple.window);

        //poll Events

        glfwPollEvents();
    }
    glfwTerminate();

}
