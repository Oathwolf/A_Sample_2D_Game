#pragma once
void BindObject(ObjectManager* objectManager)
{
	std::shared_ptr<Object> pobject = nullptr;

	pobject = std::make_shared<CommonObject>();
	pobject->SetEnityName("2DSphere");
	pobject->SetPosition(glm::vec3(1.0f, 0.0f, 0.0f));
	pobject->SetScale(glm::vec3(0.1f));
	pobject->SetName("Sphere");
	objectManager->InputObject("Sphere", pobject);

	pobject = std::make_shared<CommonObject>();
	pobject->SetEnityName("2DCube");
	pobject->SetPosition(glm::vec3(-1.0f, 0.0f, 0.0f));
	pobject->SetScale(glm::vec3(0.3f));
	pobject->SetName("Cube");
	objectManager->InputObject("Cube", pobject);

	pobject = std::make_shared<CommonObject>();
	pobject->SetEnityName("2DTriangle");
	pobject->SetPosition(glm::vec3(0.0f, 0.5f, 0.0f));
	pobject->SetScale(glm::vec3(0.2f));
	pobject->SetName("Triangle");
	objectManager->InputObject("Triangle", pobject);

	pobject = std::make_shared<CommonObject>();
	pobject->SetEnityName("Point");
	pobject->SetPosition(glm::vec3(1.0f, 1.0f, 0.0f));
	pobject->SetScale(glm::vec3(2.0f));
	objectManager->InputObject("SmallPoint", pobject);

	pobject = std::make_shared<CommonObject>();
	pobject->SetEnityName("Point");
	pobject->SetPosition(glm::vec3(1.0f, 1.0f, 0.0f));
	pobject->SetScale(glm::vec3(4.0f));
	objectManager->InputObject("BigPoint", pobject);
}