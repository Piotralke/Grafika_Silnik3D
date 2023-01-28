#include "engine.h"
namespace sf = std::filesystem;
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
	float cameraSpeed = static_cast<float>(6.0 * deltaTime);
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
		0.1f,  0.1f, 0.0f,  // top right
		 0.1f, -0.1f, 0.0f,  // bottom right
		-0.1f, -0.1f, 0.0f,  // bottom left
		-0.1f,  0.1f, 0.0f   // top left     
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
	glm::vec3 gray(175.0f/256.0f, 175.0f / 256.0f, 175.0f / 256.0f);
	glm::vec3 darkGray(125.0f/256.0f, 125.0f / 256.0f, 125.0f / 256.0f);
	glm::vec3 orange(1.0f, 160.0f / 256.0f, 20.0f / 256.0f);
	glm::vec3 pos(1.5f, 2.0f, -1.0f);
	glm::vec3 pos2(0.0f, 2.0f, -1.0f);
	glm::vec3 pos3(-1.5f, 2.0f, -1.0f);
	glm::vec3 pos4(-1.5f, -20.0f, 0.0f); //bottom
	glm::vec3 pos9(-1.5f, 30.0f, -1.0f); //top
	glm::vec3 pos5(-1.5f, 10.0f, -30.0f); //front
	glm::vec3 pos6(-1.5f, 10.0f, 30.0f); //back
	glm::vec3 pos7(-30.0f, 10.0f, 0.0f); //left
	glm::vec3 pos8(27.0f, 10.0f, 0.0f); //right
	Cube aim(pos, red);
	Cube hitbox(pos, red);
    Point3D point(vertices2);
    Triangle triangle(vertices);
	Rectangle rectangle(vertices3);
    Line line(vertices4);
    TriangleStrip triangleStrip(vertices5,sizeof(vertices5)/sizeof(float));
	Cube wall(pos5,darkGray);
	Cube wallBack(pos6,darkGray);
	Cube wallLeft(pos7,darkGray);
	Cube wallRight(pos8,darkGray);
	Cube wallTop(pos9,darkGray);
	Cube asd(pos4, gray);
	asd.scale(30.0);
	wall.scale(30.0);
	wallBack.scale(30.0);
	wallLeft.scale(30.0);
	wallRight.scale(30.0);
	wallTop.scale(30.0);
	cubesVector.push_back(asd);
	aim.scale(0.002);
	cubesVector.push_back(wall);
	cubesVector.push_back(wallBack);
	cubesVector.push_back(wallLeft);
	cubesVector.push_back(wallRight);
	cubesVector.push_back(wallTop);
	float respawnTimer = 1.2f;
	float time = 0.0f;
	std::string parentDir = (sf::current_path().sf::path::parent_path()).string();
	std::string texPath = "\\resources\\textures\\container.jpg";
	unsigned int diffuseMap = bitmapHandler->loadTexture((parentDir+texPath).c_str());

	std::string texPathWall = "\\resources\\textures\\wall.jpg";
	unsigned int diffuseMap2 = bitmapHandler->loadTexture((parentDir + texPathWall).c_str());

	std::string texPathWall2 = "\\resources\\textures\\floor.jpg";
	unsigned int floor = bitmapHandler->loadTexture((parentDir + texPathWall2).c_str());

	std::string texPathWall3 = "\\resources\\textures\\aim.jpg";
	unsigned int aimT = bitmapHandler->loadTexture((parentDir + texPathWall3).c_str());

	glEnable(GL_TEXTURE_2D);
	glUseProgram(programShader2);
	glUniform1i(glGetUniformLocation(programShader2, "material.diffuse"), 0);
    while (!glfwWindowShouldClose(getWindow()))
    {
		glUseProgram(programShader2);
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
        processInput();
        glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         
        glUseProgram(programShader2); 
		glUniform3f(glGetUniformLocation(programShader2, "light.position"), 0, 10, 0);
		glUniform3f(glGetUniformLocation(programShader2, "viewPos"), camera->getCameraPos().x, camera->getCameraPos().y,camera->getCameraPos().z);
		glUniform3f(glGetUniformLocation(programShader2, "light.ambient"), 0.2f, 0.2f, 0.2f);
		glUniform3f(glGetUniformLocation(programShader2, "light.diffuse"), 0.5f, 0.5f, 0.5f);
		glUniform3f(glGetUniformLocation(programShader2, "light.specular"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(programShader2, "material.specular"), 0.5f, 0.5f, 0.5f);
		glUniform1f(glGetUniformLocation(programShader2, "material.shininess"), 64.0f);

		glUseProgram(programShader2);
		time += deltaTime;
		if (time>=respawnTimer)
		{
			generateCube();
			time = time - respawnTimer;
		}
		glActiveTexture(GL_TEXTURE0);
		//;

		aim.setPosition(camera->getCameraPos()+camera->getCameraFront());
		hitbox.setPosition(camera->getCameraPos());
		aim.draw(programShader2, aimT,2);
		camera->UpdateCamera(programShader2,programShader2);

		for (int i = 0; i < cubesVector.size(); i++)
		{
			if (checkCollision(cubesVector[i], hitbox))
			{
				camera->setCameraPos(glm::vec3(0, 0, 0));
			}
			cubesVector[i].draw(programShader2, diffuseMap2,2);
		}
		for (int i = 0; i < targetVector.size(); i++)
		{
			targetVector[i].draw(programShader2, floor,1);
		}
		for (int i = 0; i < bulletsVector.size(); i++)
		{
			bool deleted = false;
			bulletsVector[i].move(deltaTime);
			bulletsVector[i].rotateZ(0.5);
			bulletsVector[i].rotateX(0.5);
			bulletsVector[i].rotateY(0.5);
			bulletsVector[i].draw(programShader2,aimT,1);
			for (int j = 0; j < cubesVector.size(); j++)
			{
				if (checkCollision(cubesVector[j], bulletsVector[i]))
				{
					//std::cout << "X: " << bulletsVector[i].getPosition().x << " Y: " << bulletsVector[i].getPosition().y << " Z: " << bulletsVector[i].getPosition().z << std::endl;
					bulletsVector.erase(bulletsVector.begin() + i);
					deleted = true;
					break;
				}
			}
			if (deleted)
				break;
			for (int j = 0; j < targetVector.size(); j++)
			{
				if (checkCollision(targetVector[j], bulletsVector[i]))
				{
					std::cout << "X: " << bulletsVector[i].getPosition().x << " Y: " << bulletsVector[i].getPosition().y << " Z: " << bulletsVector[i].getPosition().z << std::endl;
					bulletsVector.erase(bulletsVector.begin() + i);
					targetVector.erase(targetVector.begin() + j);
					break;
				}
			}
			
		}
		glfwSwapBuffers(getWindow());
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(programShader2);
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
void Engine::generateCube()
{
	srand(time(NULL));
	float x = rand() % 18 - 10.0;
	float y = rand() % 10 - 4;
	float z = -13.0f;
	Cube newCube(glm::vec3(x, y, z), glm::vec3(1.0f, 160.0f / 256.0f, 20.0f / 256.0f));
	targetVector.push_back(newCube);
}