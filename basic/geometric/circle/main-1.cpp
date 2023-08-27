#include "shader.hpp"

#include <iostream>
#include <vector>
#include <numbers>
#include <cmath>

constexpr float NUMBER_OF_VERTICES = 1000.0f;
constexpr float PI = std::numbers::pi_v<float>;



int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* glfwWindow = glfwCreateWindow(800, 800, "approximate circle with vertices", nullptr, nullptr);
    glfwMakeContextCurrent(glfwWindow);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    float radius = 0.5f;
    std::vector<GLfloat> vertices;
    for (float i {0}; i < 2 * PI; i += (2 * PI) / NUMBER_OF_VERTICES) {
        vertices.push_back(std::cos(i) * radius);
        vertices.push_back(std::sin(i) * radius);
        vertices.push_back(0.0f);
    }

    Shader shader("../shaders/shader-1.vert", "../shaders/shader-1.frag");
    Shader* myShader = &shader;

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(glfwWindow)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(myShader->programID);
        glBindVertexArray(VAO);
        //glDrawArrays(GL_LINE_LOOP, 0, NUMBER_OF_VERTICES);
        glDrawArrays(GL_TRIANGLE_FAN, 0, NUMBER_OF_VERTICES);

        glfwSwapBuffers(glfwWindow);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();

    return 0;
}
