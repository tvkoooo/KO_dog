#version 150 core

// 16x16 palette
uniform sampler2D texture0;
uniform sampler2D texture1;

in vec2 outUV0;
in vec4 outColor;

out vec4 fragColour;

void main(void)
{
	vec2 s_uv;

	// x_scale = 512 / 256
	// y_scale = 256 / 240
	s_uv.x = outUV0.x / 2.0;
	s_uv.y = outUV0.y / 1.0666667;

	float s_idx = texture(texture1, s_uv.xy).x;
	// index [0.0, 255.0]
	float index = floor(s_idx * 256.0);

	vec2 v_idx;
	v_idx.x = mod(index, 16.0) / 16.0;
	v_idx.y = index / 16.0 / 16.0;
	vec4 tc = texture(texture0, v_idx.xy);

	fragColour = tc * outColor;
}