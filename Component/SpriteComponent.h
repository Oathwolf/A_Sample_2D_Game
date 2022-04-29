#pragma once


class SpriteComponent
{
public:
	SpriteComponent()
	{
		texture = 0;
		current_frame = 0;
		frame_life = 0;
	}
	void Update()
	{
		frame_life = frame_life - 1;
		if (frame_life <= 0)
		{
			if (current_frame+1 < current_sprite.size())
			{
				current_frame = current_frame + 1;
			}
			else
			{
				current_frame = 0;
			}
			frame_life = current_sprite[current_frame].frame;
			texture = current_sprite[current_frame].texture;
		}

	}
	void InputSpriteArray(SpriteArray sprite_array)
	{
		this->sprite_array = sprite_array;
	}
	void TurnSprite(std::string name)
	{
		SpriteArray::iterator iter = sprite_array.find(name);
		if (iter != sprite_array.end())
		{
			current_sprite = iter->second;
		}
		else if (iter->second.empty())
		{
			std::cout << "TurnSprite ERROR: THE SPRITE_ARRAY IS EMPTY" << std::endl;
		}
		else
		{
			std::cout << "TurnSprite ERROR:NO FIND SPRITE CALLED: " << name << std::endl;
		}
		current_frame = 0;
	}
	unsigned int GetCurrentTexture()
	{
		return texture;
	}
private:
	SpriteArray sprite_array;
	Sprite current_sprite;
	unsigned int texture;
	int current_frame;
	int frame_life;
};