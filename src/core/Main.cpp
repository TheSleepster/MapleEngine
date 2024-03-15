/*
    Maple is a primarily 2D game engine being developed by yours truly made in C/C++
*/
#include <glad/glad.h>
#ifndef define

#include "Precompiled.hpp"
#include "windowLayer.hpp"

#define Maple_main main 

#endif

int Maple_main(int argc, char *argv[]) {
    MapleCreateWindow();
    GetOpenGLVersionInfo();
    glViewport(0, 0, 1280, 720);

    VertexSpecification();
    handleOpenGLPipeline();

    while(!wData.closeRequest) {
        handleInput();
        handleEvents();

        Draw();

        SDL_GL_SwapWindow(wData.window);
    }
    return 0;
}

void handleEvents() {
    SDL_Event evnt;
    while(SDL_PollEvent(&evnt)) {
        switch(evnt.type) {
            case SDL_EVENT_QUIT:
                wData.closeRequest = true;
                break;
        }
    }
}

void handleInput() {
    const u8 *keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_ESCAPE]) {
        wData.closeRequest = true;
    } 
}

unsigned int VAO;
unsigned int VBO;
unsigned int shaderProgram;

char infoLog[512];
int success;

void MapleCreateWindow() {
    wData.closeRequest = false;
    wData.window = NULL;
    wData.OpenGLContext = NULL;

    OpenGLConfig();
    wData.window = 
            SDL_CreateWindow(
            "Maple", 
            WINDOW_WIDTH, 
            WINDOW_HEIGHT, 
            SDL_WINDOW_OPENGL);
    if(!wData.window) {
        printf("Failed to Initialize a window\n");
        exit(1);
    }

    wData.OpenGLContext = SDL_GL_CreateContext(wData.window);
    if(!wData.OpenGLContext) {
        printf("Failed to Initialize an OpenGL context\n");
        exit(1);
    }

    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        exit(1);
    }
}

internal void OpenGLConfig() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

void GetOpenGLVersionInfo() {
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Version: %s\n", glGetString(GL_VERSION));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Shading Language: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void handleOpenGLPipeline() {
    const char* vertexShaderSource = R"(
            #version 460 core
            layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec3 aColor;
        out vec3 vertexColor;
        void main() {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
            vertexColor = aColor;
        })";
    const char* fragmentShaderSource = R"(
    #version 460 core
    in vec3 vertexColor;
    out vec4 FragColor;
    void main() {
        FragColor = vec4(vertexColor, 1.0);
    }
)";

    shaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);
}

unsigned int 
createShaderProgram(const char *vertexShaderSource, const char *fragmentShaderSource) 
{
    unsigned int programObject = glCreateProgram();           
    unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);
    glLinkProgram(programObject);

    glGetProgramiv(programObject, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(programObject, 512, NULL, infoLog);
        printf("Failed to link with the programObject!\n");
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return(programObject);
}

unsigned int 
CompileShader(unsigned int type, const char *source) 
{
    unsigned int shaderObject;

    if(type == GL_FRAGMENT_SHADER) {
        shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    }

    else if(type == GL_VERTEX_SHADER) {
        shaderObject = glCreateShader(GL_VERTEX_SHADER);
    }

    glShaderSource(shaderObject, 1, &source, nullptr);
    glCompileShader(shaderObject);

    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shaderObject, 512, NULL, infoLog);
        printf("Failed to create a shader Object!\n");
    }

    return(shaderObject);
}

void VertexSpecification() {
// NOTE: Vertices are stored.
    
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // Vertex 1 position
         1.0f,  0.0f, 0.0f, // Vertex 1 color (red)
         0.5f, -0.5f, 0.0f, // Vertex 2 position
         0.0f,  1.0f, 0.0f, // Vertex 2 color (green)
         0.0f,  0.5f, 0.0f, // Vertex 3 position
         0.0f,  0.0f, 1.0f  // Vertex 3 color (blue)
    };

// NOTE: This Generates a Vertex Array Object (VAO) for our use.
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

// NOTE: This creates a Vertex BUFFER Object from our VAO for our use.
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

// NOTE: Populates the VBO with data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

// NOTE: Tells OpenGL what attributes are active (Check the docs)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

// NOTE: CLEANUP
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glClearColor(0.0f, 0.3f, 1.0f, 0.1f);
    glUseProgram(shaderProgram); // Use the shader program
    glBindVertexArray(VAO); // Bind the VAO
    glDrawArrays(GL_TRIANGLES, 0, 3); // Draw the triangle
}
