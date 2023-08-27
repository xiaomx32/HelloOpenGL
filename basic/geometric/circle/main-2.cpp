#include "shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

float right = 0.5f;
float bottom = -0.5f;
float left = -0.5f;
float top = 0.5;
float quad[] = {
    right, bottom, 0.0f,// 1
    right, top   , 0.0f,
    left , top   , 0.0f,
    left , top   , 0.0f,// 2
    left , bottom, 0.0f,
    right, bottom, 0.0f,
};



int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* glfwWindow = glfwCreateWindow(800, 600, "Hello Cricle", nullptr, nullptr);
    glfwMakeContextCurrent(glfwWindow);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Shader shader("../shaders/shader-2.vert", "../shaders/shader-2.frag");
    Shader* myShader = &shader;

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(glfwWindow)) {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(myShader->programID);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(glfwWindow);
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();

    return 0;
}
