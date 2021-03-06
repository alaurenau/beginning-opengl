#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>

#include <GLee.h>
#include <GL/glu.h>

#include "example.h"
#include "glslshader.h"
#include "freetypefont.h"

Example::Example():
m_angle(0.0),
m_font(NULL)
{

}

Example::~Example() 
{
    delete m_font;
}

bool Example::init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    //Viewport[2] stores the width of the viewport, vieport[3] stores the height
    //We pass these into our font so the ortho mode can set the resolution for the window
    m_font = new FreeTypeFont("data/LiberationSans-Regular.ttf", viewport[2], viewport[3], 36);
    if (!m_font->initialize()) {
        std::cerr << "Could not initialize the font" << std::endl;
        return false;
    }
    return true;
}


void Example::prepare(float dt)
{
}


void Example::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Load the identity matrix (reset to the default position and orientation)
    glLoadIdentity();

    m_font->printString("2D Fonts with FreeType!", 250, 390);
}

void Example::shutdown()
{

}

void Example::onResize(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(52.0f, float(width) / float(height), 1.0f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

