#pragma once
#include"ParticleObject.h"
class ParticleGenerator :public PointObject
{
public:
	ParticleGenerator()
	{

	}
	virtual void Start() override
	{
		isTexture = texture_array.size();
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
	virtual void Create() override
	{

	}
	virtual void Destory() override
	{
		isDestory = true;
	}
protected:
};

class GrenadeExplodeParticleGenerator :public ParticleGenerator
{
public:
	GrenadeExplodeParticleGenerator()
	{
		position = glm::vec3(0, 0, 0);

		isShadered = false;
		isLight = true;
		generate = true;
		life = 0.3f;
		point_light_array.push_back(lightManager->GetPointLight("GrenadeExplodeLight"));
	}
	virtual void Update() override
	{
		life -= deltaTime;
		if (generate)
		{
			isCreate = true;
			for (int i = 0;i < 7;++i)
			{
				std::shared_ptr<Object> pobject = std::make_shared<GrenadeExlodeParticle>();
				pobject->SetPosition(position);
				create_object_array.push_back(pobject);
			}
			generate = false;
		}
		if (life <= 0)
		{
			Destory();
		}
	}
private:
	float life;
	bool generate;
};