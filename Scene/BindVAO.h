#pragma once

extern VAOManager* vaoManager;
extern const float PI;

void Bind2DCube();
void Bind2DTriangle();
void Bind2DDefaultSphere();

void BindVAO()
{
	Bind2DCube();
	Bind2DTriangle();
	Bind2DDefaultSphere();
}

void Bind2DCube()
{
	
		VAOData vao_data;

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
		
		for (int i = 0;i < 20;++i)
		{
			vao_data.vertex_data.push_back(Bind2DCubeVertices[i]);
		}
		for (int i = 0;i < 6;++i)
		{
			vao_data.index_data.push_back(Bind2DCubeIndices[i]);
		}

		vaoManager->InputVAO("2DCube", vao_data);
	
}

void Bind2DTriangle()
{
	
		VAOData vao_data;
		float Bind2DTriangleVertices[] = {
			//position			//texture
			 0.0f, 1.0f, 0.0f,	0.5f,1.0f,
			 1.0f,-1.0f, 0.0f,	1.0f,0.0f,
			-1.0f,-1.0f, 0.0f,	0.0f,0.0f
		};
		unsigned int Bind2DTriangleIndices[] = {
			0,1,2
		};
		
		for (int i = 0;i < 15;i++)
		{
			vao_data.vertex_data.push_back(Bind2DTriangleVertices[i]);
		}
		for (int i = 0;i < 3;i++)
		{
			vao_data.index_data.push_back(Bind2DTriangleIndices[i]);
		}

		vaoManager->InputVAO("2DTriangle", vao_data);
}

void Bind2DDefaultSphere()
{
	
		const int part = 36;
		float radius = ((float)(360 / part)) / 180.0*PI;
		VAOData vao_data;
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
		unsigned int Bind2DDefaultSphereIndices[part * 3] = { 0 };
		for (int i = 0;i < part;++i)
		{
			int I = i + 1;
			if (I >= part)
			{
				I = 0;
			}
			Bind2DDefaultSphereIndices[i * 3] = i;
			Bind2DDefaultSphereIndices[i * 3 + 1] = I;
			Bind2DDefaultSphereIndices[i * 3 + 2] = part;
		}

		for (int i = 0;i < (part + 1) * 5;++i)
		{
			vao_data.vertex_data.push_back(Bind2DDefaultSphereVertices[i]);
		}
		for (int i = 0;i < part * 3;++i)
		{
			vao_data.index_data.push_back(Bind2DDefaultSphereIndices[i]);
		}
		vaoManager->InputVAO("2DDefaultSphere", vao_data);
}
