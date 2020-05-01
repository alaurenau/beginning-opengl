#ifndef _EXAMPLE_H
#define _EXAMPLE_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <vector>
#include <string>
#include "md2model.h"
#include "terrain.h"
#include "targa.h"

#include "tree.h"
#include "monster.h"
#include "frustum.h"
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

    static vector<float> calculateNormalMatrix(const float* modelviewMatrix);
    
    void positionMonsters(int numMonsters);

    void setWindow(GlfwWindow* window) {
        m_window = window;
    }

private:
    Terrain m_terrain;
    GLSLProgram* m_terrainProgram;
    GLSLProgram* m_modelProgram;

    MD2Model m_model;
    std::vector<Monster> m_ogros;
    
    TargaImage m_ogroTexture;
    GLuint m_ogroTextureID;

    float m_rotationAngle;

    Frustum m_frustum;

    GlfwWindow* m_window;

    bool m_frustumCullingEnabled;

    float m_FPS;
    void updateFPS(float dt);
};

#endif
