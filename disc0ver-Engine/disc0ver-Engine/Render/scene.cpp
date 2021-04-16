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

#include "scene.h"
 //========================================== test_master_scene ======================================

void disc0ver::test_master_scene::guiInit()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfw_InitForOpenGL(window.getGlfwWindowObject(), true);
	ImGui_ImplOpenGL3_Init("#version 420 core");
	ImGui::StyleColorsClassic();
}

void disc0ver::test_master_scene::cameraInit()
{
	camera.position_ = glm::vec3(0.0f, 0.0f, 3.0f);
	// 记得将其与窗口绑定
	window.setWindowCamera(&camera);
}

void disc0ver::test_master_scene::shaderInit()
{
	modelShader.init("shader/phong.vs", "shader/phong.fs");
	lightShader.init("shader/light_shader.vs", "shader/light_shader.fs");
	skyboxShader.init("shader/skybox_shader.vs", "shader/skybox_shader.fs");
}

void disc0ver::test_master_scene::modelInit()
{
	std::shared_ptr<disc0ver::IBaseModel> triangle(new disc0ver::triangleModel());
	std::shared_ptr<disc0ver::IBaseModel> triangle1(new disc0ver::triangleModel());
	std::shared_ptr<disc0ver::IBaseModel> rect(new disc0ver::rectangleModel());
	std::shared_ptr<disc0ver::IBaseModel> rect1(new disc0ver::rectangleModel());
	std::shared_ptr<disc0ver::IBaseModel> circle(new disc0ver::circleModel());
	std::shared_ptr<disc0ver::IBaseModel> circle1(new disc0ver::circleModel());
	std::shared_ptr<disc0ver::IBaseModel> cube(new disc0ver::cubeModel());
	std::shared_ptr<disc0ver::IBaseModel> cube1(new disc0ver::cubeModel());
	std::shared_ptr<disc0ver::IBaseModel> sphere(new disc0ver::sphereModel());
	std::shared_ptr<disc0ver::IBaseModel> sphere1(new disc0ver::sphereModel());
	std::shared_ptr<disc0ver::IBaseModel> sphere2(new disc0ver::sphereModel());
	std::shared_ptr<disc0ver::IBaseModel> sphere3(new disc0ver::sphereModel());
	std::shared_ptr<disc0ver::IBaseModel> cylinder(new disc0ver::cylinderModel());
	std::shared_ptr<disc0ver::IBaseModel> cylinder1(new disc0ver::cylinderModel());
	std::shared_ptr<disc0ver::IBaseModel> hc(new disc0ver::hollowCircleModel());
	std::shared_ptr<disc0ver::IBaseModel> hc1(new disc0ver::hollowCircleModel());
	std::shared_ptr<disc0ver::IBaseModel> ring(new disc0ver::ringModel());
	std::shared_ptr<disc0ver::IBaseModel> ring1(new disc0ver::ringModel());
	triangle->transform.position = disc0ver::Position(-5.0f, 0.0f, 2.0f);
	triangle->addTexture("triangle", "images/triangle.png");
	triangle1->transform.position = disc0ver::Position(-4.0f, 0.0f, 2.0f);
	triangle1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::emerald);
	rect->transform.position = disc0ver::Position(-3.0f, 0.0f, 2.0f);
	rect->addTexture("long", "images/long.png");
	rect1->transform.position = disc0ver::Position(-2.0f, 0.0f, 2.0f);
	rect1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::jade);
	circle->transform.position = disc0ver::Position(-1.0f, 0.0f, 2.0f);
	circle->addTexture("compass", "images/compass.png");
	circle1->transform.position = disc0ver::Position(0.0f, 0.0f, 2.0f);
	circle1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::obsidian);
	cube->transform.position = disc0ver::Position(1.0f, 0.0f, 2.0f);
	cube->addTexture("container2_diffuse", "images/container2_diffuse.png");
	cube1->transform.position = disc0ver::Position(2.0f, 0.0f, 2.0f);
	cube1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::pearl);

	sphere->transform.position = disc0ver::Position(4.0f, 0.0f, 2.0f);
	sphere->addTexture("earth", "images/planet/planet4.jpg");
	hc->transform.position = disc0ver::Position(4.0f, 0.0f, 2.0f);
	hc->addTexture("earth", "images/planet/planet4_ring.jpg");

	sphere1->transform.position = disc0ver::Position(6.0f, 0.0f, 2.0f);
	sphere1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::ruby);
	hc1->transform.position = disc0ver::Position(6.0f, 0.0f, 2.0f);
	hc1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::gold);

	sphere2->transform.position = disc0ver::Position(8.0f, 0.0f, 2.0f);
	sphere2->addTexture("earth", "images/planet/planet12.jpg");
	ring->transform.position = disc0ver::Position(8.0f, 0.0f, 2.0f);
	ring->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::silver);

	sphere3->transform.position = disc0ver::Position(10.0f, 0.0f, 2.0f);
	sphere3->addTexture("earth", "images/planet/planet13.jpg");
	ring1->transform.position = disc0ver::Position(10.0f, 0.0f, 2.0f);
	ring1->addTexture("earth", "images/planet/planet13_ring.jpg");

	cylinder->transform.position = disc0ver::Position(-6.0f, 0.0f, 2.0f);
	cylinder->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::turquoise);
	cylinder1->transform.position = disc0ver::Position(-7.0f, 0.0f, 2.0f);
	cylinder1->addTexture("wall", "images/wall.jpg");
	models.push_back(triangle);
	models.push_back(triangle1);
	models.push_back(rect);
	models.push_back(rect1);
	models.push_back(circle);
	models.push_back(circle1);
	models.push_back(cube);
	models.push_back(cube1);
	models.push_back(sphere);
	models.push_back(sphere1);
	models.push_back(sphere2);
	models.push_back(sphere3);
	models.push_back(hc);
	models.push_back(hc1);
	models.push_back(ring);
	models.push_back(ring1);
	models.push_back(cylinder);
	models.push_back(cylinder1);
	for (int i = 0; i < 24; i++)
	{
		std::shared_ptr< disc0ver::IBaseModel> s(new disc0ver::sphereModel());
		s->transform.position = disc0ver::Position(-12 + i, 0.0f, 4.0f);
		int idx = rand() % 13 + 1;
		s->addTexture("earth", std::string("images/planet/planet") + std::to_string(idx) + ".jpg");
		models.push_back(s);
	}
	try
	{
		std::shared_ptr<disc0ver::IBaseModel> model1(new disc0ver::STLModel("models/stlModels/github-skyline/leo6033-2020.stl"));
		std::shared_ptr<disc0ver::IBaseModel> model2(new disc0ver::Model("models/objModels/Marry/Marry.obj"));
		std::shared_ptr<disc0ver::IBaseModel> model3(new disc0ver::Model("models/objModels/Nanosuit/nanosuit.obj"));
		model3->transform.position = disc0ver::Position(1.0f, 0.0f, 0.0f);
		models.push_back(model1);
		models.push_back(model2);
		models.push_back(model3);
	}
	catch (const char* msg)
	{
		std::cerr << msg << '\n' << std::endl;
	}
}

void disc0ver::test_master_scene::lightInit()
{
	dirLight = {
		disc0ver::DirLight(glm::vec3(-0.2f, -1.0f, -0.3f), glm::vec3(0.05f, 0.05f, 0.05f), glm::vec3(0.4f, 0.4f, 0.4f), glm::vec3(0.5f, 0.5f, 0.5f)),
	};

	glm::vec3 pointLightPositions[] = {
		glm::vec3(8.0f,1.0f,0.0f),
		glm::vec3(2.0f,1.0f,0.0f),
		glm::vec3(0.0f,1.0f,0.5f),
		glm::vec3(12.0f,1.0f,0.5f)
	};
	pointLights = {
		disc0ver::PointLight(pointLightPositions[0],glm::vec3(0.05f,0.05f,0.05f),glm::vec3(0.8f,0.8f,0.8f),glm::vec3(1.0f,1.0f,1.0f)),
		disc0ver::PointLight(pointLightPositions[1],glm::vec3(0.05f,0.05f,0.05f),glm::vec3(0.8f,0.8f,0.8f),glm::vec3(1.0f,1.0f,1.0f)),
		disc0ver::PointLight(pointLightPositions[2],glm::vec3(0.05f,0.05f,0.05f),glm::vec3(0.8f,0.8f,0.8f),glm::vec3(1.0f,1.0f,1.0f)),
		disc0ver::PointLight(pointLightPositions[3],glm::vec3(0.05f,0.05f,0.05f),glm::vec3(0.8f,0.8f,0.8f),glm::vec3(1.0f,1.0f,1.0f))
	};

	for (int i = 0; i < 4; i++)
	{
		std::shared_ptr<disc0ver::IBaseModel> pointLightModel = std::make_shared<disc0ver::sphereModel>();
		pointLightModel->transform.position = pointLightPositions[i];
		pointLightModel->transform.scale = disc0ver::Scale(0.2f, 0.2f, 0.2f);
		pointLightModels.push_back(pointLightModel);
	}

	spotLight = {
		disc0ver::SpotLight(camera.position_, camera.forward_, glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.3f, 0.3f, 0.3f)),
	};
}

void disc0ver::test_master_scene::skyboxInit()
{
	std::vector<std::string> skyboxTexturePaths = {
	"images/skybox/skybox1/right.jpg",
	"images/skybox/skybox1/left.jpg",
	"images/skybox/skybox1/top.jpg",
	"images/skybox/skybox1/bottom.jpg",
	"images/skybox/skybox1/front.jpg",
	"images/skybox/skybox1/back.jpg"
	};
	skybox.init(skyboxTexturePaths, false);
}

void disc0ver::test_master_scene::beforeRenderLoop()
{
	modelShader.use();
	disc0ver::setLightAllAttribute(modelShader, "dirLight", dirLight);
	disc0ver::setLightAllAttribute(modelShader, "pointLights", pointLights);
}

void disc0ver::test_master_scene::renderLoop()
{
	bool show_demo_window = true;
	//记录时间帧间隔
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	//开启深度测试
	glEnable(GL_DEPTH_TEST);

	while (!window.shouldClose()) {

		window.pollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			ImGui::Begin("Another Window", &show_demo_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				//glfwSetWindowShouldClose(window, true);
				glfwSetWindowShouldClose(window.getGlfwWindowObject(), true);
			if (ImGui::Button("new window"))
			{
				GLFWwindow* newwindow = glfwCreateWindow(800, 600, "new window", NULL, NULL);

			}
			ImGui::End();
		}
		ImGui::Render();

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		std::cout << deltaTime << '\n';

		window.processInput(deltaTime);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		modelShader.use();
		glm::mat4 projection = glm::perspective(glm::radians(camera.zoom_), (float)window.getWindowWidth() / (float)window.getWindowHeight(), 0.1f, 100.0f);
		modelShader.setMat4("projection", projection);

		glm::mat4 view = camera.GetViewMatrix();
		modelShader.setMat4("view", view);
		modelShader.setVec3("viewPos", camera.position_);
		for (auto& light : spotLight)
		{
			light.position = camera.position_;
			light.direction = camera.forward_;
		}
		disc0ver::setLightAllAttribute(modelShader, "spotLight", spotLight);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		for (auto& model : models)
		{
			modelShader.setMat4("model", model->transform.trans);
			model->draw(modelShader);
		}

		lightShader.use();
		lightShader.setMat4("view", view);
		lightShader.setMat4("projection", projection);
		for (auto& pointLightModel : pointLightModels)
		{
			lightShader.setMat4("model", pointLightModel->transform.trans);
			pointLightModel->draw(lightShader);
		}

		skyboxShader.use();
		skyboxShader.setMat4("view", glm::mat4(glm::mat3(view)));
		skyboxShader.setMat4("projection", projection);
		skybox.draw(skyboxShader);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.swapBuffers();
	}
}

void disc0ver::test_master_scene::afterRenderLoop()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
