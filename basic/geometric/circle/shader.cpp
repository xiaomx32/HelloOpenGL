#include "shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


Shader::Shader(const char*vertexPath, const char* fragmentPath) {
    // 从文件路径中获取顶点/片段着色器
    std::ifstream vertexFile;
    std::ifstream fragmentFile;
    std::stringstream vertexSStream;
    std::stringstream fragmentSStream;

    // 保证 ifstream 对象可以抛出异常
    //vertexFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);
    //fragmentFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);

    try {
        vertexFile.open(vertexPath);
        fragmentFile.open(fragmentPath);

        //if (!vertexFile.is_open() || !fragmentFile.is_open()) {
        //        throw std::exception("Open file error.");
        //}

        vertexSStream << vertexFile.rdbuf();// 读取文件的缓冲内容到数据流中
        fragmentSStream << fragmentFile.rdbuf();

        vertexString = vertexSStream.str();// 转换数据流到 string
        fragmentString = fragmentSStream.str();

        // 把着色器代码转换成 char
        vertexSource = vertexString.c_str();
        fragmentSource = fragmentString.c_str();

        // 编译着色器
        unsigned int vertex, fragment;

        vertex = glCreateShader(GL_VERTEX_SHADER);// 顶点着色器
        glShaderSource(vertex, 1, &vertexSource, nullptr);
        glCompileShader(vertex);

        fragment = glCreateShader(GL_FRAGMENT_SHADER);// 片段着色器
        glShaderSource(fragment, 1, &fragmentSource, nullptr);
        glCompileShader(fragment);

        // 着色器程序
        programID = glCreateProgram();
        glAttachShader(programID, vertex);
        glAttachShader(programID, fragment);
        glLinkProgram(programID);

        glDeleteShader(vertex);// 删除着色器，它们已经链接到我们的程序中了，已经不再需要了
        glDeleteShader(fragment);
    } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
    }
}

Shader::~Shader() {}
