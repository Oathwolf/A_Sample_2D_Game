#pragma once
class ShaderManager
{
public:

	Shader GetShader(std::string str)
	{
		std::map<std::string, Shader>::iterator iter = manager.find(str);
		Shader shader;
		if (iter != manager.end())
		{
			shader = iter->second;
		}
		else
		{
			std::cout << "GetShader ERROR: NO FIND SHADER CALLED " << str << std::endl;
			std::cout << "THE DEFAULT SHADER WILL BE USED" << std::endl;
		}
		return shader;
	}
	void InputShader(std::string name, const char* vs_path, const char* fs_path, const char* gs_path)
	{
		Shader shader(vs_path, fs_path, gs_path);
		manager.insert(std::make_pair(name, shader));
	}
	void InputShader(std::string name, const char* vs_path, const char* fs_path)
	{
		Shader shader(vs_path, fs_path);
		manager.insert(std::make_pair(name, shader));
	}
	void InputShaderDirectly(std::string name, Shader shader)
	{
		manager.insert(std::make_pair(name, shader));
	}
	static ShaderManager* GetShaderManager()
	{
		static ShaderManager instacne;
		return &instacne;
	}

private:
	std::map<std::string, Shader> manager;
	ShaderManager()
	{

	}
};