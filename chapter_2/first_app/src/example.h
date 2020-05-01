#ifndef _EXAMPLE_H
#define _EXAMPLE_H

#include <examplecallback.h>

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
    float m_rotationAngle;
};

#endif
