// 渲染天空盒的顶点着色器
#version 420 core
layout (location = 0) in vec3 aPos;     //本地——顶点坐标

out vec3 TexCoord;

uniform mat4 view;              //观察矩阵
uniform mat4 projection;        //投影矩阵

void main()
{
	TexCoord = aPos;
	gl_Position = projection * view * vec4(aPos, 1.0);
	gl_Position.z = gl_Position.w;
}