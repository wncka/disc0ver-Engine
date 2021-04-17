// 渲染天空盒的片段着色器
#version 420 core

out vec4 FragColor;

in vec3 TexCoord;

uniform samplerCube skybox;     //立方体贴图采样器

void main()
{
	FragColor = texture(skybox, TexCoord);
}