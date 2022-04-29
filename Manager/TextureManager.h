#pragma once
class TextureManager
{
public:
	unsigned int GetTexture(std::string str)
	{
		std::map<std::string, unsigned int>::iterator iter = manager.find(str);
		unsigned int texture = 0;
		if (iter != manager.end())
		{
			texture = iter->second;
		}
		else
		{
			std::cout << "GetTexture ERROR: NO FIND TEXTURE CALLED " << str << std::endl;
		}
		return texture;
	}
	void InputTextureByPass(std::string name, const char* path)
	{
		unsigned int texture = loadTexture(path);
		if (texture != 0)
		{
			manager.insert(std::make_pair(name, texture));
		}
		else
		{
			std::cout << "GetTextureArray ERROR: NO FIND TEXTURE CALLED " << name << std::endl;
		}
	}
	void InputTextureDirectly(std::string name, unsigned int texture)
	{
		manager.insert(std::make_pair(name, texture));
	}

	std::vector<unsigned int> GetTextureArray(std::vector<std::string> name)
	{
		std::vector<unsigned int> TextureArray;
		for (int i = 0;i < name.size();++i)
		{
			std::map<std::string, unsigned int>::iterator iter = manager.find(name[i]);
			if (iter != manager.end())
			{
				unsigned int texture = iter->second;
				TextureArray.push_back(texture);
			}
			else
			{
				printf("GetTextureArray ERROR: Texture %d is not find\n", i);
			}
		}
		return TextureArray;
	}

	static TextureManager* GetTextureManager()
	{
		static TextureManager instance;
		return &instance;
	}

private:

	TextureManager()
	{

	}

	std::map<std::string, unsigned int> manager;


};