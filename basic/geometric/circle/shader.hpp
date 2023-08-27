#ifndef SHADER_H_
#define SHADER_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

struct Shader {
    std::string vertexString {};
    std::string fragmentString {};
    const char* vertexSource = nullptr;
    const char* fragmentSource = nullptr;
    GLuint programID {0};

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
};
#endif// SHADER_H_
