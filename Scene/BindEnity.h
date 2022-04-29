#pragma once
void BindEnity(
	VAOClass *vaoManager,
	ShaderManager *shaderManager,
	TextureManager *textureManager,
	LightManager *lightManager,
	EnityManager *enityManager)
{
	unsigned int texture1 = textureManager->GetTexture("floor");
	unsigned int texture2 = textureManager->GetTexture("test");
	unsigned int texture3 = textureManager->GetTexture("ex");
	std::shared_ptr<AbstractEnity> penity =
		std::make_shared<DefaultModelEnity>(vaoManager->GetVAO("2DDefaultSphere"), shaderManager->GetShader("3DDefaultShader"));
	penity->InputTexture(texture1);
	penity->InputTexture(texture1);
	enityManager->InputEnity("2DSphere", penity);

	penity =
		std::make_shared<DefaultModelEnity>(vaoManager->GetVAO("2DCube"), shaderManager->GetShader("3DDefaultShader"));
	penity->InputTexture(texture2);
	penity->InputTexture(texture2);
	enityManager->InputEnity("2DCube", penity);

	penity = std::make_shared<DefaultModelEnity>(vaoManager->GetVAO("2DTriangle"), shaderManager->GetShader("3DDefaultShader"));
	penity->InputTexture(texture3);
	penity->InputTexture(texture3);
	enityManager->InputEnity("2DTriangle", penity);

	penity = std::make_shared<PointEnity>(vaoManager->GetVAO("Point"), shaderManager->GetShader("PointShader"));
	penity->isLight = true;
	penity->isShadered = true;
	penity->InputPointLight(lightManager->GetPointLight("Point"));
	enityManager->InputEnity("Point", penity);
}