#pragma once
class VAOStruct
{
public:

	VAOStruct()
	{
		vao = 0;
		vbo = 0;
		index_num = 0;  
	}
	virtual void ReBuild() = 0;
	unsigned int GetVAO()
	{
		return vao;
	}
	void SetVAO(unsigned int vao)
	{
		this->vao = vao;
	}
	void SetIndexNum(int index_num)
	{
		this->index_num = index_num;
	}
	int GetIndexNum()
	{
		return index_num;
	}
	std::vector<float> GetVertexData()
	{
		return vertex_data;
	}
	void SetVertexData(std::vector<float> vertex)
	{
		vertex_data.clear();
		for (std::vector<float>::iterator it = vertex.begin();it != vertex.end();++it)
		{
			vertex_data.push_back(*it);
		}
	}
	std::vector<int> GetIndexData()
	{
		return index_data;
	}
	void SetIndexData(std::vector<int> index)
	{
		index_data.clear();
		for (std::vector<int>::iterator it = index.begin();it != index.end();it++)
		{
			index_data.push_back(*it);
		}
	}
protected:
	unsigned int vao;
	unsigned int vbo;
	std::vector<float> vertex_data;
	std::vector<int> index_data;
	int index_num;
};

class VAO_2D_Texture:public VAOStruct
{
public:
	VAO_2D_Texture()
	{
		ebo = 0;
	}
	virtual void ReBuild() override
	{
		unsigned int vertex_data_size = vertex_data.size();
		unsigned int index_data_size = index_data.size();
		index_num = index_data_size;

		float* vertex = new float[vertex_data_size]();
		unsigned int* index = new unsigned int[index_data_size]();

		for (int i = 0;i<vertex_data_size;i++)
		{
			vertex[i] = vertex_data[i];
		}
		for (int i = 0;i<index_data_size;i++)
		{
			index[i] = index_data[i];
		}


		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertex_data_size, vertex, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*index_data_size, index, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		delete []vertex;
		delete []index;

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
protected:
	unsigned int ebo;
};

class VAO_Point:public VAOStruct
{
public:
	VAO_Point()
	{
		ReBuild();
	}
	virtual void ReBuild() override
	{
		float BindPoint[]
		{
			0.0f,0.0f,0.0f
		};
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(BindPoint), BindPoint, GL_STATIC_DRAW);

		glBindVertexArray(vao);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	

private:

};