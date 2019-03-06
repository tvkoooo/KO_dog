// Direct3D9 HLSL 1.0

float4 main(float2 texCoord : TEXCOORD0,
            uniform sampler2D texture0 : TEXUNIT0,
			uniform sampler2D texture1 : TEXUNIT1) : COLOR
{
	float2 s_uv;

	// x_scale = 512 / 256
	// y_scale = 256 / 240
	s_uv.x = texCoord.x / 2.0;
	s_uv.y = texCoord.y / 1.0666667;

	float s_idx = tex2D(texture1, s_uv.xy).x;
	// index [0.0, 255.0]
	float index = floor(s_idx * 256.0);

	float2 v_idx;
	v_idx.x = fmod(index, 16.0) / 16.0;
	v_idx.y = index / 16.0 / 16.0;
	float4 tc = tex2D(texture0, v_idx.xy);

    return tc;
}
