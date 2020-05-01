#ifndef _EXAMPLE_H
#define _EXAMPLE_H

#include <vector>
#include "robot.h"
#include <examplecallback.h>

using std::vector;

class Example: public ExampleCallback
{
public:
    Example();

    bool init();
    void prepare(float dt);
    void render();
    void shutdown();

    void onResize(int width, int height);

private:
    Robot m_robot;
    GLfloat m_rotationAngle;
};

#endif
