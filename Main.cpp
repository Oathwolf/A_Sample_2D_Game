#include<iostream>
#include<map>
#include<list>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<memory>

#define STB_IMAGE_IMPLEMENTATION
#include<stb-master/stb_image.h>

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>

#include"Common/CommonStruct.h"

#include"Common/VAOStruct.h"
#include"Common/camera.h"
#include"Common/Light.h"
#include"Common/Shader.h"
#include"Common/Texture.h"

#include"Component/SpriteComponent.h"
#include"Component/Collision.h"

#include"Object/Object.h"
#include"Object/ObjectEnity.h"

#include"Common/QuadTree.h"
#include"Common/Scene.h"

#include"Manager/LightManager.h"
#include"Manager/ShaderManager.h"
#include"Manager/TextureManager.h"
#include"Manager/VAOManager.h"
#include"Manager/SceneManager.h"
#include"Manager/SpriteManager.h"
#include"Manager/RandomManager.h"

#include"Scene/BindVAO.h"
#include"Scene/BindTexture.h"
#include"Scene/BindShader.h"
#include"Scene/BindScene.h"
#include"Scene/BindLight.h"
#include"Scene/BindSprite.h"


void set_view(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void input(GLFWwindow* window);

const float PI = 3.14159;

const unsigned int SCR_WIDTH = 700;
const unsigned int SCR_HEIGHT = 700;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = (float)SCR_WIDTH / 2.0;
float lastY = (float)SCR_HEIGHT / 2.0;
bool firstMouse = true;

float shadow = 0.0f;
float deltaTime = 0.0f;
float lastTime = 0.0f;
glm::vec3 mouseDirection = glm::vec3(0.0f, 0.0f, 0.0f);

VAOManager* vaoManager = VAOManager::GetVAOManager();
ShaderManager* shaderManager = ShaderManager::GetShaderManager();
SceneManager* sceneManager = SceneManager::GetSceneManager();
TextureManager* textureManager = TextureManager::GetTextureManager();
LightManager* lightManager = LightManager::GetLightManager();
SpriteManager* spriteManager = SpriteManager::GetSpriteManager();
RandomManager* randomManager = RandomManager::GetRandomManager();

GLFWwindow* window = nullptr;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_ANY_PROFILE);
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "MyGame", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, set_view);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glEnable(GL_DEPTH_TEST);

	BindVAO();
	BindTexture();
	BindShader();
	BindLight();
	BindSprite();
	
	BindScene();

	Scene scene;
	scene = sceneManager->GetScene("scene");
	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastTime;
		lastTime = currentFrame;
		
		input(window);
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		scene.Update(deltaTime);
		scene.Draw(SCR_WIDTH,SCR_HEIGHT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;

}
void input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		camera.Position.y = camera.Position.y + 1.0f*deltaTime;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		camera.Position.y = camera.Position.y - 1.0f*deltaTime;
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		camera.Position.x = camera.Position.x - 1.0f*deltaTime;
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		camera.Position.x = camera.Position.x + 1.0f*deltaTime;
}
void set_view(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	mouseDirection = glm::vec3((xpos - SCR_WIDTH / 2)/(SCR_WIDTH/2), (SCR_HEIGHT / 2 - ypos)/(SCR_HEIGHT/2), 0.0f);
	mouseDirection = glm::normalize(mouseDirection);
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	//camera.ProcessMouseMovement(xoffset,yoffset);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}