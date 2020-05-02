#ifndef WIN32_KEYBOARD_INTERFACE
#define WIN32_KEYBOARD_INTERFACE

#include <cstring>
#include "keyboardinterface.h"
#include <glfwwindow.h>

class GlfwKeyboardInterface : public KeyboardInterface
{
public:

    static GlfwKeyboardInterface* keyboardInterface;

    GlfwKeyboardInterface(GlfwWindow* glfwWindow): window(glfwWindow)
    {
        for (int i = 0; i < KC_MAX_KEYS; ++i) {
            m_keyState[i] = 0;
            m_lastKeyState[i] = 0;
        }
    }

    virtual bool isKeyPressed(BOGLGPKeyCode code)
    {
        return (!m_lastKeyState[code] && m_keyState[code]);
    }

    virtual bool isKeyHeldDown(BOGLGPKeyCode code)
    {
        return (m_lastKeyState[code] && m_keyState[code]);
    }

    virtual void handleKeyDown(BOGLGPKeyCode code)
    {
        m_keyState[code] = 1;
    }

    virtual void handleKeyUp(BOGLGPKeyCode code)
    {
        m_keyState[code] = 0;
    }

    virtual BOGLGPKeyCode translateKey(unsigned int code) //Translate a OS key to a KeyCode
    {
        switch(code)
        {
        case GLFW_KEY_UP:
            return KC_UP;
        case GLFW_KEY_DOWN:
            return KC_DOWN;
        case GLFW_KEY_LEFT:
            return KC_LEFT;
        case GLFW_KEY_RIGHT:
            return KC_RIGHT;
        case GLFW_KEY_W:
            return KC_w;
        case GLFW_KEY_S:
            return KC_s;
        case GLFW_KEY_A:
            return KC_a;
        case GLFW_KEY_D:
            return KC_d;
        case GLFW_KEY_SPACE:
            return KC_SPACE;
        default:
            return KC_INVALID;
        }
    }

    virtual void update()
    {
        memcpy(m_lastKeyState, m_keyState, sizeof(short) * KC_MAX_KEYS);
    }

    static void glfwKeyboardCallback(GLFWwindow* window, int key, int scanCode, int action, int mode) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GL_TRUE);
            return;
        }
        if (action == GLFW_PRESS) {
            GlfwKeyboardInterface::keyboardInterface->handleKeyDown(
                    GlfwKeyboardInterface::keyboardInterface->translateKey(key));
        }
        if (action == GLFW_RELEASE) {
            GlfwKeyboardInterface::keyboardInterface->handleKeyUp(
                    GlfwKeyboardInterface::keyboardInterface->translateKey(key));
        }
    }


private:
    GlfwWindow* window;
    short m_keyState[KC_MAX_KEYS];
    short m_lastKeyState[KC_MAX_KEYS];
};

#endif