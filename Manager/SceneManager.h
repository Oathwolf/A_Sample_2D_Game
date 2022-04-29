#pragma once
class SceneManager
{
public:
	void InputScene(std::string name, Scene scene)
	{
		manager.insert(std::make_pair(name, scene));
	}
	Scene GetScene(std::string name)
	{
		std::map<std::string, Scene>::iterator iter = manager.find(name);
		Scene scene;
		if (iter != manager.end())
		{
			scene = iter->second;
		}
		else
		{
			std::cout << "GetScene ERROR: NO FIND SCENE CALLED " << name << std::endl;
		}
		return scene;
	}
	static SceneManager* GetSceneManager()
	{
		static SceneManager instance;
		return &instance;
	}
private:
	SceneManager()
	{

	}
	std::map<std::string, Scene> manager;
};