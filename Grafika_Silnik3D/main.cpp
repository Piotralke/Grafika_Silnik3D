#include "engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "gbs" << std::endl;
    glViewport(0, 0, width, height);
}


// timing
float deltaTime = 0.0f;	
float lastFrame = 0.0f;

int main()
{
    Engine engine(1024,576,"Silnik3D",NULL);

    glfwSetFramebufferSizeCallback(engine.getWindow(), framebuffer_size_callback);
    engine.setBackgroundColor(0, 0, 0, 10);
    engine.mainLoop();
    glfwTerminate();
    return 0;
}
