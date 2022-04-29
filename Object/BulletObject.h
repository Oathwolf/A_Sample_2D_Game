#pragma once

extern glm::vec3 mouseDirection;
extern float deltaTime;
class BulletObject:public SphereObject
{
public:
	BulletObject()
	{

	}
};
class LightBullet :public BulletObject
{
public:
	LightBullet()
	{
		scale = glm::vec3(0.01f);
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("Bullet"));
		point_light_array.push_back(lightManager->GetPointLight("LightBullet"));
		rotate = atan(mouseDirection.y / mouseDirection.x);
		velcoity = glm::vec3(0, 0, 0);
		isPoint = true;
		isLight = true;
		mass = 0.05f;
		life = 10.0f;
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();
	}
	virtual void Update() override
	{
		life -= deltaTime;
		if (life <= 0.0f) Destory();
		position = position + velcoity * deltaTime;
		rotate = atan(velcoity.y / velcoity.x);
	}
	virtual void End() override
	{

	}
	virtual void Create() override
	{

	}
	virtual void Destory() override
	{
		isDestory = true;
	}
private:
	float life;
};
class CommonBullet :public BulletObject
{
public:
	CommonBullet()
	{
		scale = glm::vec3(0.01f);
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("Bullet"));
		rotate = atan(mouseDirection.y / mouseDirection.x);
		velcoity = glm::vec3(0, 0, 0);
		isPoint = true;
		life = 10.0f;
		mass = 0.05f;
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();
	}
	virtual void Update() override
	{
		life -= deltaTime;
		if (life <= 0.0f) Destory();
		position = position + velcoity * deltaTime;
		rotate = atan(velcoity.y / velcoity.x);
	}
	virtual void End() override
	{

	}
	virtual void Create() override
	{

	}
	virtual void Destory() override
	{
		isDestory = true;
	}
private:
	float life;
};