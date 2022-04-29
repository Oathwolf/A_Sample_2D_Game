#pragma once

extern LightManager* lightManager;

void BindLight()
{
	PointLight point_light;
	SpotLight spot_light;

	point_light.SetPointLight(1.0f, 2.0f, 4.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1,1,1 ));
	lightManager->InputPointLight("Point", point_light);
	point_light.SetPointLight(0.5f, 3.0f, 4.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(198.0f/ 255.0f, 105.0f / 255.0f, 0));
	lightManager->InputPointLight("LightBullet", point_light);
	point_light.SetPointLight(2.0f, 4.0f, 4.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1, 0, 0));
	lightManager->InputPointLight("LightGranade", point_light);
	point_light.SetPointLight(1.0f, 4.0f, 4.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f,1.0f, 1.0f));
	lightManager->InputPointLight("PlayerPointLight", point_light);
	point_light.SetPointLight(1.0f, 2.0f, 4.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1, 128.0f / 255.0f, 0));
	lightManager->InputPointLight("CollisionLight", point_light);
	point_light.SetPointLight(0.0f, 1.0f, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 70.0f/255.0f, 0.0f));
	lightManager->InputPointLight("GrenadeExplodeLight", point_light);

	spot_light.SetConstant(1.0f);
	spot_light.SetColor(glm::vec3(1.0f,1.0f,1.0f));
	spot_light.SetInCutOffByRadius(15);
	spot_light.SetOutCutOfffByFloat(20);
	lightManager->InputSpotLight("SpotLight", spot_light);

}