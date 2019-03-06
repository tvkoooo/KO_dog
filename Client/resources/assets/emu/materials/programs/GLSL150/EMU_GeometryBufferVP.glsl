#version 150 core

out gl_PerVertex
{
	vec4 gl_Position;
	float gl_PointSize;
	float gl_ClipDistance[1];
};

uniform mat4 worldViewProj;

in vec4 vertex;
in vec2 uv0;
in vec4 colour;

out vec2 outUV0;
out vec4 outColor;

void main(void)
{
	outUV0 = uv0;
	outColor = colour;

	gl_Position = worldViewProj * vertex;
}