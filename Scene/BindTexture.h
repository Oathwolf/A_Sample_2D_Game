#pragma once

extern TextureManager* textureManager;

void BindTexture()
{
	unsigned int texture = 0;
	texture = loadTexture("../Image/test.png");
	textureManager->InputTextureDirectly("test", texture);
	texture = loadTexture("../Image/walk.png");
	textureManager->InputTextureDirectly("floor", texture);
	texture = loadTexture("../Image/floor.png");
	textureManager->InputTextureDirectly("ex", texture);
	texture = loadTexture("../Image/Bullet.png");
	textureManager->InputTextureDirectly("Bullet", texture);
	texture = loadTexture("../Image/Magazine.png");
	textureManager->InputTextureDirectly("Magazine", texture);

	texture = loadTexture("../Image/AeroliteType1.png");
	textureManager->InputTextureDirectly("AeroliteType1", texture);

	unsigned int tex = loadTexture("../Image/AeroliteType2.png");
	textureManager->InputTextureDirectly("AeroliteType2", tex);

	texture = loadTexture("../Image/Player.png");
	textureManager->InputTextureDirectly("Player", texture);
	texture = loadTexture("../Image/Background1.png");
	textureManager->InputTextureDirectly("Background1", texture);
	texture = loadTexture("../Image/Background2.png");
	textureManager->InputTextureDirectly("Background2", texture);
	texture = loadTexture("../Image/Grenade.png");
	textureManager->InputTextureDirectly("Grenade", texture);

	texture = loadTexture("../Image/PlayerFrontMove2.png");
	textureManager->InputTextureDirectly("PlayerFrontMove", texture);
	texture = loadTexture("../Image/PlayerMoveBack1.png");
	textureManager->InputTextureDirectly("PlayerBackMove", texture);
	texture = loadTexture("../Image/PlayerMoveSprint.png");
	textureManager->InputTextureDirectly("PlayerSprintMove", texture);
	texture = loadTexture("../Image/PlayerMoveUp1.png");
	textureManager->InputTextureDirectly("PlayerUpMove", texture);

	texture = loadTexture("../Image/Enemy.png");
	textureManager->InputTextureDirectly("Enemy", texture);
}