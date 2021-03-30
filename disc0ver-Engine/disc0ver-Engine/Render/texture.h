/*
 * @Description:
 * @Author: 妄想
 * @Email: long452a@163.com
 * @Date: 2020-09-30
 */

#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glm/glm.hpp>

namespace disc0ver {
	class Texture {
		/*纹理对象*/
	public:
		unsigned int texture;
		Texture() {}
		Texture(std::string textureName, const GLchar* texturePath);
		void use(unsigned int ID);
		std::string getName() const { return textureName; }
	private:
		std::string textureName;
	};

	class Material
	{
		/* 材质 */
	public:
		Material()
		{
			name;
			Ns = 0.0f;
			Ni = 0.0f;
			d = 0.0f;
			illum = 0;
		}

		// Material Name - 名称
		std::string name;
		// Ambient Color - 环境光
		glm::vec3 Ka;
		// Diffuse Color - 漫反射
		glm::vec3 Kd;
		// Specular Color - 镜面光
		glm::vec3 Ks;
		// Specular Exponent - 镜面光反光度
		float Ns;
		// Optical Density
		float Ni;
		// Dissolve
		float d;
		// Illumination
		int illum;
		// Ambient Texture Map - 环境光贴图
		std::string map_Ka;
		// Diffuse Texture Map - 漫反射贴图
		std::string map_Kd;
		// Specular Texture Map - 镜面光贴图
		std::string map_Ks;
		// Specular Hightlight Map - 镜面光高光贴图
		std::string map_Ns;
		// Alpha Texture Map
		std::string map_d;
		// Bump Map	- 凹凸贴图
		std::string map_bump;
	};
}

#endif // !TEXTURE_H