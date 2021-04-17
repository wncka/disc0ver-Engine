/*
 * @Description:
 * @Author: 妄想
 * @Email: long452a@163.com
 * @Date: 2021-2-16
 *
 * @Author: xiji
 * @Email: wncka@foxmail.com
 * @Date: 2021-04-15
 */
#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "../render/shader.h"
#include "../render/graph.h"
#include "../render/camera.h"
#include "../engine/light/light.h"
#include "../engine/window/window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

#include <iostream>
#include <algorithm>

#include "../stb_image.h"

namespace disc0ver {

	class BaseScene
	{
	public:
		// 绘制整个场景
		void draw()
		{
			beforeRenderLoop();
			renderLoop();
			afterRenderLoop();
		}
		virtual ~BaseScene() = default;
	private:
		// gui初始化
		virtual void guiInit() = 0;
		// 相机初始化
		virtual void cameraInit() = 0;
		// 着色器初始化
		virtual void shaderInit() = 0;
		// 模型初始化
		virtual void modelInit() = 0;
		// 光源初始化
		virtual void lightInit() = 0;
		// 天空盒初始化
		virtual void skyboxInit() = 0;

		// 在渲染循环之前调用 一些永远不会变化的值可以在此处设置
		virtual void beforeRenderLoop() = 0;
		// 渲染循环
		virtual void renderLoop() = 0;
		// 在渲染循环结束后调用 可以用来回收一些资源
		virtual void afterRenderLoop() = 0;
	};

	class test_master_scene :public BaseScene
	{
	public:

		// 构造函数
		test_master_scene() :window(disc0ver::Window::getInstance())
		{
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				throw "Failed to initialize GLAD";
			}
			guiInit();
			cameraInit();
			shaderInit();
			modelInit();
			lightInit();
			skyboxInit();
		}
		~test_master_scene() {}

		// 窗口对象的引用
		disc0ver::Window& window;
		// FPS相机
		disc0ver::FPSCamera camera;
		// 着色器
		disc0ver::Shader modelShader;
		disc0ver::Shader lightShader;
		disc0ver::Shader skyboxShader;
		// 模型
		std::vector<std::shared_ptr<disc0ver::IBaseModel>> models;
		// 光源
		std::vector<disc0ver::DirLight> dirLight;
		std::vector<disc0ver::PointLight> pointLights;
		std::vector<disc0ver::SpotLight> spotLight;
		// 光源模型
		std::vector<std::shared_ptr<disc0ver::IBaseModel>> pointLightModels;
		// 天空盒
		disc0ver::skyBox skybox;
	private:
		void guiInit() override;
		void cameraInit() override;
		void shaderInit() override;
		void modelInit() override;
		void lightInit() override;
		void skyboxInit() override;
		void beforeRenderLoop() override;
		void renderLoop() override;
		void afterRenderLoop() override;
	};

	class refractionSkyBoxScene :public BaseScene
	{
	public:

		// 构造函数
		refractionSkyBoxScene() :window(disc0ver::Window::getInstance())
		{
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				throw "Failed to initialize GLAD";
			}
			guiInit();
			cameraInit();
			shaderInit();
			modelInit();
			lightInit();
			skyboxInit();
		}
		~refractionSkyBoxScene() {}

		// 窗口对象的引用
		disc0ver::Window& window;
		// FPS相机
		disc0ver::FPSCamera camera;
		// 着色器
		disc0ver::Shader modelShader;
		disc0ver::Shader skyboxShader;
		// 模型
		std::vector<std::shared_ptr<disc0ver::IBaseModel>> models;
		// 天空盒
		std::vector<disc0ver::skyBox> skyboxs;
	private:
		void guiInit() override;
		void cameraInit() override;
		void shaderInit() override;
		void modelInit() override;
		void lightInit() override;
		void skyboxInit() override;
		void beforeRenderLoop() override;
		void renderLoop() override;
		void afterRenderLoop() override;

	};

}
#endif
