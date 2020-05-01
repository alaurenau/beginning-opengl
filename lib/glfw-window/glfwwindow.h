#ifndef BEGINNING_OPENGL_GLFWWINDOW_H
#define BEGINNING_OPENGL_GLFWWINDOW_H

#include <GLFW/glfw3.h>
#include "examplecallback.h"

class GlfwWindow {
public:
    static void attachExample(ExampleCallback *pExample);

    static double getCurrentTime();

    GlfwWindow();

    virtual ~GlfwWindow();

    bool create(int width, int height, int bpp, bool fullScreen);

    void destroy();

    void processEvents();

    bool isRunning();

    void swapBuffers();

    float getElapsedSeconds();

    void setWindowCaption(const char* title);

    bool keyHeldDown(int);

    bool mouseButtonPressed(int);

    GLFWwindow* window;

    static ExampleCallback* example;

    static void glfwResizeCallback(GLFWwindow* window, int width, int height);

    static void glfwCloseCallback(GLFWwindow* window, int key, int scanCode, int action, int mode);

    double m_lastTime;
};

#endif //BEGINNING_OPENGL_GLFWWINDOW_H
