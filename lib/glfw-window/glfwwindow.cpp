#include "glfwwindow.h"

/**
 * Time since glfw start in ms.
 * @return
 */

ExampleCallback* GlfwWindow::example;

double GlfwWindow::getCurrentTime() {
    return glfwGetTime();
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
    double currentTime = glfwGetTime();
    double diff = currentTime - m_lastTime;
    m_lastTime = currentTime;

    return float(diff);
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

void GlfwWindow::setWindowCaption(const char* title) {
    glfwSetWindowTitle(window, title);
}

bool GlfwWindow::keyHeldDown(int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool GlfwWindow::mouseButtonPressed(int key) {
    return glfwGetMouseButton(window, key) == GLFW_PRESS;
}
