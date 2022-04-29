#pragma once
extern ShaderManager* shaderManager;

void BindShader()
{
	Shader Bind2DShader("../Shader/2DCubeShader.vs", "../Shader/2DCubeShader.fs");
	shaderManager->InputShaderDirectly("2DShader", Bind2DShader);
	Shader Default3DShader("../Shader/3DDefaultShader.vs", "../Shader/3DDefaultShader.fs");
	shaderManager->InputShaderDirectly("CommonShader", Default3DShader);
	Shader PointShader("../Shader/PointLight.vs", "../Shader/PointLight.fs");
	shaderManager->InputShaderDirectly("PointShader", PointShader);
	Shader SpriteShader("../Shader/SpriteShader.vs", "../Shader/SpriteShader.fs");
	shaderManager->InputShaderDirectly("SpriteShader", SpriteShader);
	Shader BackGroundShader("../Shader/BackGround1.vs", "../Shader/BackGround1.fs");
	shaderManager->InputShaderDirectly("Background", BackGroundShader);
	Shader BackgroundShader("../Shader/BackGround2.vs", "../Shader/BackGround2.fs");
	shaderManager->InputShaderDirectly("BackGround", BackgroundShader);
}