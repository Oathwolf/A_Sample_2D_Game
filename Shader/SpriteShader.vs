#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexture;

out vec2 TexCoords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	TexCoords = aTexture;
	gl_Position = projection*view*model*vec4(aPos,1.0f);
}