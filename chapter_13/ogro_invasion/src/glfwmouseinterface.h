#ifndef WIN32_MOUSE_INTERFACE
#define WIN32_MOUSE_INTERFACE

#include <cassert>
#include <windows.h>

#include "mouseinterface.h"
#include "glfwwindow.h"
#include <GLFW/glfw3.h>

class WIN32MouseInterface : public MouseInterface
{
public:
    WIN32MouseInterface(GlfwWindow* glfwWindow): window(glfwWindow) {};

    virtual void getMousePos(int& x, int& y)
    {
        double xpos, ypos;
        glfwGetCursorPos(window->window, &xpos, &ypos);
        x = (int) xpos;
        y = (int) ypos;
    }

    virtual void setMousePos(int x, int y)
    {
        glfwSetCursorPos(window->window, x, y);
    }

    virtual void showCursor(bool val)
    {
        glfwSetInputMode(window->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    bool isButtonPressed(int button)
    {
        assert(button < 2);
        return (m_lastButtonState[button] == 0 && m_buttonState[button] == 1);
    }

    void update()
    {
        memcpy(m_lastButtonState, m_buttonState, sizeof(short) * 2);
        m_buttonState[0] = window->mouseButtonPressed(GLFW_MOUSE_BUTTON_1) ? 1 : 0;
        m_buttonState[1] = window->mouseButtonPressed(GLFW_MOUSE_BUTTON_2) ? 1 : 0;
    }

private:
    GlfwWindow* window;
    short m_buttonState[2];
    short m_lastButtonState[2];
};

#endif