#pragma once

#include"CommonStruct.h"

const float PI = 3.1415926;

class VAOClass
{
public:
	
	void Draw2DCube()
	{
		VAOStruct vao = VAOManager.find("2DCube")->second;
		glBindVertexArray(vao.VAO);
		glDrawElements(GL_TRIANGLES, vao.index_num, GL_UNSIGNED_INT, 0);
	}
	void Draw2DTriangle()
	{
		VAOStruct vao = VAOManager.find("2DTriangle")->second;
		glBindVertexArray(vao.VAO);
		glDrawElements(GL_TRIANGLES, vao.index_num, GL_UNSIGNED_INT, 0);
	}
	VAOStruct GetVAO(std::string str)
	{
		VAOStruct vao;
		std::map<std::string, VAOStruct>::iterator iter = VAOManager.find(str);
		if (iter != VAOManager.end())
		{
			vao = iter->second;
		}
		else
		{
			std::cout << "GetVAO ERROR: NO FIND VAO CALLED " << str << std::endl;
			vao.index_num = 0;
			vao.VAO = 0;
		}
		return vao;
	}

	static VAOClass* GetVAOClass()
	{
		static VAOClass instance;
		return &instance;
	}

private:

	VAOClass() :
		Bind2DCubeVAO(0), Bind2DCubeVBO(0), Bind2DCubeEBO(0),
		Bind2DTriangleVAO(0), Bind2DTriangleVBO(0), Bind2DTriangleEBO(0),
		Bind2DDefaultSphereVAO(0), Bind2DDefaultSphereVBO(0), Bind2DDefaultSphereEBO(0)
	{
		Bind2DCube();
		Bind2DTriangle();
		Bind2DDefaultSphere();
		BindPoint();
	}

	std::map<std::string, VAOStruct> VAOManager;

	unsigned int Bind2DCubeVAO = 0;
	unsigned int Bind2DCubeVBO = 0;
	unsigned int Bind2DCubeEBO = 0;
	void Bind2DCube()
	{
		if (Bind2DCubeVAO == 0)
		{
			VAOStruct vao_struct;

			float Bind2DCubeVertices[] = {
				//position			//texture
				 1.0f,  1.0f, 0.0f,	1.0f, 1.0f,
				 1.0f, -1.0f, 0.0f,	1.0f, 0.0f,
				-1.0f, -1.0f, 0.0f,	0.0f, 0.0f,
				-1.0f,  1.0f, 0.0f, 0.0f, 1.0f
			};
			unsigned int Bind2DCubeIndices[] = {
				0,1,3,
				1,2,3
			};
			glGenVertexArrays(1,&Bind2DCubeVAO);
			glGenBuffers(1, &Bind2DCubeVBO);
			glGenBuffers(1, &Bind2DCubeEBO);
			glBindVertexArray(Bind2DCubeVAO);
			glBindBuffer(GL_ARRAY_BUFFER, Bind2DCubeVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Bind2DCubeVertices), Bind2DCubeVertices, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Bind2DCubeEBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Bind2DCubeIndices), Bind2DCubeIndices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			vao_struct.VAO = Bind2DCubeVAO;
			vao_struct.index_num = sizeof(Bind2DCubeIndices) / sizeof(unsigned int);
			VAOManager.insert(std::make_pair("2DCube", vao_struct));
		}
	}

	unsigned int Bind2DTriangleVAO;
	unsigned int Bind2DTriangleVBO;
	unsigned int Bind2DTriangleEBO;
	void Bind2DTriangle()
	{
		if (Bind2DTriangleVAO == 0)
		{
			VAOStruct vao_struct;
			float Bind2DTriangleVertices[] = {
				//position			//texture
				 0.0f, 1.0f, 0.0f,	0.5f,1.0f,
				 1.0f,-1.0f, 0.0f,	1.0f,0.0f,
				-1.0f,-1.0f, 0.0f,	0.0f,0.0f
			};
			unsigned int Bind2DTriangleIndices[] = {
				0,1,2
			};
			glGenVertexArrays(1, &Bind2DTriangleVAO);
			glGenBuffers(1, &Bind2DTriangleVBO);
			glGenBuffers(1, &Bind2DTriangleEBO);
			glBindVertexArray(Bind2DTriangleVAO);
			glBindBuffer(GL_ARRAY_BUFFER, Bind2DTriangleVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Bind2DTriangleVertices), Bind2DTriangleVertices, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Bind2DTriangleEBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Bind2DTriangleIndices), Bind2DTriangleIndices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
			vao_struct.VAO = Bind2DTriangleVAO;
			vao_struct.index_num = sizeof(Bind2DTriangleIndices) / sizeof(unsigned int);
			VAOManager.insert(std::make_pair("2DTriangle", vao_struct));
		}
	}

	unsigned int Bind2DDefaultSphereVAO;
	unsigned int Bind2DDefaultSphereVBO;
	unsigned int Bind2DDefaultSphereEBO;
	void Bind2DDefaultSphere()
	{
		if (Bind2DDefaultSphereVAO == 0)
		{
			const int part = 36;
			float radius = ((float)(360 / part)) / 180.0*PI;
			VAOStruct vao_struct;
			float Bind2DDefaultSphereVertices[(part + 1) * 5] = { 0.0 };
			int num = 0;
			for (int i = 0;i < part;++i)
			{
				num = i * 5;
				Bind2DDefaultSphereVertices[num] = cos(radius*i);
				Bind2DDefaultSphereVertices[num + 1] = sin(radius*i);
				Bind2DDefaultSphereVertices[num + 2] = 0.0f;
				Bind2DDefaultSphereVertices[num + 3] = 0.5f + 0.5*cos(radius*i);
				Bind2DDefaultSphereVertices[num + 4] = 0.5f + 0.5*sin(radius*i);
			}
			num = part * 5;
			Bind2DDefaultSphereVertices[num] = 0.0f;
			Bind2DDefaultSphereVertices[num + 1] = 0.0f;
			Bind2DDefaultSphereVertices[num + 2] = 0.0f;
			Bind2DDefaultSphereVertices[num + 3] = 0.5f;
			Bind2DDefaultSphereVertices[num + 4] = 0.5f;
			unsigned int Bind2DDefaultSphereIndices[part*3] = { 0 };
			for (int i = 0;i < part;++i)
			{
				int I = i+1;
				if (I >= part)
				{
					I = 0;
				}
				Bind2DDefaultSphereIndices[i * 3] = i;
				Bind2DDefaultSphereIndices[i * 3 + 1] = I;
				Bind2DDefaultSphereIndices[i * 3 + 2] = part;
			}
			glGenVertexArrays(1, &Bind2DDefaultSphereVAO);
			glGenBuffers(1, &Bind2DDefaultSphereVBO);
			glGenBuffers(1, &Bind2DDefaultSphereEBO);
			glBindVertexArray(Bind2DDefaultSphereVAO);
			glBindBuffer(GL_ARRAY_BUFFER, Bind2DDefaultSphereVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Bind2DDefaultSphereVertices), Bind2DDefaultSphereVertices, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,Bind2DDefaultSphereEBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Bind2DDefaultSphereIndices), Bind2DDefaultSphereIndices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			vao_struct.VAO = Bind2DDefaultSphereVAO;
			vao_struct.index_num = sizeof(Bind2DDefaultSphereIndices) / sizeof(unsigned int);
			VAOManager.insert(std::make_pair("2DDefaultSphere", vao_struct));
		}
	}

	unsigned int BindPointVAO = 0;
	unsigned int BindPointVBO = 0;
	void BindPoint()
	{
		if (BindPointVAO == 0)
		{
			VAOStruct vao_struct;
			float BindPoint[]
			{
				0.0f,0.0f,0.0f
			};
			glGenVertexArrays(1, &BindPointVAO);
			glGenBuffers(1, &BindPointVBO);
			glBindBuffer(GL_ARRAY_BUFFER, BindPointVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(BindPoint), BindPoint, GL_STATIC_DRAW);
			
			glBindVertexArray(BindPointVAO);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0));
			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
			vao_struct.VAO = BindPointVAO;
			vao_struct.index_num = 1;
			VAOManager.insert(std::make_pair("Point", vao_struct));
		}
	}

};
