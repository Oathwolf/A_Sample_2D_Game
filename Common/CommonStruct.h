#pragma once
#include<iostream>

typedef struct SpriteImage
{
	unsigned int texture;
	int frame;
}SpriteImage;

typedef std::vector<SpriteImage> Sprite;

typedef std::map<std::string, Sprite> SpriteArray;

typedef struct  ShaderEnityAttribute
{
	glm::vec3 position;
	glm::vec3 rotate;
	glm::vec3 scale;
} EnityAttribute;

typedef struct VAOData
{
	bool isIndex = true;
	std::vector<float> vertex_data;
	std::vector<int> index_data;
}VAOData;

enum ObjectType
{
	BIG_AEROLITE_TYPE1,
	BIG_AEROLITE_TYPE2,
	MIDDLE_AEROLITE_TYPE1,
	MIDDLE_AEROLITE_TYPE2,
	SMALL_AEROLITE_TYPE1,
	SMALL_AEROLITE_TYPE2,
	DUST_TYPE1,
	DUST_TYPE2,
	BULLET,
	PLAYER,
	ENEMY_TYPE1,
	ENEMY_TYPE2,
	COMMON_MAGAZINE,
	COMMON_GRENADE
};
