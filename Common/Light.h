#pragma once

class PointLight
{
public:

	PointLight()
	{
		constant = 1.0f;
		linear = 0.0f;
		quadratic = 0.0f;
		position = glm::vec3(0.0f, 0.0f, 0.0f);
		color = glm::vec3(1.0f, 1.0f, 1.0f);
	}
	void SetConstant(float constant)
	{
		this->constant = constant;
	}
	float GetConstant()
	{
		return constant;
	}
	void SetLinear(float linear)
	{
		this->linear = linear;
	}
	float GetLinear()
	{
		return linear;
	}
	void SetQuadratic(float quadratic)
	{
		this->quadratic = quadratic;
	}
	float GetQuadratic()
	{
		return quadratic;
	}
	void SetPosition(glm::vec3 position)
	{
		this->position = position;
	}
	glm::vec3 GetPosition()
	{
		return position;
	}
	void SetColor(glm::vec3 color)
	{
		this->color = color;
	}
	glm::vec3 GetColor()
	{
		return color;
	}
	void SetPointLight(float constant, float linear, float quadratic, glm::vec3 position, glm::vec3 color)
	{
		this->constant = constant;
		this->linear = linear;
		this->quadratic = quadratic;
		this->position = position;
		this->color = color;
	}

private:
	float constant;
	float linear;
	float quadratic;
	glm::vec3 position;
	glm::vec3 color;
};

class SpotLight
{
public:

	SpotLight()
	{
		constant = 1.0f;
		linear = 0.0f;
		quadratic = 0.0f;
	}
	void SetConstant(float constant)
	{
		this->constant = constant;
	}
	float GetConstant()
	{
		return constant;
	}
	void SetLinear(float linear)
	{
		this->linear = linear;
	}
	float GetLinear()
	{
		return linear;
	}
	void SetQuadratic(float quadratic)
	{
		this->quadratic = quadratic;
	}
	float GetQuadratic()
	{
		return quadratic;
	}
	void SetInCutOffByFloat(float inCutOff)
	{
		this->inCutOff = inCutOff;
	}
	void SetInCutOffByRadius(float radius)
	{
		inCutOff = glm::cos(glm::radians(radius));
	}
	float GetInCutOff()
	{
		return inCutOff;
	}
	void SetOutCutOfffByFloat(float outCutOff)
	{
		this->outCutOff = outCutOff;
	}
	void SetOutCutOffByRadius(float radius)
	{
		outCutOff = glm::cos(glm::radians(radius));
	}
	float GetOutCutOff()
	{
		return outCutOff;
	}
	void SetDirection(glm::vec3 direction)
	{
		this->direction = direction;
	}
	glm::vec3 GetDirection()
	{
		return direction;
	}
	void SetPosition(glm::vec3 position)
	{
		this->position = position;
	}
	glm::vec3 GetPosition()
	{
		return position;
	}
	void SetColor(glm::vec3 color)
	{
		this->color = color;
	}
	glm::vec3 GetColor()
	{
		return color;
	}
	void SetSpotLight(float constant, float linear, float quadratic, 
		float inCutOff, float outCutOff, 
		glm::vec3 direction, glm::vec3 position, glm::vec3 color)
	{
		this->constant = constant;
		this->linear = linear;
		this->quadratic = quadratic;
		this->inCutOff = inCutOff;
		this->outCutOff = outCutOff;
		this->direction = direction;
		this->position = position;
		this->color = color;
	}

private:
	float constant;
	float linear;
	float quadratic;
	float inCutOff;
	float outCutOff;
	glm::vec3 direction;
	glm::vec3 position;
	glm::vec3 color;
};
