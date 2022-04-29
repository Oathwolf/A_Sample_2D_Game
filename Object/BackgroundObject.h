#pragma once
extern float shadow;
class BackgroundObjectType1:public CubeObject
{
public:
	BackgroundObjectType1()
	{
		scale = glm::vec3(2.0f);
		shader = shaderManager->GetShader("Background");
		texture_array.push_back(textureManager->GetTexture("Background1"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();
	}
	virtual void Update() override
	{
		position = glm::vec3(camera.Position.x, camera.Position.y, -1.0f);
	}
	virtual void End() override
	{

	}
	virtual void Create() override
	{

	}
	virtual void Destory() override
	{

	}
private:

};
class BackgroundObjectType2 :public CubeObject
{
public:
	BackgroundObjectType2()
	{
		scale = glm::vec3(2.0f);
		sub_position = glm::vec3(0.0f, 0.0f, 0.0f);
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("Background2"));
		
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();
	}
	virtual void Update() override
	{
		position = glm::vec3(camera.Position.x -24.0f, camera.Position.y, -0.9f);
		sub_position += glm::vec3(0.1f, 0.0f, 0.0f)*deltaTime;
		position += sub_position;
		if (position.x - camera.Position.x > -4 && position.x - camera.Position.x < 4)
		{
			shadow += 20.0f*deltaTime;
		}
	}
	virtual void End() override
	{

	}
	virtual void Create() override
	{

	}
	virtual void Destory() override
	{
		shadow = 0.0f;
	}
private:
	glm::vec3 sub_position;
};