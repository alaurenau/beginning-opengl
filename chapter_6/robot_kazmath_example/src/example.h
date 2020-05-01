#ifndef _EXAMPLE_H
#define _EXAMPLE_H

#include <vector>

#include <GL/matrix.h>
#include <mat4.h>
#include <examplecallback.h>

#include "Robot.h"

using std::vector;
class GLSLProgram;

class Example: public ExampleCallback
{
public:
    Example();
    ~Example();

    bool init();
    void prepare(float dt);
    void render();
    void shutdown();

    void onResize(int width, int height);

private:
    Robot m_robot;
    float m_rotationAngle;
    GLSLProgram* m_shader;
};

#endif
