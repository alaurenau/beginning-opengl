#include "glfwwindowwrapper.h"

GlfwKeyboardInterface* GlfwKeyboardInterface::keyboardInterface;

bool GlfwWindowAdapter::create(int width, int height, int bpp, bool fullscreen, const char* title) {
    bool result = m_window->create(width, height, bpp, fullscreen, title);
    glfwSetKeyCallback(m_window->window, GlfwKeyboardInterface::glfwKeyboardCallback);
    return result;
}

void GlfwWindowAdapter::destroy() {
    m_window->destroy();
}

void GlfwWindowAdapter::processEvents() {
    m_keyboard.update();
    m_mouse.update();
    return m_window->processEvents();
}

void GlfwWindowAdapter::attachExample(Example* example) {
    return m_window->attachExample(example);
}

bool GlfwWindowAdapter::isRunning() {
    return m_window->isRunning();
}

void GlfwWindowAdapter::swapBuffers() {
    m_window->swapBuffers();
}

float GlfwWindowAdapter::getElapsedSeconds() {
    return m_window->getElapsedSeconds();
}
