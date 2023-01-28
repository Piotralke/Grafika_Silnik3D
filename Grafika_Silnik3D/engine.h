#pragma once
#ifndef engine_h
#define engine_h
#include <string>
#include "Bullet.h"
#include "Point3D.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Line.h"
#include "TriangleStrip.h"
#include "Camera.h"
#include "BitmapHandler.h"
#include <time.h>
#include <filesystem>
/**
 * @brief Metoda wyzwalająca callback myszki
 * 
 * @param window okno aplikacji
 * @param xpos pozycja x myszy
 * @param ypos pozycja y myszy
 */
void MouseCallback(GLFWwindow* window, double xpos, double ypos);
/**
 * @brief Metoda wyzwalająca callback lkawiatury
 * 
 * @param window kno aplikacji
 * @param button przycisk
 * @param action akcja
 * @param mods tryb wciśnięcia
 */
void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
/**
 * @brief Metoda sprawdzająca kolizję
 * 
 * @param ob1 objekt 1
 * @param ob2 objekt 2
 * @return true jesli wystąpi kolizja
 * @return false jeśli nie będzie kolizji
 */
bool checkCollision(Cube ob1, Cube ob2);
/**
 * @brief główna klasa Engine
 * 
 */
class Engine
{
private:
	/*!<Wskaźnik na kamerę*/
	Camera* camera;
	/*!<Wskaźnik na handlera bitmap*/
	BitmapHandler* bitmapHandler;
	/*!<Wskaźnik na intancję silnika*/
	static Engine* instance;
	/*!<Wskaźnik na okno aplikacji*/
	GLFWwindow* window;
	/*!<Wskaźnik na monitor*/
	GLFWmonitor* monitor;
	/*<! Szerokość ekranu*/
	unsigned int screenWidth;
	/*!<Wysokość ekranu*/
	unsigned int screenHeight;
	/*!<Czas pomiędzy klatkami*/
	float deltaTime;
	/*<!Czas ostatniej klatki*/
	float lastFrame;
	/*!<Macierz projekcji*/
	glm::mat4 projection;
	/*!<Kolor tła*/
	glm::vec4 backgroundColor = glm::vec4(0.0f,0.0f,1.0f,0.1f);
	/*!<wektor sześcianów*/
	std::vector<Cube> cubesVector;
	/*!<Wektor celów*/
	std::vector<Cube> targetVector;

	/*!<Vertex Shader*/
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec2 aTexCoord;\n"
		"out vec2 TexCoord;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
    	"{\n"
    	"   gl_Position = projection*view*model*vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
    	"}\0";
	/*!<Fragment Shader*/
	const char *fragmentShaderSource ="#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec2 TexCoord;\n"
		"uniform sampler2D texture1;\n"
		"void main()\n"
    	"{\n"
    	"  FragColor = texture(texture1, TexCoord);\n"
		"}\0";
	/*!<Vertex Lightning Shader*/
	const char* vertexLightningShaderSource = "#version 330 core\n"
		"layout(location = 0) in vec3 aPos;"
		"layout(location = 1) in vec3 aNormal;\n"
		"layout(location = 2) in vec2 aTexCoords;\n"
		"out vec3 FragPos;\n"
		"out vec2 TexCoords;\n"
		"out vec3 Normal;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"

		"void main()\n"
		"{\n"
		"FragPos = vec3(model * vec4(aPos, 1.0));\n"
		"Normal = mat3(transpose(inverse(model))) * aNormal;\n"
		"TexCoords = aTexCoords;\n"
		"gl_Position = projection * view * vec4(FragPos, 1.0);\n"
		"}\0";
		/*!<Fragment lightning shader*/
	const char* fragmentLightningShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"struct Material {\n"
		"sampler2D diffuse;\n"
		"vec3 specular;\n"
		"float shininess;\n"
		"};\n"
		"struct Light {\n"
		"vec3 position;\n"
		"vec3 ambient;\n"
		"vec3 diffuse;\n"
		"vec3 specular;\n"
		"};\n"
		"in vec3 FragPos;\n"
		"in vec3 Normal;\n"
		"in vec2 TexCoords;\n"

		"uniform vec3 viewPos;\n"
		"uniform Material material;\n"
		"uniform Light light;\n"

		"void main()\n"
		"{\n"
		"vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;\n"
		"vec3 norm = normalize(Normal);\n"
		"vec3 lightDir = normalize(light.position - FragPos);\n"
		"float diff = max(dot(norm, lightDir), 0.0);\n"
		"vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;\n"
		"vec3 viewDir = normalize(viewPos - FragPos);\n"
		"vec3 reflectDir = reflect(-lightDir, norm);\n"
		"float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess); \n"
		"vec3 specular = light.specular * (spec * material.specular); \n"
		"vec3 result = ambient + diffuse + specular;\n"
		"FragColor = vec4(result, 1.0);\n"
		"}\0";
	
		unsigned int vertexShader;
		unsigned int fragmentShader;
		unsigned int programShader2;
		unsigned int VBO, VAO;
		unsigned int vertexLightningShader;
		unsigned int fragmentLightningShader;
public:
/**
 * @brief 
 * Vector przechowujący pociski
 */
	std::vector<Bullet> bulletsVector;
	/**
	 * @brief Konstruktor klasy Engine
	 * 
	 * @param width szerokość
	 * @param height wysokość
	 * @param Title tytuł okna
	 * @param monitor wskaźnik na monitor
	 */
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
		vertexLightningShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexLightningShader, 1, &vertexLightningShaderSource, NULL);
		glCompileShader(vertexLightningShader);
		glGetShaderiv(vertexLightningShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexLightningShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		fragmentLightningShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentLightningShader, 1, &fragmentLightningShaderSource, NULL);
		glCompileShader(fragmentLightningShader);
		glGetShaderiv(fragmentLightningShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentLightningShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		programShader2 = glCreateProgram();
		glAttachShader(programShader2, vertexLightningShader);
		glAttachShader(programShader2, fragmentLightningShader);
		glLinkProgram(programShader2);
		glGetProgramiv(programShader2, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(programShader2, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glDeleteShader(vertexLightningShader);
		glDeleteShader(fragmentLightningShader);

		

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
     	this->screenHeight = height;
		this->screenWidth = width;
		this->monitor = monitor;
		camera = new Camera(width, height,programShader2,programShader2, window);
		glfwSetMouseButtonCallback(window, MouseButtonCallback);
		glfwSetCursorPosCallback(window, MouseCallback);
		
	}
	/**
	 * @brief ustawia rozmiar ekranu 
	 * 
	 * @param width szerokość okna
	 * @param height wysokość okna
	 */
	void setWindowSize(unsigned int width, unsigned int height);
	/**
	 * @brief przełącza pełny ekran
	 * 
	 * @param fullscreen czy włączyć czy wyłączyć
	 */
	void isFullscreen(bool fullscreen);
	/**
	 * @brief inicjacja silnika
	 * 
	 */
	void init();
	/**
	 * @brief przetwarzanie urządzeń wejścia
	 * 
	 */
	void processInput();
	/**
	 * @brief główna pętla gry
	 * 
	 */
	void mainLoop();
	/**
	 * @brief Ustawia kolor tła
	 * 
	 * @param r intensywność czerwonego
	 * @param g intensywność zielonego
	 * @param b intensywność niebieskiego
	 * @param a kanał alfa
	 */
	void setBackgroundColor(float r,float g,float b,float a);
	/**
	 * @brief generowanie sześcianów
	 * 
	 */
	void generateCube();
	/**
	 * @brief pobieranie instancji klasy
	 * 
	 * @return wskaźnik na klasę engine 
	 */
	static Engine* getInstance()
	{
		return instance;
	}
	/**
	 * @brief pobieranie wskaźnika na kamerę
	 * 
	 * @return wskaźnik na kamerę 
	 */
	Camera* getCamera()
	{
		return camera;
	}
	/**
	 * @brief pobieranie wskaźnika na okno
	 * 
	 * @return wskaźnik na okno 
	 */
	GLFWwindow* getWindow();
};
#endif // !engine_h
