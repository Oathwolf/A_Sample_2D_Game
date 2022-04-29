#pragma once

#include"../Manager/VAOManager.h"
#include"../Manager/LightManager.h"
#include"../Manager/ShaderManager.h"
#include"../Manager/SpriteManager.h"
#include"../Manager/TextureManager.h"
#include"../Manager/RandomManager.h"

extern LightManager* lightManager;
extern ShaderManager* shaderManager;
extern TextureManager* textureManager;
extern SpriteManager* spriteManager;
extern RandomManager* randomManager;

extern glm::vec3 mouseDirection;
extern float shadow;
extern VAOManager* vaoManager;
extern GLFWwindow* window;

class Object
{
public:

	Object()
	{
		position = glm::vec3(0.0f, 0.0f, 0.0f);
		scale = glm::vec3(1.0f);
		rotate = 0.0f;
		isShadered = true;
		isLighted = true;
		isLight = false;
		isSprite = false; 
		isDestory = false;
		isCreate = false;
		isCreated = true;
		isSprite = false;
		isSphere = false;
		isPoint = false;
		isTexture = 0;
	}
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;
	virtual void Draw(glm::mat4 projection,glm::mat4 view,
		std::vector<PointLight>& pointLightArray,
		std::vector<SpotLight>& spotLightArray) = 0;
	virtual void Create() = 0;
	virtual void Destory() = 0;

	virtual void ObjectCollision()
	{

	}
	void InputTexture(unsigned int texture)
	{
		texture_array.push_back(texture);
		isTexture++;
	}
	void InputTexture(std::vector<unsigned int> texture)
	{
		for (std::vector<unsigned int>::iterator it = texture.begin();it != texture.end();++it)
		{
			texture_array.push_back(*it);
			isTexture++;
		}
	}
	void InputPointLight(PointLight point_light)
	{
		point_light.SetPosition(position);
		point_light_array.push_back(point_light);
	}
	void InputSpotLight(SpotLight spot_light)
	{
		spot_light.SetPosition(position);
		spot_light_array.push_back(spot_light);
	}
	std::vector<PointLight>* GetPointLightArray()
	{
		return &point_light_array;
	}
	std::vector<SpotLight>* GetSpotLightArray()
	{
		return &spot_light_array;
	}
	void SetShader(Shader shader)
	{
		this->shader = shader;
	}
	Shader GetShader()
	{
		return shader;
	}
	ObjectType GetObjectType()
	{
		return object_type;
	}
	glm::vec3 GetPosition()
	{
		return position;
	}
	void SetPosition(glm::vec3 position)
	{
		this->position = position;
	}
	glm::vec3 GetScale()
	{
		return scale;
	}
	void SetScale(glm::vec3 scale)
	{
		this->scale = scale;
	}
	float GetRotate()
	{
		return rotate;
	}
	void SetRotate(float rotate)
	{
		this->rotate = rotate;
	}
	glm::vec3 GetVelcoity()
	{
		return velcoity;
	}
	void SetVelcoity(glm::vec3 velcoity)
	{
		this->velcoity = velcoity;
	}
	bool GetIsDestory()
	{
		return isDestory;
	}
	bool GetIsCreate()
	{
		return isCreate;
	}
	void SetIsCreate(bool isCreate)
	{
		this->isCreate = isCreate;
	}
	bool GetIsLight()
	{
		return isLight;
	}
	void SetIsLight(bool isLight)
	{
		this->isLight = isLight;
	}
	bool GetIsShadered()
	{
		return isShadered;
	}
	void SetIsShadered(bool isShadered)
	{
		this->isShadered = isShadered;
	}
	std::vector<std::shared_ptr<Object>> GetCreateObjectArray()
	{
		return create_object_array;
	}
	void InputSpriteArray(SpriteArray sprite_array)
	{
		sprite.InputSpriteArray(sprite_array);
	}

	bool isPoint;
	bool isSphere;
	float radius = 0.0f;
	float mass;

protected:

	std::vector<std::shared_ptr<Object>> create_object_array;
	std::vector<unsigned int> texture_array;
	std::vector<PointLight> point_light_array;
	std::vector<SpotLight> spot_light_array;

	ObjectType object_type;

	Shader shader;
	SpriteComponent sprite;

	glm::vec3 position;
	glm::vec3 scale;
	float rotate;
	glm::vec3 velcoity;

	bool isDestory;
	bool isCreate;
	bool isCreated;
	bool isLight;
	bool isLighted;
	bool isShadered;
	bool isSprite;

	int isTexture;
	unsigned int sprite_texture;

	void ClearCreateObjectArray()
	{
		create_object_array.clear();
	}
	unsigned int GetSpriteTexture()
	{
		sprite_texture = sprite.GetCurrentTexture();
	}
};

class VAOObject :public Object
{
public:

	VAOObject()
	{

	}
	virtual void BuildObjectVAO() = 0;
	virtual void Draw(glm::mat4 projection, glm::mat4 view,
		std::vector<PointLight>& pointLightArray,
		std::vector<SpotLight>& spotLightArray) override
	{
		shader.use();
		if (isSprite)
		{
			shader.setInt("sprite", 0);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, sprite_texture);
		}
		if (isTexture)
		{
			int num = 0;
			if (isSprite) num = 1;
			unsigned int texture_size = isTexture;
			for (int i = 0+num;i < isTexture+num;++i)
			{
				shader.setInt("texture" + std::to_string(i), i);
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, texture_array[i]);
			}
		}
		if (isLighted)
		{
			for (int i = 0;i < pointLightArray.size();++i)
			{
				shader.setVec3("pointLights[" + std::to_string(i) + "].position", pointLightArray[i].GetPosition());
				shader.setVec3("pointLights[" + std::to_string(i) + "].color", pointLightArray[i].GetColor());
				shader.setFloat("pointLights[" + std::to_string(i) + "].constant", pointLightArray[i].GetConstant());
				shader.setFloat("pointLights[" + std::to_string(i) + "].linear", pointLightArray[i].GetLinear());
				shader.setFloat("pointLights[" + std::to_string(i) + "].quadratic", pointLightArray[i].GetQuadratic());
			}
			for (int i = 0;i < spotLightArray.size();++i)
			{
				shader.setVec3("spotLights[" + std::to_string(i) + "].direction", mouseDirection);
				//shader.setVec3("spotLights[" + std::to_string(i) + "].direction", spotLightArray[i].GetDirection());
				shader.setVec3("spotLights[" + std::to_string(i) + "].position", spotLightArray[i].GetPosition());
				shader.setVec3("spotLights[" + std::to_string(i) + "].color", spotLightArray[i].GetColor());
				shader.setFloat("spotLights[" + std::to_string(i) + "].constant", spotLightArray[i].GetConstant());
				shader.setFloat("spotLights[" + std::to_string(i) + "].linear", spotLightArray[i].GetLinear());
				shader.setFloat("spotLights[" + std::to_string(i) + "].quadratic", spotLightArray[i].GetQuadratic());
				shader.setFloat("spotLights[" + std::to_string(i) + "].inCutOff", spotLightArray[i].GetInCutOff());
				shader.setFloat("spotLights[" + std::to_string(i) + "].outCutOff", spotLightArray[i].GetOutCutOff());
			}
		}
		shader.setInt("pointLightNum", pointLightArray.size());
		shader.setInt("spotLightNum", spotLightArray.size());
		shader.setFloat("shadow", shadow);
		shader.setMat4("projection", projection);
		shader.setMat4("view", view);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, position);
		model = glm::rotate(model, rotate,glm::normalize(glm::vec3(0,0,1)));
		model = glm::scale(model,scale);
		shader.setMat4("model", model);
		glBindVertexArray(vao_struct.GetVAO());
		glDrawElements(GL_TRIANGLES, vao_struct.GetIndexNum(), GL_UNSIGNED_INT, 0);
	}

protected:
	VAO_2D_Texture vao_struct;
private:

};

class PointObject:public Object 
{
public:

	virtual void Draw(glm::mat4 projection, glm::mat4 view,
		std::vector<PointLight>& pointLightArray,
		std::vector<SpotLight>& spotLightArray) override
	{
		shader.use();
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model,position);
		shader.setMat4("model", model);
		glPointSize(scale.x);
		glBindVertexArray(vao_point.GetVAO());
		glDrawArrays(GL_POINTS, 0, 1);
	}

protected:

	VAO_Point vao_point;

private:

};

class CubeObject :public VAOObject
{
public:

	CubeObject()
	{
		BuildObjectVAO();
		position = glm::vec3(-1.0f, 0.0f, 0.0f);
		scale = glm::vec3(0.1f);
	}
	virtual void BuildObjectVAO() override final
	{
		VAOData vao_data = vaoManager->GetVAO("2DCube");
		vao_struct.SetVertexData(vao_data.vertex_data);
		vao_struct.SetIndexData(vao_data.index_data);
		vao_struct.ReBuild();
	}
private:
};

class SphereObject :public VAOObject
{
public:

	SphereObject()
	{
		BuildObjectVAO();
		position = glm::vec3(1.0f, 0.0f, 0.0f);
		scale = glm::vec3(0.3f);
	}
	virtual void BuildObjectVAO() override final
	{
		VAOData vao_data = vaoManager->GetVAO("2DDefaultSphere");
		vao_struct.SetVertexData(vao_data.vertex_data);
		vao_struct.SetIndexData(vao_data.index_data);
		vao_struct.ReBuild();
	}

private:
};

class TriangleObject :public VAOObject
{
public:
	TriangleObject()
	{
		BuildObjectVAO();
		position = glm::vec3(0.0f, 0.5f, 0.0f);
		scale = glm::vec3(0.2f);
	}
	virtual void Create() override
	{
		VAOData vao_data = vaoManager->GetVAO("2DTriangle");
		vao_struct.SetVertexData(vao_data.vertex_data);
		vao_struct.SetIndexData(vao_data.index_data);
		vao_struct.ReBuild();
	}
private:
};
