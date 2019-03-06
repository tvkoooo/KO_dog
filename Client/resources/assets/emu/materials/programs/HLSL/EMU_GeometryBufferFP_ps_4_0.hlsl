// Direct3D11 HLSL 4.0

Texture2D texture0 : register(t0);
Texture2D texture1 : register(t1);
SamplerState textureSamplerState0 : register(s0);
SamplerState textureSamplerState1 : register(s1);

struct VertOut
{
	float4 pos : SV_Position;
	float2 texcoord0 : TEXCOORD;
};

float4 main(VertOut input) : SV_Target
{
	float2 s_uv;

	// x_scale = 512 / 256
	// y_scale = 256 / 240
	s_uv.x = input.texcoord0.x / 2.0;
	s_uv.y = input.texcoord0.y / 1.0666667;

	float s_idx = texture1.Sample(textureSamplerState1, s_uv.xy).x;
	// index [0.0, 255.0]
	float index = floor(s_idx * 256.0);

	float2 v_idx;
	v_idx.x = fmod(index, 16.0) / 16.0;
	v_idx.y = index / 16.0 / 16.0;
	float4 tc = texture0.Sample(textureSamplerState0, v_idx.xy);

	return tc;
}

