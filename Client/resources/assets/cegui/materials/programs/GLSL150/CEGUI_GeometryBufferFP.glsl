#version 150 core

uniform sampler2D texture0;

in vec2 exTexCoord;
in vec4 exColour;

out vec4 fragColour;

void main(void)
{
   fragColour = texture(texture0, exTexCoord) * exColour;
}