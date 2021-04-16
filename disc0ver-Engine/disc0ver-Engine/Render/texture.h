/*
 * @Description: 纹理和材质
 * @Author: 妄想
 * @Email: long452a@163.com
 * @Date: 2020-09-30
 *
 * @Author: xiji
 * @Email: wncka@foxmail.com
 * @Date: 2021-04-13
 */

#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "..\math\DGM.h"
#include <unordered_map>

#include <glm/glm.hpp>

namespace disc0ver {

	// 纹理类型 目前支持 漫反射(环境光)贴图 镜面光贴图
	enum class TextureType
	{
		DIFFUSE,
		SPECULAR
	};

	class Texture {
		/* 2D纹理对象 */
	public:
		unsigned int texture;
		Texture() :texture(0), textureType(TextureType::DIFFUSE) {}
		/*
			2D纹理对象构造函数
			参数一：该纹理的名称
			参数二：该纹理对应图片的路径
			参数三：该纹理对应的类型
			参数四：是否翻转图片y轴
		*/
		Texture(std::string textureName, const GLchar* texturePath, TextureType textureType = TextureType::DIFFUSE, bool flipVertically = true);
		Texture(std::string textureName, std::string texturePath, TextureType textureType = TextureType::DIFFUSE, bool flipVertically = true) :
			Texture(textureName, texturePath.c_str(), textureType, flipVertically) {}
		// 激活参数ID所对应的纹理单元 并把该纹理对象绑定到上面
		void use(unsigned int ID);
		// 获得纹理的名称
		std::string getName() const { return textureName; }
		// 获得纹理的类型——返回值为TextureType
		TextureType getType() const { return textureType; }

		// 获得纹理的类型——返回值为string
		static std::string getTypeString(TextureType textureType)
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

		std::string getTypeString() const
		{
			return getTypeString(textureType);
		}
	private:
		// 纹理图像文件路径到纹理对象的哈希表 保证每个纹理只被加载一次 从而节省资源(简单起见 就不回收资源了 即glDeleteTextures(1, &texture)操作)
		static std::unordered_map<std::string, Texture> textureHashTable;
		std::string textureName;
		TextureType textureType;
	};

	class cubeMapTexture {
		/* 立方体贴图 这里主要用来实现天空盒效果 */
	public:
		// 纹理ID
		unsigned int texture = 0;

		// 依据给定的路径数组构造立方体贴图(6张贴图路径按照 右 左 上 下 前 后 的顺序给出)
		void init(const std::vector<std::string>& texturePaths, bool flipVertically = true);

		// 依据给定的路径数组构造立方体贴图(6张贴图路径按照 右 左 上 下 前 后 的顺序给出)
		cubeMapTexture(const std::vector<std::string>& texturePaths, bool flipVertically = true)
		{
			init(texturePaths, flipVertically);
		}

		cubeMapTexture(const cubeMapTexture& cmTexture) = delete;

		cubeMapTexture& operator =(const cubeMapTexture& cmTexture) = delete;

		cubeMapTexture(cubeMapTexture&& cmTexture)noexcept
		{
			texture = cmTexture.texture;
			cmTexture.texture = 0;
		}

		cubeMapTexture& operator=(cubeMapTexture&& cmTexture)noexcept
		{
			texture = cmTexture.texture;
			cmTexture.texture = 0;
		}

		~cubeMapTexture()
		{
			glDeleteTextures(1, &texture);
		}
		// 激活参数ID所对应的纹理单元 并把该纹理对象绑定到上面
		void use(int ID);
	};

	enum class DefaultMaterialType
	{
		// 祖母绿
		emerald,
		// 玉
		jade,
		// 黑曜石
		obsidian,
		// 珍珠
		pearl,
		// 红宝石
		ruby,
		// 绿松石
		turquoise,
		// 黄铜
		brass,
		// 青铜
		bronze,
		// 铬
		chrome,
		// 铜
		copper,
		// 金
		gold,
		// 银
		silver,
		// 各种颜色的塑料
		black_plastic,
		cyan_plastic,
		green_plastic,
		red_plastic,
		white_plastic,
		yellow_plastic,
		// 各种颜色的橡胶
		black_rubber,
		cyan_rubber,
		green_rubber,
		red_rubber,
		white_rubber,
		yellow_rubber
	};

	class Material
	{
		/*
			材质

			tips：
			(1) 它包含了很多属性 你可以仅仅设置自己需要的属性——只要和shader匹配即可
			(2) 对于各类型的贴图 它仅仅支持1张——对目前的学习来说 这应该足够了 如果你有自己的想法 可以在此基础上进行扩展 同时也要修改其它部分的代码...(看起来是个大工程orz)
			(3) 虽然这里把环境光贴图和漫反射贴图分开了 不过在大多数情况下它们都是相同的——所以在shader中我们认为它们是相同的 如果你想要使用不同的贴图 那么也需要对shader进行更改
			(4) 我们为你准备了一些默认材质 详见 setMaterial 函数
		*/
	public:
		Material()
		{
			// Bronze
			Ka = Rgb(0.2125f, 0.1275f, 0.054f);
			Kd = Rgb(0.714f, 0.4284f, 0.18144f);
			Ks = Rgb(0.393548f, 0.271906f, 0.166721f);
			Ns = 0.2 * 128;
			Ni = 0.0;
			d = 0.0;
			illum = 0;
		}

		Material(const Material& m) :name(m.name), Ka(m.Ka), Kd(m.Kd), Ks(m.Ks), Ns(m.Ns), Ni(m.Ni), d(m.d), illum(m.illum),
			map_Ka(m.map_Ka), map_Kd(m.map_Kd), map_Ks(m.map_Ks), map_d(m.map_d), map_bump(m.map_bump) { }

		Material& operator=(const Material& m) = default;

		Material(Material&& m) noexcept :name(std::move(m.name)), Ka(m.Ka), Kd(m.Kd), Ks(m.Ks), Ns(m.Ns), Ni(m.Ni), d(m.d), illum(m.illum),
			map_Ka(std::move(m.map_Ka)), map_Kd(std::move(m.map_Kd)), map_Ks(std::move(m.map_Ks)), map_d(std::move(m.map_d)), map_bump(std::move(m.map_bump)) { }

		Material& operator=(Material&& m) noexcept
		{
			name = std::move(m.name);
			Ka = m.Ka;
			Kd = m.Kd;
			Ks = m.Ks;
			Ns = m.Ns;
			Ni = m.Ni;
			d = m.d;
			illum = m.illum;
			map_Ka = std::move(m.map_Ka);
			map_Kd = std::move(m.map_Kd);
			map_Ks = std::move(m.map_Ks);
			map_Ns = std::move(m.map_Ns);
			map_d = std::move(m.map_d);
			map_bump = std::move(m.map_bump);
			return *this;
		}

		void setMaterial(DefaultMaterialType materialType);

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
