#ifndef _EXAMPLE_H
#define _EXAMPLE_H

#include <GL/gl.h>
#include <vector>
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
    vector<float> m_vertices;
    GLuint m_vertexBuffer;
};

#endif