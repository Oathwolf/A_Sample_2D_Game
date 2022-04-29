#pragma once

#include"Shader.h"
#include"Model.h"

class AbstractEnity
{
public:

	AbstractEnity(Shader shader):shader("../Shader/2DDefaultShader.vs", "../Shader/2DDefaultShader.fs")
	{
		attribute.position = glm::vec3(0.0f);
		attribute.rotate = glm::vec3(0.0f);
		attribute.scale = glm::vec3(1.0f);
		light_color = glm::vec3(0.0f);
		isShadered = true;
		isLighted = true;
		isLight = false;
		isTexture = 0;
		this->shader = shader;
	}
	virtual void Update() = 0;
	virtual void Draw(glm::mat4 projection,glm::mat4 view,
	    std::vector<PointLight>& pointLightArray,
		std::vector<SpotLight>& spotLightArray) = 0;
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
	void InputPointLight(PointLight pointLight)
	{
		pointLight.SetPosition(attribute.position);
		pointLight_array.push_back(pointLight);
	}
	void InputSpotLight(SpotLight spotLight)
	{
		spotLight.SetPosition(attribute.position);
		spotLight_array.push_back(spotLight);
	}
	glm::vec3 GetPosition()
	{
		return attribute.position;
	}
	void SetPosition(glm::vec3 position)
	{
		attribute.position = position;
	}
	glm::vec3 GetScale()
	{
		return attribute.scale;
	}
	void SetScale(glm::vec3 scale)
	{
		attribute.scale = scale;
	}
	glm::vec3 GetRotate()
	{
		return attribute.rotate;
	}
	void SetRotate(glm::vec3 rotate)
	{
		attribute.rotate = rotate;
	}
	Shader GetShader()
	{
		return shader;
	}
	glm::vec3 GetLightColor()
	{
		return light_color;
	}
	void SetLightColor(glm::vec3 color)
	{
		light_color = color;
	}
	std::vector<PointLight>* GetPointLightArray()
	{
		return &pointLight_array;
	}
	std::vector<SpotLight>* GetSpotLightArray()
	{
		return &spotLight_array;
	}
	bool isLight;
	bool isLighted;
	bool isShadered;
	int isTexture;

protected:
	std::vector<unsigned int> texture_array;
	std::vector<PointLight> pointLight_array;
	std::vector<SpotLight> spotLight_array;
	glm::vec3 light_color;
	EnityAttribute attribute;
	Shader shader;

private:
};

class DefaultModelEnity:public AbstractEnity
{
public:

	DefaultModelEnity(VAOStruct vao,Shader shader):AbstractEnity(shader)
	{
		this->vao = vao;
	}
	virtual void Update()
	{

	}
	virtual void Draw(glm::mat4 projection, glm::mat4 view,
		std::vector<PointLight>& pointLightArray,
		std::vector<SpotLight>& spotLightArray)
	{
		shader.use();
		if (isTexture)
		{
			unsigned int texture_size = isTexture;
			for (int i = 0;i < isTexture;++i)
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
				
				/*glm::vec3 position = pointLightArray[i].GetPosition();
				glm::vec3 color = pointLightArray[i].GetColor();
				printf("position[%d] x:%f y:%f z:%f  ", i, position.x, position.y, position.z);
				printf("color[%d] x:%f y:%f z:%f\n", i, color.x, color.y, color.z);*/
			}
			for (int i = 0;i < spotLightArray.size();++i)
			{
				shader.setVec3("spotLights[" + std::to_string(i) + "].direction", spotLightArray[i].GetDirection());
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

		shader.setMat4("projection", projection);
		shader.setMat4("view", view);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, attribute.position);
		model = glm::scale(model, attribute.scale);
		shader.setMat4("model", model);
		glBindVertexArray(vao.VAO);
		glDrawElements(GL_TRIANGLES, vao.index_num, GL_UNSIGNED_INT, 0);
	}
protected:
	VAOStruct vao;
private:
};

class PointEnity :public AbstractEnity
{
public:

	PointEnity(VAOStruct vao,Shader shader):AbstractEnity(shader)
	{
		this->vao = vao;
	}
	virtual void Update()
	{

	}
	virtual void Draw(glm::mat4 projection,glm::mat4 view, 
		std::vector<PointLight>& pointLightArray,
		std::vector<SpotLight>& spotLightArray)
	{
		shader.use();
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, attribute.position);
		shader.setMat4("model", model);
		glPointSize(attribute.scale.x);
		glBindVertexArray(vao.VAO);
		glDrawArrays(GL_POINTS, 0, 1);
	}
protected:
	VAOStruct vao;

private:

};

class ModelEnity :public AbstractEnity
{
public:

	ModelEnity(Model model,Shader shader):
		AbstractEnity(shader),
		model("")
	{
		this->model = model;
	}
	virtual void Update()
	{

	}
	virtual void Draw(glm::mat4 projection,glm::mat4 view,std::vector<PointLight>& pointLightArray)
	{
		shader.use();
		unsigned int texture_size = texture_array.size();
		for (int i = 0;i < texture_size;++i)
		{
			shader.setInt("texture" + std::to_string(i),i);
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, texture_array[i]);
		}
		shader.setMat4("projection", projection);
		shader.setMat4("view", view);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, attribute.position);
		model = glm::scale(model, attribute.scale);
		shader.setMat4("model", model);
		this->model.Draw(shader);
	}
protected:
	Model model;
private:
};

class EnityManager
{
public:
	
	void InputEnity(std::string name,std::shared_ptr<AbstractEnity> enity_point)
	{
		manager.insert(std::make_pair(name, enity_point));
	}
	std::shared_ptr<AbstractEnity> GetEnityPoint(std::string name)
	{
		std::map<std::string, std::shared_ptr<AbstractEnity>>::iterator iter = manager.find(name);
		std::shared_ptr<AbstractEnity> enity_point = nullptr;
		if (iter != manager.end())
		{
			enity_point = iter->second;
		}
		else
		{
			std::cout << "GetEnityPoint ERROR NO FIND ENITYPOINT CALLED " << name << std::endl;
		}
		return enity_point;
	}

	static EnityManager* GetEnityManager()
	{
		static EnityManager instance;
		return &instance;
	}

private:
	EnityManager()
	{

	}
	std::map<std::string, std::shared_ptr<AbstractEnity>> manager;
};
