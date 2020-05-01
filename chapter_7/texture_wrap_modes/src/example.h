#ifndef _EXAMPLE_H
#define _EXAMPLE_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <examplecallback.h>
#include <vector>
#include <string>
#include <GLee.h>
#include "targa.h"
#include <glfwwindow.h>

class GLSLProgram; 

using std::vector;
using std::string;


class Example: public ExampleCallback
{
public:
    Example();
    virtual ~Example();

    bool init();
    void prepare(float dt);
    void render();
    void shutdown();

    void onResize(int width, int height);

    GlfwWindow* m_window;

private:
    GLSLProgram* m_GLSLProgram;
    TargaImage m_texture;
    GLuint m_texID;

    GLuint m_vertexBuffer;
    GLuint m_texCoordBuffer;

    GLint m_wrapMode;
};

#endif
