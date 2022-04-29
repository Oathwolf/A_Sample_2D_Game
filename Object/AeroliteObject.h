#pragma once
class AeroliteObject :public SphereObject
{
public:
	AeroliteObject()
	{
		position = glm::vec3(1.0f, 0.0f, 0.0f);
		velcoity = glm::vec3(0.0f, 0.0f, 0.0f);
		scale = glm::vec3(0.1f);
		mass = 240.0f;
		radius = 0.1f;
		isSphere = true;
		shader = shaderManager->GetShader("CommonShader");
		//texture_array.push_back(textureManager->GetTexture("AeroliteType1"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();

	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
	}
	virtual void End()override
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
};

class BigAeroliteType1:public AeroliteObject
{
public:
	BigAeroliteType1()
	{
		position = glm::vec3(1, 0, 0);
		rotate = ((float)randomManager->GetRandomNum() / 100.0f)*360.0f;
		scale = glm::vec3(0.3f);
		mass = 500.0f;
		radius = 0.25f;
		isSphere = true;
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("AeroliteType1"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();

	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
	}
	virtual void End()override
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
};

class BigAeroliteType2 :public AeroliteObject
{
public:
	BigAeroliteType2()
	{
		position = glm::vec3(1, 0, 0);
		rotate = ((float)randomManager->GetRandomNum() / 100.0f)*360.0f;
		scale = glm::vec3(0.3f);
		mass = 500.0f;
		radius = 0.25f;
		isSphere = true;
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("AeroliteType2"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();

	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
	}
	virtual void End()override
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
};

class MiddleAeroliteType1 :public AeroliteObject
{
public:
	MiddleAeroliteType1()
	{
		position = glm::vec3(1, 0, 0);
		rotate = ((float)randomManager->GetRandomNum() / 100.0f)*360.0f;
		scale = glm::vec3(0.1f);
		mass = 50.0f;
		radius = 0.09f;
		isSphere = true;
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("AeroliteType1"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();

	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
	}
	virtual void End()override
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
};

class MiddleAeroliteType2 :public AeroliteObject

{
public:
	MiddleAeroliteType2()
	{
		position = glm::vec3(1, 0, 0);
		rotate = ((float)randomManager->GetRandomNum() / 100.0f)*360.0f;
		scale = glm::vec3(0.1f);
		mass = 50.0f;
		radius = 0.09f;
		isSphere = true;
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("AeroliteType2"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();

	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
	}
	virtual void End()override
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
};

class SmallAeroliteType1 :public AeroliteObject
{
public:
	SmallAeroliteType1()
	{
		position = glm::vec3(1, 0, 0);
		rotate = ((float)randomManager->GetRandomNum() / 100.0f)*360.0f;
		scale = glm::vec3(0.02f);
		mass = 5.0f;
		isPoint = true;
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("AeroliteType1"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();

	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
	}
	virtual void End()override
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
};

class SmallAeroliteType2 :public AeroliteObject
{
public:
	SmallAeroliteType2()
	{
		position = glm::vec3(1, 0, 0);
		rotate = ((float)randomManager->GetRandomNum() / 100.0f)*360.0f;
		scale = glm::vec3(0.02f);
		mass = 5.0f;
		isPoint = true;
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("AeroliteType2"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();

	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
	}
	virtual void End()override
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
};

class Enemy :public AeroliteObject
{
public:
	Enemy()
	{
		position = glm::vec3(1, 0, 0);
		scale = glm::vec3(0.1f);
		mass = 50.0f;
		radius = 0.09f;
		isSphere = true;
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("Enemy"));
	}
	virtual void Start() override
	{
		isTexture = texture_array.size();

	}
	virtual void Update() override
	{
		position += velcoity * deltaTime;
	}
	virtual void End()override
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
};