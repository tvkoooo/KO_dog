// Direct3D11 HLSL 4.0

Texture2D texture0 : register(t0);
SamplerState textureSamplerState : register(s0);

struct VertOut
{
	float4 pos : SV_Position;
	float4 colour : COLOR;
	float2 texcoord0 : TEXCOORD;
};

float4 main(VertOut input) : SV_Target
{
	float4 colour = texture0.Sample(textureSamplerState, input.texcoord0) * input.colour;
	return colour;
}

