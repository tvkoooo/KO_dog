// Direct3D9 HLSL 1.0

uniform float4x4 worldViewProj;

struct VS_OUT 
{
   float4 position : POSITION;
   float2 uv : TEXCOORD0;
   float4 colour : COLOR;
};
VS_OUT main(float4 position : POSITION,
            float2 uv : TEXCOORD0,
            float4 colour : COLOR)
{
    VS_OUT o;
    o.uv = uv;
    o.colour = colour;
    o.position = mul(worldViewProj, position);
    return o;
}
