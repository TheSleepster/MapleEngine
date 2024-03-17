/*
    Maple is a primarily 2D game engine being developed by yours truly made in C/C++
*/
#ifndef define

#include "Precompiled.hpp"
#include "windowLayer.hpp"

#define Maple_main main 

#endif

int Maple_main(int argc, char *argv[]) {
    GLenum error;

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

        if(error != 0) {
            printf("Error: %i\n", error);
            error = 0;
        }
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

global unsigned int VAO;
global unsigned int VBO;
global unsigned int IBO;
global unsigned int shaderProgram;
global char* shaderSource;

global char infoLog[512];
global int success;

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
    printf("Shading Language: %s\n\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void handleOpenGLPipeline() {
    const char* relativeVertexFilePath = "../src/.shader/vertexShader.glsl";
    const char* relativeFragmentFilePath = "../src/.shader/fragmentShader.glsl";

    const char* vertexShaderSource = getShaderFromFile(relativeVertexFilePath);
    const char* fragmentShaderSource = getShaderFromFile(relativeFragmentFilePath);

    shaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);
    free((void *)shaderSource);
}

const char *getShaderFromFile(const char *filepath) {
    FILE* file;
    long size;

    fopen_s(&file, filepath, "rb");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filepath);
        return 0;
    }

    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    shaderSource = (char*)malloc(size + 1);
    if (shaderSource == NULL) {
        printf("Failed to allocate memory for shader source\n");
        fclose(file);
        return NULL;
    }

    fread(shaderSource, 1, size, file);
    shaderSource[size] = '\0';

    fclose(file);

    return(shaderSource);
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
        printf("Info log: %s", infoLog);
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
         0.5f,  0.5f, 0.0f, // Vertex 3 position
         0.0f,  0.0f, 1.0f,  // Vertex 3 color (blue)
        
         0.5f,  0.5f, 0.0f, // Vertex 4 position
         0.0f,  0.0f, 1.0f, // Vertex 4 color (red)
        -0.5f,  0.5f, 0.0f, // Vertex 5 position
         0.0f,  1.0f, 0.0f, // Vertex 5 color (green)
        -0.5f, -0.5f, 0.0f, // Vertex 6 position
         1.0f,  0.0f, 0.0f  // Vertex 6 color (blue)
    };

    unsigned int indices[] {
        0, 1, 2,
        2, 1, 0,
    };

// NOTE: This Generates a Vertex Array Object (VAO) for our use.
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

// NOTE: This creates a Vertex BUFFER Object from our VAO for our use.
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

// NOTE: Populates the VBO with data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


// WARNING: INDEX BUFFER
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
    glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
 
    glUseProgram(shaderProgram); // Use the shader program
    glBindVertexArray(VAO); // Bind the VAO

    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glDrawArrays(GL_TRIANGLES, 0, 6); // Draw the triangle

    glUseProgram(0);
}
