#pragma once
class Collision
{
public:
	Collision()
	{
		isCollision = false;
	}
	glm::vec3 GetPosition()
	{
		return position;
	}
	void SetPosition(glm::vec3 position)
	{
		this->position = position;
	}

	bool isCollision;
protected:
	glm::vec3 position;
};
class Collision_Point:public Collision
{
public:
	Collision_Point()
	{
		position = glm::vec3(0.0, 0.0, 0.0);
	}
};

class Collision_Sphere :public Collision
{
public:
	Collision_Sphere()
	{
		radius = 1.0f;
		position = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	void SetRadius(float radius)
	{
		this->radius = radius;
	}
	float GetRadius()
	{
		return radius;
	}
private:
	float radius;
};