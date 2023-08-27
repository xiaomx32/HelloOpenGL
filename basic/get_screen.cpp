#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    int monitorCount;
    GLFWmonitor** pMonitor = glfwGetMonitors(&monitorCount);
    std::cout << "screen count is " << monitorCount << std::endl;
    for (std::size_t i {0}; i < monitorCount; ++i) {
        int resolution_x, resolution_y;
        const GLFWvidmode* mode = glfwGetVideoMode(pMonitor[i]);
        std::cout << "resolution is width = " << mode->width
                  << ", height = " << mode->height
                  << std::endl;
    }

    glfwTerminate();
    return 0;
}
