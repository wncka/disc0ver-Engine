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
	triangle->transform.position = disc0ver::Position(-5.0f, 1.0f, 2.0f);
	triangle->addTexture("triangle", "images/triangle.png");
	triangle1->transform.position = disc0ver::Position(-4.0f, 0.0f, 2.0f);
	triangle1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::emerald);
	rect->transform.position = disc0ver::Position(-3.0f, 1.0f, 2.0f);
	rect->addTexture("long", "images/long.png");
	rect1->transform.position = disc0ver::Position(-2.0f, 0.0f, 2.0f);
	rect1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::jade);
	circle->transform.position = disc0ver::Position(-1.0f, 1.0f, 2.0f);
	circle->addTexture("compass", "images/compass.png");
	circle1->transform.position = disc0ver::Position(0.0f, 0.0f, 2.0f);
	circle1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::obsidian);
	cube->transform.position = disc0ver::Position(1.0f, 1.0f, 2.0f);
	cube->addTexture("container2_diffuse", "images/container2_diffuse.png");
	cube1->transform.position = disc0ver::Position(2.0f, 0.0f, 2.0f);
	cube1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::pearl);

	sphere->transform.position = disc0ver::Position(4.0f, 1.0f, 2.0f);
	sphere->addTexture("earth", "images/planet/planet4.jpg");
	hc->transform.position = disc0ver::Position(4.0f, 1.0f, 2.0f);
	hc->addTexture("earth", "images/planet/planet4_ring.jpg");

	sphere1->transform.position = disc0ver::Position(6.0f, 0.0f, 2.0f);
	sphere1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::ruby);
	hc1->transform.position = disc0ver::Position(6.0f, 0.0f, 2.0f);
	hc1->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::gold);

	sphere2->transform.position = disc0ver::Position(8.0f, 0.0f, 2.0f);
	sphere2->addTexture("earth", "images/planet/planet12.jpg");
	ring->transform.position = disc0ver::Position(8.0f, 1.0f, 2.0f);
	ring->getMaterial()->setMaterial(disc0ver::DefaultMaterialType::silver);

	sphere3->transform.position = disc0ver::Position(10.0f, 0.0f, 2.0f);
	sphere3->addTexture("earth", "images/planet/planet13.jpg");
	ring1->transform.position = disc0ver::Position(10.0f, 0.0f, 2.0f);
	ring1->addTexture("earth", "images/planet/planet13_ring.jpg");

	cylinder->transform.position = disc0ver::Position(-6.0f, 1.0f, 2.0f);
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
		model1->transform.position = disc0ver::Position(1.0f, 1.0f, 0.0f);
		model2->transform.position = disc0ver::Position(1.0f, 1.0f, 0.0f);
		model3->transform.position = disc0ver::Position(1.0f, 1.0f, 0.0f);
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
	"images/skybox/skybox1/right.png",
	"images/skybox/skybox1/left.png",
	"images/skybox/skybox1/top.png",
	"images/skybox/skybox1/bottom.png",
	"images/skybox/skybox1/back.png",
	"images/skybox/skybox1/front.png"
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
	float lastFrame = glfwGetTime();

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
			model->transform.rotation = disc0ver::Rotation(sin(glfwGetTime()) * 360.0f, 0.0f, 0.0f);
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

//========================================== refractionSkyBoxScene ======================================

void disc0ver::refractionSkyBoxScene::guiInit()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfw_InitForOpenGL(window.getGlfwWindowObject(), true);
	ImGui_ImplOpenGL3_Init("#version 420 core");
	ImGui::StyleColorsClassic();
}

void disc0ver::refractionSkyBoxScene::cameraInit()
{
	camera.position_ = glm::vec3(0.0f, 0.0f, 3.0f);
	// 记得将其与窗口绑定
	window.setWindowCamera(&camera);
}

void disc0ver::refractionSkyBoxScene::shaderInit()
{
	modelShader.init("shader/refraction_skybox.vs", "shader/refraction_skybox.fs");
	//modelShader.init("shader/reflection_skybox.vs", "shader/reflection_skybox.fs");
	skyboxShader.init("shader/skybox_shader.vs", "shader/skybox_shader.fs");
}

void disc0ver::refractionSkyBoxScene::modelInit()
{
	//std::shared_ptr<disc0ver::IBaseModel> cube = std::make_shared<disc0ver::cubeModel>();
	//std::shared_ptr<disc0ver::IBaseModel> cube = std::make_shared<disc0ver::Model>("models/objModels/Nanosuit/nanosuit.obj");
	std::shared_ptr<disc0ver::IBaseModel> cube = std::make_shared<disc0ver::sphereModel>();
	models.push_back(cube);
}

void disc0ver::refractionSkyBoxScene::lightInit()
{
}

void disc0ver::refractionSkyBoxScene::skyboxInit()
{
	// 依据skybox文件夹的数量 生成多个skybox对象
	std::vector<std::string> skyboxTexturePaths = {
		"images/skybox/skybox1/right.png",
		"images/skybox/skybox1/left.png",
		"images/skybox/skybox1/top.png",
		"images/skybox/skybox1/bottom.png",
		"images/skybox/skybox1/back.png",
		"images/skybox/skybox1/front.png"
	};
	std::vector<int> idx(skyboxTexturePaths.size());
	for (int i = 0; i < idx.size(); i++)
		idx[i] = skyboxTexturePaths[i].rfind('1');
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < skyboxTexturePaths.size(); j++)
			skyboxTexturePaths[j][idx[j]] = '0' + i;
		skyboxs.emplace_back(skyboxTexturePaths, false);
	}
}

void disc0ver::refractionSkyBoxScene::beforeRenderLoop()
{
}

void disc0ver::refractionSkyBoxScene::renderLoop()
{
	bool show_demo_window = true;
	//记录时间帧间隔
	float deltaTime = 0.0f;
	float lastFrame = glfwGetTime();

	//开启深度测试
	glEnable(GL_DEPTH_TEST);

	//按时间间隔切换skybox
	unsigned int idx = 0;
	float switchTime = 10.0f;
	float curTime = 0.0f;

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

		curTime += deltaTime;
		std::cout << curTime << ' ' << skyboxs.size() << '\n';
		if (curTime > switchTime)
		{
			curTime = 0.0f;
			idx = (idx + 1) % skyboxs.size();
		}

		window.processInput(deltaTime);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		modelShader.use();
		glm::mat4 projection = glm::perspective(glm::radians(camera.zoom_), (float)window.getWindowWidth() / (float)window.getWindowHeight(), 0.1f, 100.0f);
		modelShader.setMat4("projection", projection);

		glm::mat4 view = camera.GetViewMatrix();
		modelShader.setMat4("view", view);
		modelShader.setVec3("viewPos", camera.position_);
		skyboxs[idx].getCubeMapTexture().use(0);
		modelShader.setInt("skybox", 0);
		for (auto& model : models)
		{
			modelShader.setMat4("model", model->transform.trans);
			model->draw(modelShader);
		}

		skyboxShader.use();
		skyboxShader.setMat4("view", glm::mat4(glm::mat3(view)));
		skyboxShader.setMat4("projection", projection);
		skyboxs[idx].draw(skyboxShader);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.swapBuffers();
	}
}

void disc0ver::refractionSkyBoxScene::afterRenderLoop()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}


//========================================== galaxyScene ======================================

void disc0ver::galaxyScene::guiInit()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfw_InitForOpenGL(window.getGlfwWindowObject(), true);
	ImGui_ImplOpenGL3_Init("#version 420 core");
	ImGui::StyleColorsClassic();
}

void disc0ver::galaxyScene::cameraInit()
{
	camera.position_ = glm::vec3(0.0f, 0.0f, 3.0f);
	// 记得将其与窗口绑定
	window.setWindowCamera(&camera);
}

void disc0ver::galaxyScene::shaderInit()
{
	modelShader.init("shader/phong.vs", "shader/phong.fs");
	skyboxShader.init("shader/skybox_shader.vs", "shader/skybox_shader.fs");
}

void disc0ver::galaxyScene::modelInit()
{
	std::shared_ptr<IBaseModel> sun = std::make_shared<sphereModel>();
	sun->addTexture("sun", "images/planet/planet6.jpg");
	std::shared_ptr<IBaseModel> earth = std::make_shared<sphereModel>();
	earth->transform.position = Position(5.0f, 0.0f, 0.0f);
	earth->addTexture("earth", "images/planet/planet1.jpg");
	std::shared_ptr<IBaseModel> moon = std::make_shared<sphereModel>();
	moon->transform.position = Position(2.0f, 0.0f, 0.0f);
	moon->addTexture("moon", "images/planet/planet4.jpg");

	models.push_back(sun);
	models.push_back(earth);
	models.push_back(moon);

	std::shared_ptr<SceneNode> sunNode = std::make_shared<SceneNode>(sun);
	std::shared_ptr<SceneNode> earthNode = std::make_shared<SceneNode>(earth);
	std::shared_ptr<SceneNode> moonNode = std::make_shared<SceneNode>(moon);

	sunNode->addChild(earthNode);
	earthNode->addChild(moonNode);
	sceneRootNode.addChild({ sunNode });
}

void disc0ver::galaxyScene::lightInit()
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

	spotLight = {
		disc0ver::SpotLight(camera.position_, camera.forward_, glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.3f, 0.3f, 0.3f)),
	};
}

void disc0ver::galaxyScene::skyboxInit()
{
	std::vector<std::string> skyboxTexturePaths = {
		"images/skybox/skybox2/right.png",
		"images/skybox/skybox2/left.png",
		"images/skybox/skybox2/top.png",
		"images/skybox/skybox2/bottom.png",
		"images/skybox/skybox2/back.png",
		"images/skybox/skybox2/front.png"
	};
	skybox.init(skyboxTexturePaths, false);
}

void disc0ver::galaxyScene::beforeRenderLoop()
{
	modelShader.use();
	disc0ver::setLightAllAttribute(modelShader, "dirLight", dirLight);
	disc0ver::setLightAllAttribute(modelShader, "pointLights", pointLights);
}

void disc0ver::galaxyScene::renderLoop()
{
	bool show_demo_window = true;
	//记录时间帧间隔
	float deltaTime = 0.0f;
	float lastFrame = glfwGetTime();

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
		float yRotation = glfwGetTime() * 120.0f;
		for (auto& model : models)
		{
			model->transform.rotation = Rotation(0.0f, yRotation, 0.0f);
		}
		sceneRootNode.updateMatrix();
		for (auto& model : models)
		{
			modelShader.setMat4("model", model->transform.trans);
			model->draw(modelShader);
		}

		skyboxShader.use();
		skyboxShader.setMat4("view", glm::mat4(glm::mat3(view)));
		skyboxShader.setMat4("projection", projection);
		skybox.draw(skyboxShader);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.swapBuffers();
	}
}

void disc0ver::galaxyScene::afterRenderLoop()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

//========================================== galaxyScene ======================================

void disc0ver::blockGuyAnimationScene::guiInit()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfw_InitForOpenGL(window.getGlfwWindowObject(), true);
	ImGui_ImplOpenGL3_Init("#version 420 core");
	ImGui::StyleColorsClassic();
}

void disc0ver::blockGuyAnimationScene::cameraInit()
{
	camera.position_ = glm::vec3(0.0f, 0.0f, 3.0f);
	// 记得将其与窗口绑定
	window.setWindowCamera(&camera);
}

void disc0ver::blockGuyAnimationScene::shaderInit()
{
	modelShader.init("shader/phong.vs", "shader/phong.fs");
	skyboxShader.init("shader/skybox_shader.vs", "shader/skybox_shader.fs");
}

void disc0ver::blockGuyAnimationScene::modelInit()
{
	std::shared_ptr<IBaseModel> waist = std::make_shared<cubeModel>();
	waist->transform.position = Position(0.0f, 3.0f, 0.0f);
	models.push_back(waist);
	namesToModelIndex["waist"] = models.size() - 1;

	std::shared_ptr<IBaseModel> torso = std::make_shared<cubeModel>();
	torso->transform.position = Position(0.0f, 2.0f, 0.0f);
	models.push_back(torso);
	namesToModelIndex["torso"] = models.size() - 1;

	std::shared_ptr<IBaseModel> neck = std::make_shared<cubeModel>();
	neck->transform.position = Position(0.0f, 1.0f, 0.0f);
	models.push_back(neck);
	namesToModelIndex["neck"] = models.size() - 1;

	std::shared_ptr<IBaseModel> head = std::make_shared<cubeModel>();
	head->transform.position = Position(0.0f, 1.0f, 0.0f);
	models.push_back(head);
	namesToModelIndex["head"] = models.size() - 1;

	std::shared_ptr<IBaseModel> leftArm = std::make_shared<cubeModel>();
	leftArm->transform.position = Position(-1.0f, 0.0f, 0.0f);
	models.push_back(leftArm);
	namesToModelIndex["leftArm"] = models.size() - 1;

	std::shared_ptr<IBaseModel> leftForearm = std::make_shared<cubeModel>();
	leftForearm->transform.position = Position(-1.0f, 0.0f, 0.0f);
	models.push_back(leftForearm);
	namesToModelIndex["leftForearm"] = models.size() - 1;

	std::shared_ptr<IBaseModel> leftHand = std::make_shared<cubeModel>();
	leftHand->transform.position = Position(-1.0f, 0.0f, 0.0f);
	models.push_back(leftHand);
	namesToModelIndex["leftHand"] = models.size() - 1;

	std::shared_ptr<IBaseModel> rightArm = std::make_shared<cubeModel>();
	rightArm->transform.position = Position(1.0f, 0.0f, 0.0f);
	models.push_back(rightArm);
	namesToModelIndex["rightArm"] = models.size() - 1;

	std::shared_ptr<IBaseModel> rightForearm = std::make_shared<cubeModel>();
	rightForearm->transform.position = Position(1.0f, 0.0f, 0.0f);
	models.push_back(rightForearm);
	namesToModelIndex["rightForearm"] = models.size() - 1;

	std::shared_ptr<IBaseModel> rightHand = std::make_shared<cubeModel>();
	rightHand->transform.position = Position(1.0f, 0.0f, 0.0f);
	models.push_back(rightHand);
	namesToModelIndex["rightHand"] = models.size() - 1;

	std::shared_ptr<IBaseModel> leftLeg = std::make_shared<cubeModel>();
	leftLeg->transform.position = Position(-1.0f, -1.0f, 0.0f);
	models.push_back(leftLeg);
	namesToModelIndex["leftLeg"] = models.size() - 1;

	std::shared_ptr<IBaseModel> leftCalf = std::make_shared<cubeModel>();
	leftCalf->transform.position = Position(0.0f, -1.0f, 0.0f);
	models.push_back(leftCalf);
	namesToModelIndex["leftCalf"] = models.size() - 1;

	std::shared_ptr<IBaseModel> leftFoot = std::make_shared<cubeModel>();
	leftFoot->transform.position = Position(0.0f, -1.0f, 0.0f);
	models.push_back(leftFoot);
	namesToModelIndex["leftFoot"] = models.size() - 1;

	std::shared_ptr<IBaseModel> rightLeg = std::make_shared<cubeModel>();
	rightLeg->transform.position = Position(1.0f, -1.0f, 0.0f);
	models.push_back(rightLeg);
	namesToModelIndex["rightLeg"] = models.size() - 1;

	std::shared_ptr<IBaseModel> rightCalf = std::make_shared<cubeModel>();
	rightCalf->transform.position = Position(0.0f, -1.0f, 0.0f);
	models.push_back(rightCalf);
	namesToModelIndex["rightCalf"] = models.size() - 1;

	std::shared_ptr<IBaseModel> rightFoot = std::make_shared<cubeModel>();
	rightFoot->transform.position = Position(0.0f, -1.0f, 0.0f);
	models.push_back(rightFoot);
	namesToModelIndex["rightFoot"] = models.size() - 1;

	for (auto& model : models)
	{
		model->getMaterial()->setMaterial(DefaultMaterialType::gold);
	}

	std::shared_ptr<SceneNode> waistNode = std::make_shared<SceneNode>(waist);
	std::shared_ptr<SceneNode> torsoNode = std::make_shared<SceneNode>(torso);
	std::shared_ptr<SceneNode> neckNode = std::make_shared<SceneNode>(neck);
	std::shared_ptr<SceneNode> headNode = std::make_shared<SceneNode>(head);
	std::shared_ptr<SceneNode> leftArmNode = std::make_shared<SceneNode>(leftArm);
	std::shared_ptr<SceneNode> leftForearmNode = std::make_shared<SceneNode>(leftForearm);
	std::shared_ptr<SceneNode> leftHandNode = std::make_shared<SceneNode>(leftHand);
	std::shared_ptr<SceneNode> rightArmNode = std::make_shared<SceneNode>(rightArm);
	std::shared_ptr<SceneNode> rightForearmNode = std::make_shared<SceneNode>(rightForearm);
	std::shared_ptr<SceneNode> rightHandNode = std::make_shared<SceneNode>(rightHand);
	std::shared_ptr<SceneNode> leftLegNode = std::make_shared<SceneNode>(leftLeg);
	std::shared_ptr<SceneNode> leftCalfNode = std::make_shared<SceneNode>(leftCalf);
	std::shared_ptr<SceneNode> leftFootNode = std::make_shared<SceneNode>(leftFoot);
	std::shared_ptr<SceneNode> rightLegNode = std::make_shared<SceneNode>(rightLeg);
	std::shared_ptr<SceneNode> rightCalfNode = std::make_shared<SceneNode>(rightCalf);
	std::shared_ptr<SceneNode> rightFootNode = std::make_shared<SceneNode>(rightFoot);

	sceneRootNode.addChild(waistNode);
	waistNode->addChild({ torsoNode,leftLegNode,rightLegNode });
	torsoNode->addChild({ neckNode,leftArmNode,rightArmNode });
	neckNode->addChild(headNode);
	leftArmNode->addChild(leftForearmNode);
	leftForearmNode->addChild(leftHandNode);
	rightArmNode->addChild(rightForearmNode);
	rightForearmNode->addChild(rightHandNode);
	leftLegNode->addChild(leftCalfNode);
	leftCalfNode->addChild(leftFootNode);
	rightLegNode->addChild(rightCalfNode);
	rightCalfNode->addChild(rightFootNode);
}

void disc0ver::blockGuyAnimationScene::lightInit()
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

	spotLight = {
		disc0ver::SpotLight(camera.position_, camera.forward_, glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.3f, 0.3f, 0.3f)),
	};
}

void disc0ver::blockGuyAnimationScene::skyboxInit()
{
	std::vector<std::string> skyboxTexturePaths = {
		"images/skybox/skybox1/right.png",
		"images/skybox/skybox1/left.png",
		"images/skybox/skybox1/top.png",
		"images/skybox/skybox1/bottom.png",
		"images/skybox/skybox1/back.png",
		"images/skybox/skybox1/front.png"
	};
	skybox.init(skyboxTexturePaths, false);
}

void disc0ver::blockGuyAnimationScene::beforeRenderLoop()
{
	modelShader.use();
	disc0ver::setLightAllAttribute(modelShader, "dirLight", dirLight);
	disc0ver::setLightAllAttribute(modelShader, "pointLights", pointLights);
}

void disc0ver::blockGuyAnimationScene::renderLoop()
{
	bool show_demo_window = true;
	//记录时间帧间隔
	float deltaTime = 0.0f;
	float lastFrame = glfwGetTime();

	//开启深度测试
	glEnable(GL_DEPTH_TEST);

	std::shared_ptr<IBaseModel> leftLeg = models[namesToModelIndex["leftLeg"]];
	std::shared_ptr<IBaseModel> rightLeg = models[namesToModelIndex["rightLeg"]];
	std::shared_ptr<IBaseModel> leftCalf = models[namesToModelIndex["leftCalf"]];
	std::shared_ptr<IBaseModel> rightCalf = models[namesToModelIndex["rightCalf"]];
	std::shared_ptr<IBaseModel> leftFoot = models[namesToModelIndex["leftFoot"]];
	std::shared_ptr<IBaseModel> rightFoot = models[namesToModelIndex["rightFoot"]];
	std::shared_ptr<IBaseModel> leftArm = models[namesToModelIndex["leftArm"]];
	std::shared_ptr<IBaseModel> rightArm = models[namesToModelIndex["rightArm"]];
	std::shared_ptr<IBaseModel> leftForearm = models[namesToModelIndex["leftForearm"]];
	std::shared_ptr<IBaseModel> rightForearm = models[namesToModelIndex["rightForearm"]];
	std::shared_ptr<IBaseModel> leftHand = models[namesToModelIndex["leftHand"]];
	std::shared_ptr<IBaseModel> rightHand = models[namesToModelIndex["rightHand"]];
	std::shared_ptr<IBaseModel> waist = models[namesToModelIndex["waist"]];
	std::shared_ptr<IBaseModel> torso = models[namesToModelIndex["torso"]];
	std::shared_ptr<IBaseModel> neck = models[namesToModelIndex["neck"]];
	std::shared_ptr<IBaseModel> head = models[namesToModelIndex["head"]];

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

		float c = glfwGetTime() * 2.5f;
		float adjust = abs(sin(c)) * 0.2f;
		float rotation = 60.0f;
		glm::mat4 initTrans = glm::mat4(1.0f);
		initTrans = glm::translate(initTrans, glm::vec3(0.0f, adjust, 0.0f));
		initTrans = glm::scale(initTrans, glm::vec3(0.2f, 0.2f, 0.2f));

		adjust = sin(c) * rotation;
		leftLeg->transform.rotation.x = adjust;
		rightLeg->transform.rotation.x = -adjust;

		adjust = sin(c + 0.1) * 0.4 * rotation;
		leftCalf->transform.rotation.x = -adjust;
		rightCalf->transform.rotation.x = adjust;

		adjust = sin(c + 0.1) * 0.4 * rotation;
		leftFoot->transform.rotation.x = -adjust;
		rightFoot->transform.rotation.x = adjust;

		adjust = sin(c) * 0.4 * rotation;
		leftArm->transform.rotation.z = adjust;
		rightArm->transform.rotation.z = adjust;

		adjust = sin(c + 0.1) * 0.4 * rotation;
		leftForearm->transform.rotation.z = adjust;
		rightForearm->transform.rotation.z = adjust;

		adjust = sin(c - 0.1) * 0.4 * rotation;
		leftHand->transform.rotation.z = adjust;
		rightHand->transform.rotation.z = adjust;

		adjust = sin(c) * 0.4 * rotation;
		waist->transform.rotation.y = adjust;

		adjust = sin(c) * 0.4 * rotation;
		torso->transform.rotation.y = adjust;

		adjust = sin(c + 0.25) * 0.4 * rotation;
		neck->transform.rotation.y = adjust;

		adjust = sin(c + 0.5) * 0.4 * rotation;
		head->transform.rotation.y = adjust;

		adjust = cos(c * 2) * 0.4 * rotation;
		head->transform.rotation.x = adjust;

		sceneRootNode.updateMatrix(initTrans);

		for (auto& model : models)
		{
			modelShader.setMat4("model", model->transform.trans);
			model->draw(modelShader);
		}

		skyboxShader.use();
		skyboxShader.setMat4("view", glm::mat4(glm::mat3(view)));
		skyboxShader.setMat4("projection", projection);
		skybox.draw(skyboxShader);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.swapBuffers();
	}
}

void disc0ver::blockGuyAnimationScene::afterRenderLoop()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
