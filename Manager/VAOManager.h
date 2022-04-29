#pragma once

class VAOManager
{
public:

	VAOData GetVAO(std::string str)
	{
		VAOData vao;
		std::map<std::string, VAOData>::iterator iter = manager.find(str);
		if (iter != manager.end())
		{
			vao = iter->second;
		} 
		else
		{
			std::cout << "GetVAO ERROR: NO FIND VAO CALLED " << str << std::endl;
		}
		return vao;
	}
	void InputVAO(std::string name,VAOData vao_struct)
	{
		manager.insert(std::make_pair(name, vao_struct));
	}

	static VAOManager* GetVAOManager()
	{
		static VAOManager instance;
		return &instance;
	}

private:

	VAOManager()
	{

	}
	std::map<std::string, VAOData> manager;
};