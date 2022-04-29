#pragma once
extern SpriteManager* spriteManager;
void BindSprite()
{
	SpriteArray sprite_array;

	Sprite sprite;

	SpriteImage sprite_image;
	sprite_image.texture = loadTexture("../Sprite/PlayerFrontMove1.png");
	sprite_image.frame = 10;
	sprite.push_back(sprite_image);

	sprite_image.texture = loadTexture("../Sprite/PlayerFrontMove2.png");
	sprite_image.frame = 10;
	sprite.push_back(sprite_image);
	sprite_array.insert(std::make_pair("Front", sprite));
	sprite.clear();

	sprite_image.texture = loadTexture("../Sprite/PlayerMoveBack1.png");
	sprite_image.frame = 100;
	sprite.push_back(sprite_image);
	sprite_array.insert(std::make_pair("Back", sprite));
	sprite.clear();

	sprite_image.texture = loadTexture("../Sprite/PlayerMoveSprint.png");
	sprite_image.frame = 100;
	sprite.push_back(sprite_image);
	sprite_array.insert(std::make_pair("Sprint", sprite));
	sprite.clear();

	sprite_image.texture = loadTexture("../Sprite/PlayerMoveUp1.png");
	sprite_image.frame = 10;
	sprite.push_back(sprite_image);

	sprite_image.texture = loadTexture("../Sprite/PlayerMoveUp2.png");
	sprite_image.frame = 10;
	sprite.push_back(sprite_image);
	sprite_array.insert(std::make_pair("Up", sprite));
	sprite.clear();

	sprite_image.texture = loadTexture("../Sprite/Player.png");
	sprite_image.frame = 10;
	sprite.push_back(sprite_image);
	sprite_array.insert(std::make_pair("Common", sprite));

	spriteManager->InputSpriteArray("Player", sprite_array);
}