// 环境映射——反射天空盒
#version 420 core
layout (location = 0) in vec3 aPos;     //本地——顶点坐标 
layout (location = 1) in vec3 aNormal;  //本地——法线坐标

uniform mat4 model;             //模型矩阵
uniform mat4 view;              //观察矩阵
uniform mat4 projection;        //投影矩阵

out vec3 Normal;                //世界法线坐标
out vec3 FragPos;              //世界顶点坐标

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}