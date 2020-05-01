#ifndef BEGINNING_OPENGL_GLFWWINDOW_H
#define BEGINNING_OPENGL_GLFWWINDOW_H

#include <GLFW/glfw3.h>
#include "examplecallback.h"

class GlfwWindow {
public:
    static void attachExample(ExampleCallback *pExample);

    GlfwWindow();

    virtual ~GlfwWindow();

    bool create(int width, int height, int bpp, bool fullScreen);

    void destroy();

    void processEvents();

    bool isRunning();

    void swapBuffers();

    float getElapsedSeconds();

    void setWindowCaption(const char* title);

    bool keyPressed(int);

    bool keyHeldDown(int);
private:
    static ExampleCallback* example;

    static void glfwResizeCallback(GLFWwindow* window, int width, int height);

    static void glfwCloseCallback(GLFWwindow* window, int key, int scanCode, int action, int mode);

    GLFWwindow* window;

    unsigned int m_lastTime;
};

#endif //BEGINNING_OPENGL_GLFWWINDOW_H
