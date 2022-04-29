#pragma once
class RandomManager
{
public:

	static RandomManager* GetRandomManager()
	{
		static RandomManager instance;
		return &instance;
	}
	int GetRandomNum()
	{
		int num = random_array[point];
		point++;
		if (point >= 200) point = 0;
		return num;
	}
	glm::vec3 GetRandom2DDirection()
	{
		int num_a = GetRandomNum() - 50;
		int num_b = GetRandomNum() - 50;
		return glm::normalize(glm::vec3(num_a, num_b, 0.0f));
	}
private:
	RandomManager()
	{
		point = 0;
		BindRandomManager();
	}
	void BindRandomManager()
	{
		for (int i = 0;i < 200;i++)
		{
			random_array[i] = rand()%100;
		}
	}
	int point;
	int random_array[200];
};