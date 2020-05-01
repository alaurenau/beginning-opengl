#include "glfwwindow.h"

/**
 * Time since glfw start in ms.
 * @return
 */

ExampleCallback* GlfwWindow::example;

unsigned int getTickCount() {
    unsigned int ms = (unsigned int)(glfwGetTime() * 1000);
    return ms;
}

GlfwWindow::GlfwWindow() :
        window(NULL),
        m_lastTime(0) {
}

GlfwWindow::~GlfwWindow() {
}

bool GlfwWindow::create(int width, int height, int bpp, bool fullScreen) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWmonitor* glfwMonitor = fullScreen ? glfwGetPrimaryMonitor() : NULL;

    window = glfwCreateWindow(width, height, "GlfwWindow", glfwMonitor, NULL);
    glfwSetWindowSizeCallback(window, GlfwWindow::glfwResizeCallback);
    glfwSetKeyCallback(window, GlfwWindow::glfwCloseCallback);

    glfwMakeContextCurrent(window);

    // initial resize event
    glfwResizeCallback(NULL, width, height);
    return window != NULL;
}

void GlfwWindow::destroy() {
    glfwTerminate();
};

void GlfwWindow::processEvents() {
    glfwPollEvents();
};

bool GlfwWindow::isRunning() {
    return !glfwWindowShouldClose(window);
};

void GlfwWindow::swapBuffers() {
    glfwSwapBuffers(window);
}

float GlfwWindow::getElapsedSeconds() {
    unsigned int currentTime = getTickCount();
    unsigned int diff = currentTime - m_lastTime;
    m_lastTime = currentTime;
    return float(diff) / 1000.0f;
};

void GlfwWindow::glfwCloseCallback(GLFWwindow* window, int key, int scanCode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void GlfwWindow::glfwResizeCallback(GLFWwindow* window, int width, int height) {
    GlfwWindow::example->onResize(width, height);
}

void GlfwWindow::attachExample(ExampleCallback *pExample) {
    GlfwWindow::example = pExample;
}
