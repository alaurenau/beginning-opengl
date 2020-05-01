#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <vector>
#include <string>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

using std::vector;

void error(const std::string& s) {
#ifdef _WIN32
	MessageBox(NULL, s.c_str(), "An error occurred", MB_ICONINFORMATION | MB_OK);
#else
	std::cerr << s << std::endl;
#endif
}

class SimpleApp
{
public:
    static const int WINDOW_WIDTH = 1024;
    static const int WINDOW_HEIGHT = 768;

    SimpleApp();
    bool initialize();
    void resize(int x, int y);
    void prepare();
    void render();
};

SimpleApp::SimpleApp()
{

}

bool SimpleApp::initialize()
{
    //Enable depth testing
    glEnable(GL_DEPTH_TEST);
    //Set up the projection matrix
    resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    return true;
}

void SimpleApp::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0, 1.0, 6.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLES);
        //Send the vertices and colors for the triangle
        glColor4f(1.0, 0.0, 0.0, 1.0);
        glVertex3f(2.0, 2.5, -1.0);
        glColor4f(0.0, 1.0, 0.0, 1.0);
        glVertex3f(-3.5, -2.5, -1.0);
        glColor4f(0.0, 0.0, 1.0, 1.0);
        glVertex3f(2.0, -4.0, -1.0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        //Send the vertices and colors for the pentagon
        glColor4f(1.0, 1.0, 1.0, 1.0);
        glVertex3f(-1.0, 2.0, 0.0);
        glColor4f(1.0, 1.0, 0.0, 1.0);
        glVertex3f(-3.0, -0.5, 0.0);
        glColor4f(0.0, 1.0, 1.0, 1.0);
        glVertex3f(-1.5, -3.0, 0.0);
        glColor4f(0.0, 0.0, 0.0, 1.0);
        glVertex3f(1.0, -2.0, 0.0);
        glColor4f(1.0, 0.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 0.0);
    glEnd();
}

void SimpleApp::resize(int w, int h)
{
    //Prevent a divide by zero error
    if (h <= 0)
    {
        h = 1;
    }

    //When we resize the window, we tell OpenGL about the new viewport size
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION); //deprecated
    glLoadIdentity();
    //Then we set up our projection matrix with the correct aspect ratio
    gluPerspective(60.0f, float(w) / float(h), 1.0f, 100.0f); //deprecated

    glMatrixMode(GL_MODELVIEW); //deprecated
    glLoadIdentity(); //deprecated
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // When a user presses the escape key, we set the WindowShouldClose property to true,
    // closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

static SimpleApp myApp;

void resize_callback(GLFWwindow *window, int width, int height)
{
    myApp.resize(width, height);
}

int main(int argc, char** argv)
{


    if (glfwInit() != GL_TRUE)
    {
        std::cerr << "Could not initialize window" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_RED_BITS, 5);
    glfwWindowHint(GLFW_GREEN_BITS, 5);
    glfwWindowHint(GLFW_BLUE_BITS, 5);
    glfwWindowHint(GLFW_ALPHA_BITS, 5);
    glfwWindowHint(GLFW_DEPTH_BITS, 16);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    std::string title = "BOGLGP Chapter 1";

    // Create the window
    GLFWwindow* window = glfwCreateWindow(SimpleApp::WINDOW_WIDTH, SimpleApp::WINDOW_HEIGHT,
                                          title.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Could not create the window" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowSizeCallback(window, resize_callback);

    if (!myApp.initialize())
    {
        glfwTerminate();
        return 1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        myApp.render();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
	
    return 0;
}
