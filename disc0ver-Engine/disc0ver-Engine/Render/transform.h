/*
 * @Description:
 * @Author: 妄想
 * @Email: long452a@163.com
 * @Date: 2020-10-02
 *
 * @Author: xiji
 * @Email: wncka@foxmail.com
 * @Date: 2021-4-14
 */

#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

#include "../math/DGM.h"

namespace disc0ver {

	class Transform {
	public:
		Transform() = default;
		Transform(Rotation rotation, Position position, Scale scale) : rotation(rotation), position(position), scale(scale), trans(glm::mat4(1.0)) {}
		glm::mat4 trans = glm::mat4(1.0f);
		// 计算变换矩阵
		void use();
		//private:
			//旋转 平移 缩放矩阵
		Rotation rotation = { 0.0f, 0.0f, 0.0f };
		Position position = { 0.0f, 0.0f, 0.0f };
		Scale scale = { 1.0f, 1.0f, 1.0f };
	private:
		Transform& operator =(const Transform& t) { return *this; }
	};
}

#endif // !TRANSFORM_H
