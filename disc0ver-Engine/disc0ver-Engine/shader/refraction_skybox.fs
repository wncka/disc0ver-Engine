// 环境映射——单面折射天空盒
#version 420 core

out vec4 FragColor; 

in vec3 FragPos;        // 世界法线坐标
in vec3 Normal;         // 世界顶点坐标

uniform samplerCube skybox;     // 立方体贴图采样器
uniform vec3 viewPos;           // 相机观察坐标

void main()
{
    float ratio = 1.0/1.52;
    vec3 viewDir = normalize(FragPos - viewPos);
    vec3 refractDir = refract(viewDir, normalize(Normal), ratio);
    FragColor = vec4(texture(skybox, refractDir).rgb, 1.0);
}