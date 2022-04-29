#pragma once
class ParticleObject :public PointObject
{
public:
	ParticleObject()
	{

	}
	virtual void Start() override
	{

	}
	virtual void Update() override
	{

	}
	virtual void End() override
	{
		if (isCreate)
		{
			ClearCreateObjectArray();
			isCreate = false;
		}
	}
	virtual void Create()override
	{

	}
	virtual void Destory() override
	{
		isDestory = true;
	}
};

class GrenadeParticle :public ParticleObject
{
public:
	GrenadeParticle()
	{
		shader = shaderManager->GetShader("PointShader");
		position = glm::vec3(0, 1, 0);
		velcoity = glm::vec3(0, 0, 0);
		scale = glm::vec3(1.0f);
		life = 0.3f;
		point_light_array.push_back(lightManager->GetPointLight("Point"));
		isLight = true;
	}
	virtual void Update() override
	{
		life = life - deltaTime;
		if (life <= 0) Destory();
	}
	virtual void End() override
	{
		
	}
private:
	float life;
};

class GrenadeExlodeParticle:public ParticleObject
{
public:
	GrenadeExlodeParticle()
	{
		shader = shaderManager->GetShader("PointShader");
		position = glm::vec3(0, 0, 0);
		velcoity = randomManager->GetRandom2DDirection()*1.0f;
		scale = glm::vec3(3.0f);
		point_light_array.push_back(lightManager->GetPointLight("Point"));
		life = 3.0f;
		isLight = true;
		isPoint = true;
		mass = 0.1f;
	}
	virtual void Update() override
	{
		life = life - deltaTime;
		if (life <= 0.0f)
		{
			Destory();
		}
		position += velcoity * deltaTime;
	}
private:
	float life;
};
class FireParticle:public ParticleObject
{
public:
	FireParticle()
	{
		life = 0.05f;
		isShadered = false;
		isLight = true;
		velcoity = glm::vec3(0, 0, 0);
		point_light_array.push_back(lightManager->GetPointLight("LightBullet"));
	}
	virtual void Update()
	{
		life -= deltaTime;
		if (life <= 0.0f)
		{
			Destory();
		}
	}
private:
	float life;
};