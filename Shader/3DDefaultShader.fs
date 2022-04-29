#version 330 core
out vec4 FragColor;

struct PointLight{
	vec3 position;
	vec3 color;
	float constant;
	float linear;
	float quadratic;
};
struct SpotLight{
	float constant;
	float linear;
	float quadratic;
	float inCutOff;
	float outCutOff;
	vec3 direction;
	vec3 position;
	vec3 color;
};

#define MAX_POINT_LIGHT 128
#define MAX_SPOT_LIGHT 24

in vec2 TexCoords;
in vec3 Pos;

uniform int pointLightNum;
uniform int spotLightNum;

uniform sampler2D sprite;
uniform float shadow;
uniform sampler2D texture0;

uniform PointLight pointLights[MAX_POINT_LIGHT];
uniform SpotLight spotLights[MAX_SPOT_LIGHT];
void main()
{
 	vec4 real_texture_color = texture(texture0,TexCoords);
	if(real_texture_color.a<0.1) discard;
	vec3 texture_color = real_texture_color.rgb;
	float alpha = real_texture_color.a;
	float ambient = 0.4f;
	if(gl_FragCoord.x<shadow)
	{
		ambient = 0.0f;
		if(shadow - 900>gl_FragCoord.x)
		{
			ambient = 0.4f;
		}
	}
	vec3 light = vec3(0.0f,0.0f,0.0f);
	
	for(int i = 0;i<pointLightNum;i++)
	{
		float len = length(Pos-pointLights[i].position);
		light = light + pointLights[i].color/(pointLights[i].constant+len*pointLights[i].linear+len*len*pointLights[i].quadratic);
	}
	for(int i = 0;i<spotLightNum;i++)
	{
		float len = length(Pos-pointLights[i].position);
		vec3 dir = normalize(Pos - spotLights[i].position);
		float theta = dot(spotLights[i].direction,dir);
		if(theta>0.95)
		{
			light = light + spotLights[i].color/(spotLights[i].constant+len*spotLights[i].linear+len*len*spotLights[i].quadratic);
		}
	}
	FragColor =  vec4(texture_color*(light+ambient),alpha);
}