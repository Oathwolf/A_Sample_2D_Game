#pragma once
class LightManager
{
public:

	static LightManager* GetLightManager()
	{
		static LightManager instance;
		return &instance;
	}

	void InputPointLight(std::string name, PointLight point_light)
	{
		pointLightManager.insert(std::make_pair(name, point_light));
	}
	void InputSpotLight(std::string name, SpotLight spot_light)
	{
		spotLightManager.insert(std::make_pair(name, spot_light));
	}
	PointLight GetPointLight(std::string name)
	{
		std::map<std::string, PointLight>::iterator iter = pointLightManager.find(name);
		PointLight point_light;
		if (iter != pointLightManager.end())
		{
			point_light = iter->second;
		}
		else
		{
			std::cout << "GetPointLight ERROR: NO FIND POINT_LIGHT CALLED " << name << std::endl;
		}
		return point_light;
	}
	SpotLight GetSpotLight(std::string name)
	{
		std::map<std::string, SpotLight>::iterator iter = spotLightManager.find(name);
		SpotLight spot_light;
		if (iter != spotLightManager.end())
		{
			spot_light = iter->second;
		}
		else
		{
			std::cout << "GetPointLight ERROR:NO FIND SPOT_LIGHT CALLED " << name << std::endl;
		}
		return spot_light;
	}
private:

	LightManager()
	{

	}
	std::map<std::string, PointLight> pointLightManager;
	std::map<std::string, SpotLight> spotLightManager;

};