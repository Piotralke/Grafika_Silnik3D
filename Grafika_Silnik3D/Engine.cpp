#include "engine.h"

Engine* Engine::instance = NULL;
void Engine::init()
{
    glfwSetWindowSizeLimits(getWindow(), 1024, 576, GLFW_DONT_CARE, GLFW_DONT_CARE);
	glfwMakeContextCurrent( this->getWindow() );
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
	}
}
void Engine::processInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		isFullscreen(true);
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
		isFullscreen(false);
	float cameraSpeed = static_cast<float>(2.5 * deltaTime);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->VerticalMove(true, cameraSpeed);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->VerticalMove(false, cameraSpeed);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->HorizontalMove(false, cameraSpeed);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->HorizontalMove(true, cameraSpeed);
}
void Engine::setWindowSize(unsigned int width, unsigned int height)
{
	glfwSetWindowSize(this->window, width, height);
}
void Engine::isFullscreen(bool fullscreen)
{
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	if (fullscreen)
	{
		glfwSetWindowMonitor(this->window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
	}
	else
	{
		glfwSetWindowMonitor(this->window, NULL, mode->width *0.1, mode->height *0.1, mode->width *0.8, mode->height *0.8, mode->refreshRate);
	}
}
GLFWwindow* Engine::getWindow()
{
	return this->window;
}
void Engine::setBackgroundColor(float r, float g, float b, float a)
{
    backgroundColor.r = r/255;
    backgroundColor.g = g/255;
    backgroundColor.b = b/255;
    backgroundColor.a = a/255;
}
void Engine::mainLoop()
{
    //Point3D point3D(-0.5f, -0.5f,0.0f);
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
        -0.5f,  0.5f, 0.0f,  // top left    
    };
    float vertices2[] = {
        2.0f, 3.5f, -3.0f, // left     
    };
    float vertices3[] = {
		0.7f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.8f, 0.0f   // top left     
    };
    float vertices4[] = {
		0.7f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right    
    };
    float vertices5[] = {
		0.7f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.8f, 0.0f,   // top left   
    };
	float vertices6[] = { 
		0.5f, 0.5f, 0.5f,       1.0f,0.0f,0.0f,//1 
		-0.5f, 0.5f, 0.5f,	    1.0f,0.0f,0.0f,//2
		-0.5f, 0.5f, -0.5f,	    1.0f,0.0f,0.0f,//3
		0.5f,0.5f,-0.5f,	    1.0f,0.0f,0.0f,//4
		0.5f, -0.5f, 0.5f,	    1.0f,0.0f,0.0f,//5
		-0.5f, -0.5f, 0.5f,	    1.0f,0.0f,0.0f,//6
		-0.5f, -0.5f, -0.5f,	1.0f,0.0f,0.0f,//7
		0.5f,-0.5f,-0.5f,	    1.0f,0.0f,0.0f//8


	};
	glm::vec3 red(1.0f, 0.0f, 0.0f);
	glm::vec3 blue(0.0f, 0.0f, 1.0f);
	glm::vec3 green(0.0f, 1.0f, 0.0f);
	glm::vec3 yellow(1.0f, 1.0f, 0.0f);
	glm::vec3 pos(1.5f, 2.0f, -1.0f);
	glm::vec3 pos2(0.0f, 2.0f, -1.0f);
	glm::vec3 pos3(-1.5f, 2.0f, -1.0f);
	glm::vec3 pos4(-1.5f, -10.0f, -1.0f);
	
    Point3D point(vertices2);
    Triangle triangle(vertices);
	Rectangle rectangle(vertices3);
    Line line(vertices4);
    TriangleStrip triangleStrip(vertices5,sizeof(vertices5)/sizeof(float));
	Cube cube(pos,red);
	Cube cube2(pos2,yellow);
	Cube cube3(pos3,green);
	Cube cube4(pos3,yellow);
	Cube asd(pos4, blue);
	asd.scale(15.0);
	cubesVector.push_back(asd);
	cubesVector.push_back(cube);
	cubesVector.push_back(cube2);
	cubesVector.push_back(cube3);
	cubesVector.push_back(cube4);

    while (!glfwWindowShouldClose(getWindow()))
    {
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
        processInput();
        glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programShader);
		//glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		//glm::mat4 view = glm::mat4(1.0f);
		//glm::mat4 projection = glm::mat4(1.0f);
		//model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		//projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
		//// retrieve the matrix uniform locations
		//unsigned int modelLoc = glGetUniformLocation(programShader, "model");
		//unsigned int viewLoc = glGetUniformLocation(programShader, "view");
		//// pass them to the shaders (3 different ways)
		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &model[0][0]);
		//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
		//glUniformMatrix4fv(glGetUniformLocation(programShader, "projection"), 1, GL_FALSE, &projection[0][0]);

        //triangle.draw();
        //point.draw();
        //rectangle.draw();
		point.draw();
		camera->UpdateCamera(programShader);
        //line.draw();
		//glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		//glUniformMatrix4fv(glGetUniformLocation(programShader, "view"), 1, GL_FALSE, &view[0][0]);
		//glm::mat4 model = glm::mat4(1.0f);
		//glUniformMatrix4fv(glGetUniformLocation(programShader, "model"), 1, GL_FALSE, &model[0][0]);
		//triangleStrip.draw();
		for (int i = 0; i < cubesVector.size(); i++)
		{
			cubesVector[i].draw(programShader);
		}
		for (int i = 0; i < bulletsVector.size(); i++)
		{
			bulletsVector[i].move(deltaTime);
			bulletsVector[i].rotateZ(0.5);
			bulletsVector[i].rotateX(0.5);
			bulletsVector[i].rotateY(0.5);
			bulletsVector[i].draw(programShader);
			for (int j = 0; j < cubesVector.size(); j++)
			{
				if (checkCollision(cubesVector[j], bulletsVector[i]))
				{
					bulletsVector.erase(bulletsVector.begin() + i);
					break;
				}
			}
			
		}
		glfwSwapBuffers(getWindow());
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(programShader);
    glfwTerminate();
}

void MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	Engine* eng = Engine::getInstance();
	eng->getCamera()->UpdateMouse(xpos, ypos);
}

void MouseButtonCallback(GLFWwindow* window,int button, int action, int mods)
{
	Engine* eng = Engine::getInstance();
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		glm::vec3 view = eng->getCamera()->getCameraPos();
		glm::vec3 direction =glm::normalize(eng->getCamera()->getCameraFront() );
		//std::cout << "X: " << direction.x << "Y: " << direction.y << "Z: " << direction.z << std::endl;
		Bullet bullet(view, glm::vec3(1.0, 1.0, 1.0), direction);
		eng->bulletsVector.push_back(bullet);
	}

	//
}

bool checkCollision(Cube ob1, Cube ob2)
{
	// collision x-axis
	bool collisionX = ob1.getPosition().x + 0.5 * ob1.getScalingFactor().x >= ob2.getPosition().x &&
		ob2.getPosition().x + 0.5 * ob1.getScalingFactor().x >= ob1.getPosition().x;
	// collision y-axis
	bool collisionY = ob1.getPosition().y +0.5*ob1.getScalingFactor().y >= ob2.getPosition().y &&
		ob2.getPosition().y + 0.5 * ob1.getScalingFactor().y >= ob1.getPosition().y;
	// collision z-axis
	bool collisionZ = ob1.getPosition().z + 0.5 * ob1.getScalingFactor().z >= ob2.getPosition().z &&
		ob2.getPosition().z + 0.5 * ob1.getScalingFactor().z >= ob1.getPosition().z;
	return collisionX && collisionY && collisionZ;
}
