#pragma once

#include <GLFW/glfw3.h>
#include "examplecallback.h"
#include <glfwwindow.h>
#include "../boglgpwindow.h"
#include "../glfwkeyboardinterface.h"
#include "../glfwmouseinterface.h"

class GlfwWindowAdapter: public BOGLGPWindow {
public:
    GlfwWindowAdapter(GlfwWindow* window): m_window(window), m_keyboard(window), m_mouse(window) {
        WIN32KeyboardInterface::keyboardInterface = &m_keyboard;
    };

    virtual bool create(int width, int height, int bpp, bool fullscreen, const char* title);
    virtual void destroy();
    virtual void processEvents();
    virtual void attachExample(Example* example);
    virtual bool isRunning();
    virtual void swapBuffers();
    virtual float getElapsedSeconds();
    KeyboardInterface* getKeyboard() { return &m_keyboard; }
    MouseInterface* getMouse() { return &m_mouse; }

    GlfwWindow* m_window;
    WIN32KeyboardInterface m_keyboard;
    WIN32MouseInterface m_mouse;
};
