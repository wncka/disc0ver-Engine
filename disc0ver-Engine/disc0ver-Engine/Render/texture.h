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
#include "..\math\DGM.h"

#include <glm/glm.hpp>

namespace disc0ver {

	// 纹理类型 目前支持 漫反射(环境光)贴图 镜面光贴图
	enum class TextureType 
	{
		DIFFUSE,
		SPECULAR
	};

	class Texture {
		/*纹理对象*/
	public:
		unsigned int texture;
		Texture() {};
		Texture(std::string textureName, const GLchar* texturePath, TextureType textureType = TextureType::DIFFUSE, bool flipVertically = true);
		void use(unsigned int ID);
		std::string getName() const { return textureName; }
		TextureType getType() const { return textureType; }
		std::string getTypeString() const
		{
			switch (textureType)
			{
			case disc0ver::TextureType::DIFFUSE:
				return "diffuse";
				break;
			case disc0ver::TextureType::SPECULAR:
				return "specular";
				break;
			default:
				break;
			}
		}
	private:
		std::string textureName;
		TextureType textureType;
	};

	class Material
	{
		/* 
			材质
			
			tips：
			(1) 它包含了很多属性 你可以仅仅设置自己需要的属性——只要和shader匹配即可
			(2) 对于各类型的贴图 它仅仅支持1张——对目前的学习来说 这应该足够了 如果你有自己的想法 可以在此基础上进行扩展 同时也要修改其它部分的代码...(看起来是个大工程orz)
		*/
	public:
		Material()
		{
			Ns = 0.0f;
			Ni = 0.0f;
			d = 0.0f;
			illum = 0;
		}

		// Material Name - 名称
		std::string name;
		// Ambient Color - 环境光
		Rgb Ka;
		// Diffuse Color - 漫反射
		Rgb Kd;
		// Specular Color - 镜面光
		Rgb Ks;
		// Specular Exponent - 镜面光反光度
		float Ns;
		// Optical Density - 光密度 又称 折射率
		float Ni;
		// Dissolve - 不透明度 1.0即完全不透明 0.0即完全透明
		float d;
		// Illumination - 光照模型 这个是在 https://en.wikipedia.org/wiki/Wavefront_.obj_file 看到的 目前来看应该没什么用
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