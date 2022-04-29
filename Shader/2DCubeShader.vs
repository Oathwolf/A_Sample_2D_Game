#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoords;
out vec2 TexCoord;
out vec3 Pos;
void main()
{
	TexCoord = vec2(aTexCoords.x,aTexCoords.y);
	Pos = vec3(model*vec4(aPos,1.0f));
	gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);
}