#ifndef BEGINNING_OPENGL_GLFWWINDOW_H
#define BEGINNING_OPENGL_GLFWWINDOW_H

#include <GLFW/glfw3.h>
#include "examplecallback.h"

class GlfwWindow {
public:
    GlfwWindow();

    virtual ~GlfwWindow();

    bool create(int width, int height, int bpp, bool fullScreen);

    void destroy();

    void processEvents();

    bool isRunning();

    void swapBuffers();

    float getElapsedSeconds();

    static void attachExample(ExampleCallback *pExample);

private:
    GLFWwindow* window;

    static ExampleCallback* example;

    unsigned int m_lastTime;

    static void glfwResizeCallback(GLFWwindow* window, int width, int height);

    static void glfwCloseCallback(GLFWwindow* window, int key, int scanCode, int action, int mode);

};

#endif //BEGINNING_OPENGL_GLFWWINDOW_H
