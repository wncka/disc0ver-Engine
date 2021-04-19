#include "test_total.h"
#include "../render/scene.h"

int test_master_main() {

	//glfw初始化
	glfwInit();

	disc0ver::test_master_scene scene;
	scene.draw();
	glfwTerminate();

	return 0;
}
