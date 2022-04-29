#pragma once
#include"../Manager/VAOManager.h"
#include"../Manager/LightManager.h"
#include"../Manager/ShaderManager.h"
#include"../Manager/SpriteManager.h"
#include"../Manager/TextureManager.h"

#include"BulletObject.h"
#include"MagazineObject.h"
#include"BombObject.h"

extern LightManager* lightManager;
extern ShaderManager* shaderManager;
extern TextureManager* textureManager;
extern SpriteManager* spriteManager;
extern VAOManager* vaoManager;
extern GLFWwindow* window;
extern float deltaTime;
extern glm::vec3 mouseDirection;
extern Camera camera;
extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;
extern const float PI;

class PlayerObject:public SphereObject
{
public:
	PlayerObject()
	{
		position = glm::vec3(0.0f, 0.0f, 0.0f);
		velcoity = glm::vec3(0.0f, 0.0f, 0.0f);
		scale = glm::vec3(0.1f);
		shader = shaderManager->GetShader("CommonShader");
		accelerated = glm::vec3(0, 0, 0);
		texture_array.push_back(textureManager->GetTexture("Player"));
		magazine_time = 0.0f;
		spot_light_array.push_back(lightManager->GetSpotLight("SpotLight"));
		point_light_array.push_back(lightManager->GetPointLight("PlayerPointLight"));
		radius = 0.1f;
		turn_light_time = 0.0f;
		shoot_time = 0.0f;
		sprint_time = 0.0f;
		grenate_time = 0.0f;
		mass = 70.0f;
		isSphere = true;
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();
	}
	virtual void Update() override
	{

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			accelerated.y = 0.1f;
			texture_array.clear();
			texture_array.push_back(textureManager->GetTexture("PlayerUpMove"));
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			accelerated.y = -0.1f;
			texture_array.clear();
			texture_array.push_back(textureManager->GetTexture("Player"));
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			accelerated.x = -0.1f;
			texture_array.clear();
			texture_array.push_back(textureManager->GetTexture("PlayerBackMove"));
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			accelerated.x = 0.1f;
			texture_array.clear();
			texture_array.push_back(textureManager->GetTexture("PlayerFrontMove"));
		}
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		{
			if (turn_light_time == 0)
			{
				if (isLight)
				{
					isLight = false;
					turn_light_time = 1.0f;
				}
				else
				{
					isLight = true;
					turn_light_time = 1.0f;
				}
			}
		}
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			velcoity = velcoity - 0.1f*velcoity;
			texture_array.clear();
			texture_array.push_back(textureManager->GetTexture("Player"));
		}
		if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		{
			if (magazine_time == 0)
			{
				isCreate = true;
				std::shared_ptr<Object> pobject = std::make_shared<CommonMagazine>();
				pobject->SetPosition(position);
				pobject->SetVelcoity(velcoity);
				create_object_array.push_back(pobject);
				magazine_time = 2.0f;
			}
		}
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
		{
			if (mouseDirection.x > 0)
			{
				rotate = atan(mouseDirection.y / mouseDirection.x);
			}
			if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
			{
				if (shoot_time == 0)
				{
					isCreate = true;
					glm::vec3 shoot_position = position + mouseDirection * radius;
					std::shared_ptr<Object> pobject = std::make_shared<CommonBullet>();
					pobject->SetPosition(shoot_position);
					pobject->SetVelcoity(mouseDirection*5.0f + velcoity);
					create_object_array.push_back(pobject);

					pobject = std::make_shared<FireParticle>();
					pobject->SetPosition(position);
					create_object_array.push_back(pobject);
					velcoity -= mouseDirection * 0.1f;
					shoot_time = 0.5f;
				}
			}
			if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_4) == GLFW_PRESS)
			{
				if (shoot_time == 0)
				{
					isCreate = true;
					glm::vec3 shoot_position = position + mouseDirection * radius;
					std::shared_ptr<Object> pobject = std::make_shared<LightBullet>();
					pobject->SetPosition(shoot_position);
					pobject->SetVelcoity(mouseDirection*5.0f + velcoity);
					create_object_array.push_back(pobject);

					pobject = std::make_shared<FireParticle>();
					pobject->SetPosition(position);
					create_object_array.push_back(pobject);
					velcoity -= mouseDirection * 0.1f;
					shoot_time = 0.5f;
				}
			}
			if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
			{
				if (grenate_time == 0)
				{
					isCreate = true;
					glm::vec3 shoot_position = position + mouseDirection * radius;
					std::shared_ptr<Object> pobject = std::make_shared<CommonGrenade>();
					pobject->SetPosition(shoot_position);
					pobject->SetVelcoity(mouseDirection*3.0f + velcoity);
					create_object_array.push_back(pobject);
					velcoity -= mouseDirection * 0.1f;
					grenate_time = 0.5f;
				}
			}
		}
		velcoity = velcoity + deltaTime * accelerated;
		if (sprint_time > 0.0f)
		{
			sprint_time = sprint_time - deltaTime;
			if (sprint_time <= 0.0f)
			{
				sprint_time = 0.0f;
				velcoity = glm::vec3(0.0f);
			}
		}
		turn_light_time = Delay(turn_light_time);
		shoot_time = Delay(shoot_time);
		magazine_time = Delay(magazine_time);
		grenate_time = Delay(grenate_time);
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		{
			sprint_time = 0.1f;
			velcoity = mouseDirection* 3.0f;
			texture_array.clear();
			texture_array.push_back(textureManager->GetTexture("PlayerFrontMove"));
		}
		position = position + velcoity * deltaTime;
	
		if((!glfwGetKey(window,GLFW_KEY_LEFT)==GLFW_PRESS)&&
			(!glfwGetKey(window,GLFW_KEY_RIGHT)==GLFW_PRESS)&&
			(!glfwGetKey(window,GLFW_KEY_UP)==GLFW_PRESS)&&
			(!glfwGetKey(window,GLFW_KEY_DOWN)==GLFW_PRESS))
		camera.Position = glm::vec3(position.x,position.y,camera.Position.z);
	}
	virtual void End() override
	{
		accelerated = glm::vec3(0.0f);
		if (isCreate)
		{
			ClearCreateObjectArray();
			isCreate = false;
		}
	}
	virtual void Create() override
	{

	}
	virtual void Destory() override
	{

	}
	void SetAccelerated(glm::vec3 accelerated)
	{
		this->accelerated = accelerated;
	}
	glm::vec3 GetAccelerated()
	{
		return accelerated;
	}
	float Delay(float delay)
	{
		if (delay > 0.0f)
		{
			delay -= deltaTime;
			if (delay <= 0.0f)
			{
				delay = 0.0f;
			}
		}
		return delay;
	}
private:
	float turn_light_time;
	float magazine_time;
	float grenate_time;
	float shoot_time;
	float sprint_time;
	glm::vec3 accelerated;
};