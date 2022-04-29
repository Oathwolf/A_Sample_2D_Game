#pragma once

extern SceneManager* sceneManager;
extern LightManager* lightManager;
extern ShaderManager* shaderManager;
extern TextureManager* textureManager;
extern SpriteManager* spriteManager;

void BindScene()
{
	Scene scene;

	std::shared_ptr<Object> pobject = nullptr;

	pobject = std::make_shared<PlayerObject>();
	scene.objectArray.push_back(pobject);

	for (int i = 0;i < 30;i++)
	{
		int rand_num = randomManager->GetRandomNum() % 6;
		glm::vec3 rand_posiiton = glm::vec3(0, 0, 0);
		rand_posiiton.x = ((float)randomManager->GetRandomNum() / 100.0f)*6.0f - 3.0f;
		rand_posiiton.y = ((float)randomManager->GetRandomNum() / 100.0f)*6.0f - 3.0f;
		rand_posiiton.z = 0.0f;
		switch (rand_num)
		{
		case 0:
			pobject = std::make_shared<BigAeroliteType1>();
			break;
		case 1:
			pobject = std::make_shared<BigAeroliteType2>();
			break;
		case 2:
			pobject = std::make_shared<MiddleAeroliteType1>();
			break;
		case 3:
			pobject = std::make_shared<MiddleAeroliteType2>();
			break;
		case 4:
			pobject = std::make_shared<SmallAeroliteType1>();
			break;
		case 5:
			pobject = std::make_shared<SmallAeroliteType2>();
			break;
		}
		pobject->SetPosition(rand_posiiton);
		scene.objectArray.push_back(pobject);
	}

	pobject = std::make_shared<BackgroundObjectType1>();
	scene.objectArray.push_back(pobject);

	pobject = std::make_shared<Enemy>();
	scene.objectArray.push_back(pobject);

	pobject = std::make_shared<BackgroundObjectType2>();
	scene.objectArray.push_back(pobject);


	sceneManager->InputScene("scene", scene);
}