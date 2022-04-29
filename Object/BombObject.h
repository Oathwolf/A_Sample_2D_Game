#pragma once
#include"ParticleObject.h"
#include"ParticleGenerator.h"
class BombObject:public SphereObject
{
public:
	BombObject()
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

	}
protected:
};

class CommonGrenade:public BombObject
{
public:
	CommonGrenade()
	{
		position = glm::vec3(0, 0, 0);
		scale = glm::vec3(0.01f);
		velcoity = mouseDirection * 2.0f;
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("Grenade"));
		rotate = atan(mouseDirection.y / mouseDirection.x);
		isPoint = true;
		mass = 2.0f;
		life = 1.0f;
		object_type = COMMON_GRENADE;
		shoot_time = 0.0f;
	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
		if (shoot_time == 0.0f)
		{
			std::shared_ptr<Object> pobject = std::make_shared<GrenadeParticle>();
			pobject->SetPosition(position);
			create_object_array.push_back(pobject);
			isCreate = true;
			shoot_time = 0.03f;
		}
		rotate = atan(velcoity.y / velcoity.x);
		life = life - deltaTime;
		if (life <= 0) Destory();

		if (shoot_time > 0.0f)
		{
			shoot_time -= deltaTime;
			if (shoot_time <= 0)
			{
				shoot_time = 0.0f;
			}
		}
	}
	virtual void Destory() override
	{
		Explode();
		isDestory = true;
		
	}
	void Explode()
	{
		std::shared_ptr<Object> pobject = std::make_shared<GrenadeExplodeParticleGenerator>();
		pobject->SetPosition(position);
		create_object_array.push_back(pobject);
		isCreate = true;
	}
private:
	float life;
	float shoot_time;
};