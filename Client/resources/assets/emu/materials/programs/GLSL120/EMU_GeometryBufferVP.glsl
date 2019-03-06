#version 120

uniform mat4 worldViewProj;

attribute vec4 vertex;
attribute vec2 uv0;
attribute vec4 colour;

varying vec2 outUV0;
varying vec4 outColor;

void main(void)
{
	outUV0 = uv0;
	outColor = colour;

	gl_Position = worldViewProj * vertex;
}