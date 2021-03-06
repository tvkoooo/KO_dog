// Direct3D11 HLSL 4.0

cbuffer MatrixBuffer
{
    matrix worldViewProj;
};

struct VertOut
{
	float4 pos : SV_Position;
	float4 colour : COLOR;
	float2 texcoord0 : TEXCOORD;
};

// Vertex shader
VertOut main(float3 inPos : POSITION, float4 inColour : COLOR, float2 inTexCoord0 : TEXCOORD)
{
	VertOut output;

	output.pos = mul(worldViewProj, float4(inPos, 1.0));
	output.texcoord0 = inTexCoord0;
	output.colour = inColour;

	return output;
}
