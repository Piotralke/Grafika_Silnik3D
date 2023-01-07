#pragma once
#ifndef engine_h
#define engine_h
#include <string>
#include <iostream>
#include "Bullet.h"
#include "Point3D.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Line.h"
#include "TriangleStrip.h"
#include "Camera.h"
#include <time.h>

void MouseCallback(GLFWwindow* window, double xpos, double ypos);
void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
bool checkCollision(Cube ob1, Cube ob2);
class Engine
{
private:
	Camera* camera;
	static Engine* instance;
	GLFWwindow* window;
	GLFWmonitor* monitor;
	unsigned int screenWidth;
	unsigned int screenHeight;
	float deltaTime;
	float lastFrame;
	glm::mat4 projection;
	glm::vec4 backgroundColor = glm::vec4(0.0f,0.0f,1.0f,0.1f);
	std::vector<Cube> cubesVector;
	std::vector<Cube> targetVector;

	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 color;\n"
		"out vec4 vertexColor;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
    	"{\n"
    	"   gl_Position = projection*view*model*vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"	vertexColor = vec4(color.x, color.y, color.z, 1.0);\n"
    	"}\0";
	const char *fragmentShaderSource ="#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec4 vertexColor;\n"
		"void main()\n"
    	"{\n"
    	"   FragColor = vertexColor;\n"
		"}\0";
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int programShader;
	unsigned int VBO, VAO;
public:
	std::vector<Bullet> bulletsVector;
	Engine(unsigned int width, unsigned int height, std::string Title, GLFWmonitor* monitor)
	{
		
		this->instance = this;
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glEnable(GL_DEPTH_TEST);
		this->window = glfwCreateWindow(width, height, Title.c_str(), monitor, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		init();
		
		int success;
		char infoLog[512];
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glEnable(GL_DEPTH_TEST);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		programShader = glCreateProgram();
		glAttachShader(programShader, vertexShader);
		glAttachShader(programShader, fragmentShader);
		glLinkProgram(programShader);
		glGetProgramiv(programShader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(programShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
     	this->screenHeight = height;
		this->screenWidth = width;
		this->monitor = monitor;
		camera = new Camera(width, height,programShader, window);
		glfwSetMouseButtonCallback(window, MouseButtonCallback);
		glfwSetCursorPosCallback(window, MouseCallback);
		
	}
	void setWindowSize(unsigned int width, unsigned int height);
	void isFullscreen(bool fullscreen);
	void init();
	void processInput();
	void mainLoop();
	void setBackgroundColor(float r,float g,float b,float a);
	void generateCube();
	static Engine* getInstance()
	{
		return instance;
	}
	Camera* getCamera()
	{
		return camera;
	}
	GLFWwindow* getWindow();
};
#endif // !engine_h
