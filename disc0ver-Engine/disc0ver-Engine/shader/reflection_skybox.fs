// 环境映射——反射天空盒
#version 420 core

out vec4 FragColor; 

in vec3 FragPos;        // 世界法线坐标
in vec3 Normal;         // 世界顶点坐标

uniform samplerCube skybox;     // 立方体贴图采样器
uniform vec3 viewPos;           // 相机观察坐标

void main()
{
    vec3 viewDir = normalize(FragPos - viewPos);
    vec3 reflectDir = reflect(viewDir, normalize(Normal));
    FragColor = vec4(texture(skybox, reflectDir).rgb, 1.0);
}