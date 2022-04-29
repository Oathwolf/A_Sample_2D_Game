#pragma once
class SpriteManager
{

public:
	static SpriteManager* GetSpriteManager()
	{
		static SpriteManager instance;
		return &instance;
	}
	void InputSpriteArray(std::string name,SpriteArray sprite_array)
	{
		manager.insert(std::make_pair(name, sprite_array));
	}
	SpriteArray GetSpriteArray(std::string name)
	{
		SpriteArray sprite_array;
		std::map<std::string, SpriteArray>::iterator iter = manager.find(name);
		if (iter != manager.end())
		{
			sprite_array = iter->second;
		}
		else
		{
			std::cout << "GetSpriteArray ERROR:NO FIND SPRITE_ARRAY CALLED " << name << std::endl;
		}
		return sprite_array;
	}

private:
	SpriteManager()
	{

	}

	std::map<std::string, SpriteArray> manager;
};