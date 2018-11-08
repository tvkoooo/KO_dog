// Direct3D9 HLSL 1.0

float4 main(float4 colour : COLOR,
            float2 texCoord : TEXCOORD0,
            uniform sampler2D texture0 : TEXUNIT0) : COLOR
{
    return tex2D(texture0, texCoord) * colour;
}
