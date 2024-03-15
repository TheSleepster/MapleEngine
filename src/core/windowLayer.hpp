#pragma once

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

internal void OpenGLConfig();
void GetOpenGLVersionInfo();
void VertexSpecification();
void VertexSpecification();
void handleOpenGLPipeline();
unsigned int CompileShader(unsigned int type, const char *source); 
unsigned int createShaderProgram(const char *vertexShaderSource, const char *fragmentShaderSource); 
