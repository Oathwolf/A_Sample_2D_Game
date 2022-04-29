#pragma once
glm::vec3 CalCollision(float mass_a, float mass_b, glm::vec3 a, glm::vec3 b);
extern Camera camera;
class Scene
{
public:

	std::list<std::shared_ptr<Object>> objectArray;
	Scene()
	{
	}
	
	void Update(float deltaTime)
	{
		for (std::list<std::shared_ptr<Object>>::iterator it = objectArray.begin();it != objectArray.end();++it)
		{
			if ((*it)->isPoint)
			{
				pointObject.push_back((*it));
			}
			if ((*it)->isSphere)
			{
				sphereObject.push_back((*it));
			}
		}
		CollisionCheck();
		objectArray.remove_if([](std::shared_ptr<Object> object) {return object->GetIsDestory();});
		for (std::list<std::shared_ptr<Object>>::iterator it = objectArray.begin();it != objectArray.end();++it)
		{
			//objectArray.remove_if([](std::shared_ptr<Object> object){return object->GetIsDestory();});

			(*it)->Start();
			(*it)->Update();

			if ((*it)->GetIsCreate())
			{
				std::vector<std::shared_ptr<Object>> createObjectArray = (*it)->GetCreateObjectArray();
				for (std::vector<std::shared_ptr<Object>>::iterator create_it = createObjectArray.begin();create_it != createObjectArray.end();++create_it)
				{
					objectArray.push_back(*create_it);
				}
			}
			if (glm::length(camera.Position - (*it)->GetPosition()) > 10.0f)
			{
				(*it)->Destory();
			}
			(*it)->End();
		}
		SceneCreate();
		pointObject.clear();
		sphereObject.clear();
	}
	void Draw(const float SCR_WIDTH,const float SCR_HEIGHT)
	{ 
		glm::mat4 view = camera.GetViewMatrix();
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 10.0f);
		std::vector<PointLight> pointLightArray;
		std::vector<SpotLight> spotLightArray;
		for (std::list<std::shared_ptr<Object>>::iterator object_it = objectArray.begin();object_it != objectArray.end();++object_it)
		{
			if ((*object_it)->GetIsLight())
			{
				for (std::vector<PointLight>::iterator it = (*object_it)->GetPointLightArray()->begin();
					it != (*object_it)->GetPointLightArray()->end();it++)
				{
					it->SetPosition((*object_it)->GetPosition());
					pointLightArray.push_back(*it);
				}
				for (std::vector<SpotLight>::iterator it = (*object_it)->GetSpotLightArray()->begin();
					it != (*object_it)->GetSpotLightArray()->end();it++)
				{
					it->SetPosition((*object_it)->GetPosition());
					spotLightArray.push_back(*it);
				}
				
			}
		}
		int num = 0;
		for (std::list<std::shared_ptr<Object>>::iterator it = objectArray.begin();it != objectArray.end();++it)
		{
			if (!(*it)->GetIsShadered()) continue;
			(*it)->Draw(projection, view,pointLightArray,spotLightArray);
			num++;
		}
	}

	void CollisionCheck();

protected:
	std::vector<std::shared_ptr<Object>> pointObject;
	std::vector<std::shared_ptr<Object>> sphereObject;
private:

	void SceneCreate();

};

glm::vec3 CalCollision(float mass_a, float mass_b, glm::vec3 a, glm::vec3 b)
{
	return ((mass_a - mass_b)*a + 2.0f*mass_b*b) / (mass_a + mass_b);
}
void Scene::CollisionCheck()
{
	for (std::vector<std::shared_ptr<Object>>::iterator sphere_it = sphereObject.begin();sphere_it != sphereObject.end();++sphere_it)
	{
		for (std::vector<std::shared_ptr<Object>>::iterator sub_sphere_it = sphere_it + 1;sub_sphere_it != sphereObject.end();++sub_sphere_it)
		{
			glm::vec3 collision_direction = (*sphere_it)->GetPosition() - (*sub_sphere_it)->GetPosition();
			float len = glm::length(collision_direction);
			if (len < (*sphere_it)->radius + (*sub_sphere_it)->radius)
			{
				glm::vec3 vec_a = glm::normalize(collision_direction);
				glm::vec3 vec_b = glm::normalize(-vec_a);
				float speed_a = glm::length((*sphere_it)->GetVelcoity());
				float speed_b = glm::length((*sub_sphere_it)->GetVelcoity());
				float cos_a = 0.0f, cos_b = 0.0f;
				if (speed_a == 0.0f) cos_a = 1.0f;
				else cos_a = glm::dot(vec_a, glm::normalize((*sphere_it)->GetVelcoity()));
				if (speed_b == 0.0f) cos_b = 1.0f;
				else cos_b = glm::dot(vec_b, glm::normalize((*sub_sphere_it)->GetVelcoity()));
				glm::vec3 ac = speed_a * cos_a*vec_a;
				glm::vec3 bc = speed_b * cos_b*vec_b;
				glm::vec3 ar = (*sphere_it)->GetVelcoity() - ac;
				glm::vec3 br = (*sub_sphere_it)->GetVelcoity() - bc;
				glm::vec3 a = CalCollision((*sphere_it)->mass, (*sub_sphere_it)->mass, ac, bc);
				glm::vec3 b = CalCollision((*sub_sphere_it)->mass, (*sphere_it)->mass, bc, ac);
				(*sphere_it)->SetVelcoity(ar + a);
				(*sub_sphere_it)->SetVelcoity(br + b);
			}
		}
		for (std::vector<std::shared_ptr<Object>>::iterator point_it = pointObject.begin();point_it != pointObject.end();++point_it)
		{
			glm::vec3 collision_direction = (*sphere_it)->GetPosition() - (*point_it)->GetPosition();
			float len = glm::length(collision_direction);
			if (len < (*sphere_it)->radius)
			{
				glm::vec3 vec_a = glm::normalize(collision_direction);
				glm::vec3 vec_b = glm::normalize(-vec_a);
				float speed_a = glm::length((*sphere_it)->GetVelcoity());
				float speed_b = glm::length((*point_it)->GetVelcoity());
				float cos_a = 0.0f, cos_b = 0.0f;
				if (speed_a == 0.0f) cos_a = 1.0f;
				else cos_a = glm::dot(vec_a, glm::normalize((*sphere_it)->GetVelcoity()));
				if (speed_b == 0.0f) cos_b = 1.0f;
				else cos_b = glm::dot(vec_b, glm::normalize((*point_it)->GetVelcoity()));
				glm::vec3 ac = speed_a * cos_a*vec_a;
				glm::vec3 bc = speed_b * cos_b*vec_b;
				glm::vec3 ar = (*sphere_it)->GetVelcoity() - ac;
				glm::vec3 br = (*point_it)->GetVelcoity() - bc;
				glm::vec3 a = CalCollision((*sphere_it)->mass, (*point_it)->mass, ac, bc);
				glm::vec3 b = CalCollision((*point_it)->mass, (*sphere_it)->mass, bc, ac);
				(*sphere_it)->SetVelcoity(ar + a);
				(*point_it)->SetVelcoity((br + b)*0.4f);
			}
		}
	}
}

void Scene::SceneCreate()
{
	 
}