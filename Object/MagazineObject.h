#pragma once
class MagazineObject :public SphereObject
{
public:
	MagazineObject()
	{

	}
private:
};

class CommonMagazine :public MagazineObject
{
public:
	CommonMagazine()
	{
		scale = glm::vec3(0.03f);
		shader = shaderManager->GetShader("CommonShader");
		texture_array.push_back(textureManager->GetTexture("Magazine"));
		texture_array.push_back(textureManager->GetTexture("Magazine"));
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

	}
	virtual void Create()override
	{

	}
	virtual void Destory() override
	{

	}
};