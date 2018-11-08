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

out vec2 exTexCoord;
out vec4 exColour;

void main(void)
{
	exTexCoord = uv0;
	exColour = colour;

	gl_Position = worldViewProj * vertex;
}