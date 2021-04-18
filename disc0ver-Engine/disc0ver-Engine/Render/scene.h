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

	// 场景节点 主要用于定义场景中模型之间的父子关系
	// 从而帮助我们更好的设计动画效果
	class SceneNode
	{
	public:
		// 该场景节点对应的模型
		std::shared_ptr<IBaseModel> model;
		// 该场景节点的子节点
		std::vector<std::shared_ptr<SceneNode>> children;

		SceneNode() = default;
		SceneNode(const std::shared_ptr<IBaseModel>& m) :model(m) {}

		void addChild(const std::shared_ptr<SceneNode>& child)
		{
			children.push_back(child);
		}

		void addChild(const std::initializer_list<std::shared_ptr<SceneNode>>& childs)
		{
			for (auto& child : childs)
			{
				children.push_back(child);
			}
		}

		std::shared_ptr<SceneNode>& addChild(const std::shared_ptr<IBaseModel>& childModel)
		{
			std::shared_ptr<SceneNode> childNode = std::make_shared<SceneNode>(childModel);
			children.push_back(childNode);
			return children.back();
		}

		void updateMatrix(const glm::mat4& parrentMatrix = glm::mat4(1.0f))
		{
			model->transform.trans = parrentMatrix * model->transform.trans;
			for (auto& child : children)
			{
				child->updateMatrix(model->transform.trans);
			}
		}
	};

	// 场景根节点 用来管理场景节点 简化一些操作
	class SceneRootNode
	{
	public:
		std::vector<std::shared_ptr<SceneNode>> children;

		SceneRootNode() = default;

		SceneRootNode(const std::initializer_list<std::shared_ptr<SceneNode>>& nodes)
		{
			for (const auto& node : nodes)
			{
				children.push_back(node);
			}
		}

		void addChild(const std::shared_ptr<SceneNode>& node)
		{
			children.push_back(node);
		}

		void addChild(const std::initializer_list<std::shared_ptr<SceneNode>>& nodes)
		{
			for (const auto& node : nodes)
			{
				children.push_back(node);
			}
		}

		void updateMatrix(const glm::mat4& initMatrix = glm::mat4(1.0f))
		{
			for (auto& child : children)
			{
				child->updateMatrix(initMatrix);
			}
		}
	};

	// 基础场景类 定义场景的接口
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

	class galaxyScene :public BaseScene
	{
	public:
		// 构造函数
		galaxyScene() :window(disc0ver::Window::getInstance())
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
		~galaxyScene() {}

		// 窗口对象的引用
		disc0ver::Window& window;
		// FPS相机
		disc0ver::FPSCamera camera;
		// 着色器
		disc0ver::Shader modelShader;
		disc0ver::Shader skyboxShader;
		// 模型
		std::vector<std::shared_ptr<disc0ver::IBaseModel>> models;
		// 场景根节点 用来处理节点间的关系
		disc0ver::SceneRootNode sceneRootNode;
		// 光源
		std::vector<disc0ver::DirLight> dirLight;
		std::vector<disc0ver::PointLight> pointLights;
		std::vector<disc0ver::SpotLight> spotLight;
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

	class blockGuyAnimationScene :public BaseScene
	{
	public:
		// 构造函数
		blockGuyAnimationScene() :window(disc0ver::Window::getInstance())
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
		~blockGuyAnimationScene() {}

		// 窗口对象的引用
		disc0ver::Window& window;
		// FPS相机
		disc0ver::FPSCamera camera;
		// 着色器
		disc0ver::Shader modelShader;
		disc0ver::Shader skyboxShader;
		// 模型
		std::vector<std::shared_ptr<disc0ver::IBaseModel>> models;
		// 变量名称到模型数组下标的映射
		std::unordered_map<std::string, unsigned int> namesToModelIndex;
		// 场景根节点 用来处理节点间的关系
		disc0ver::SceneRootNode sceneRootNode;
		// 光源
		std::vector<disc0ver::DirLight> dirLight;
		std::vector<disc0ver::PointLight> pointLights;
		std::vector<disc0ver::SpotLight> spotLight;
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

}
#endif
