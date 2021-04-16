/*
 * @Description:
 * @Author: 妄想
 * @Email: long452a@163.com
 * @Date: 2020-09-27
 *
 * @Author: xiji
 * @Email: wncka@foxmail.com
 * @Date: 2021-04-03
 */

#include "graph.h"

 //========================================== some functions ======================================

void disc0ver::scale(const std::vector<Mesh>& meshes, Transform& trans)
{
	/* 依据模型的坐标范围自动进行缩放 */
	float max_x = std::numeric_limits<float>::min();
	float min_x = std::numeric_limits<float>::max();
	float max_y = max_x, max_z = max_x;
	float min_y = min_x, min_z = min_x;

	for (const Mesh& mesh : meshes)
	{
		const std::vector<Vertex>& vertices = mesh.vertices;
		for (int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i].position.x > max_x) max_x = vertices[i].position.x;
			else if (vertices[i].position.x < min_x) min_x = vertices[i].position.x;

			if (vertices[i].position.y > max_y) max_y = vertices[i].position.y;
			else if (vertices[i].position.y < min_y) min_y = vertices[i].position.y;

			if (vertices[i].position.z > max_z) max_z = vertices[i].position.z;
			else if (vertices[i].position.z < min_z) min_z = vertices[i].position.z;
		}
	}
	if (max_x > min_x)
	{
		float  m_scale = 100;
		m_scale = m_scale < (1.0 / (max_x - min_x)) ? m_scale : (1.0 / (max_x - min_x));
		m_scale = m_scale < (1.0 / (max_y - min_y)) ? m_scale : (1.0 / (max_y - min_y));
		m_scale = m_scale < (1.0 / (max_z - min_z)) ? m_scale : (1.0 / (max_z - min_z));

		trans.scale = { m_scale,m_scale,m_scale };
	}
}

//========================================== triangleModel ======================================

std::vector<disc0ver::BaseMesh> disc0ver::triangleModel::meshes;

void disc0ver::triangleModel::draw(Shader& shader)
{
	/* 三角形模型——绘制 */
	transform.use();
	meshes[0].Draw(shader, textures, material);
}

void disc0ver::triangleModel::addTexture(std::string textureName, const GLchar* texturePath)
{
	/* 三角形模型——添加纹理 */
	textures.emplace_back(textureName, texturePath);
}

//========================================== rectangleModel ======================================

std::vector<disc0ver::BaseMesh> disc0ver::rectangleModel::meshes;

void disc0ver::rectangleModel::draw(Shader& shader)
{
	/* 矩形模型——绘制 */
	transform.use();
	meshes[0].Draw(shader, textures, material);
}

void disc0ver::rectangleModel::addTexture(std::string textureName, const GLchar* texturePath)
{
	/* 矩形模型——添加纹理 */
	textures.emplace_back(textureName, texturePath);
}


//========================================== circleModel ======================================

std::vector<disc0ver::BaseMesh> disc0ver::circleModel::meshes;

void disc0ver::circleModel::draw(Shader& shader)
{
	/* 圆形模型——绘制 */
	transform.use();
	// 圆形模型的索引数组的第一个值对应的点是 圆心 然后是其它点(按顺序连着一圈)
	// 所以我们要用GL_TRIANGLE_FAN模式进行绘制
	meshes[0].Draw(shader, textures, material, GL_TRIANGLE_FAN);
}

void disc0ver::circleModel::addTexture(std::string textureName, const GLchar* texturePath)
{
	/* 圆形模型——添加纹理 */
	textures.emplace_back(textureName, texturePath);
}

//========================================== hollowCircleModel ======================================

void disc0ver::hollowCircleModel::draw(Shader& shader)
{
	/* 圆环模型——绘制 */
	transform.use();
	meshes[0].Draw(shader, textures, material, GL_TRIANGLE_STRIP);
}

void disc0ver::hollowCircleModel::addTexture(std::string textureName, const GLchar* texturePath)
{
	/* 圆环模型——添加纹理 */
	textures.emplace_back(textureName, texturePath);
}

//========================================== cubeModel ======================================

std::vector<disc0ver::BaseMesh>disc0ver::cubeModel::meshes;

void disc0ver::cubeModel::draw(Shader& shader)
{
	/* 立方体模型——绘制 */
	transform.use();
	if (useCullFace)
		glEnable(GL_CULL_FACE);
	meshes[0].Draw(shader, textures, material);
	glDisable(GL_CULL_FACE);
}

void disc0ver::cubeModel::addTexture(std::string textureName, const GLchar* texturePath)
{
	/* 立方体模型——添加纹理 */
	textures.emplace_back(textureName, texturePath);
}


//========================================== cylinderModel ======================================

std::vector<disc0ver::BaseMesh>disc0ver::cylinderModel::meshes;

void disc0ver::cylinderModel::draw(Shader& shader)
{
	/* 圆柱模型——绘制 */
	transform.use();
	std::vector<Texture> emptyTextures;
	if (useCullFace)
		glEnable(GL_CULL_FACE);
	meshes[0].Draw(shader, emptyTextures, material, GL_TRIANGLE_FAN);
	meshes[1].Draw(shader, emptyTextures, material, GL_TRIANGLE_FAN);
	meshes[2].Draw(shader, textures, material, GL_TRIANGLE_STRIP);
	glDisable(GL_CULL_FACE);
}

void disc0ver::cylinderModel::addTexture(std::string textureName, const GLchar* texturePath)
{
	/* 圆柱模型——添加纹理 */
	textures.emplace_back(textureName, texturePath);
}



//========================================== sphereModel ======================================

std::vector<disc0ver::BaseMesh> disc0ver::sphereModel::meshes;

void disc0ver::sphereModel::draw(Shader& shader)
{
	/* 球体模型——绘制 */
	transform.use();
	if (useCullFace)
		glEnable(GL_CULL_FACE);
	meshes[0].Draw(shader, textures, material);
	glDisable(GL_CULL_FACE);
}

void disc0ver::sphereModel::addTexture(std::string textureName, const GLchar* texturePath)
{
	/* 球体模型——添加纹理 */
	textures.emplace_back(textureName, texturePath);
}

//========================================== ringModel ======================================

void disc0ver::ringModel::draw(Shader& shader)
{
	/* 球体模型——绘制 */
	transform.use();
	if (useCullFace)
		glEnable(GL_CULL_FACE);
	meshes[0].Draw(shader, textures, material);
	glDisable(GL_CULL_FACE);
}

void disc0ver::ringModel::addTexture(std::string textureName, const GLchar* texturePath)
{
	/* 球体模型——添加纹理 */
	textures.emplace_back(textureName, texturePath);
}

//========================================== STLModel ======================================

void disc0ver::STLModel::draw(Shader& shader)
{
	/* .stl Model 绘制 */
	transform.use();
	if (useCullFace)
		glEnable(GL_CULL_FACE);
	for (auto& mesh : meshes)
	{
		mesh.Draw(shader);
	}
	glDisable(GL_CULL_FACE);
}

void disc0ver::STLModel::loadModel(const std::string path)
{
	/*
		从指定路径加载模型文件(.stl)

		其格式大致为:

		solid stlmesh
		facet normal floatx floaty floatz
			outer loop
				vertex floatx floaty floatz
				vertex floatx floaty floatz
				vertex floatx floaty floatz
			endloop
		end facet
		facet......
		......
		end facet
		endsolid stlmesh

	*/
	std::cout << "Loading model......\n" << "Path: " << path << '\n' << std::endl;
	std::ifstream infile;
	std::string tmp_str;
	infile.open(path);

	if (!infile.is_open())
	{
		throw "Model file not found";
	}

	// 读取头 solid filename
	char line[256];
	infile.getline(line, sizeof(line));
	std::istringstream solid(line);
	solid >> tmp_str;
	assert(tmp_str == "solid");

	while (!infile.eof())
	{
		infile.getline(line, sizeof(line));
		float n1, n2, n3;
		float x, y, z;
		std::istringstream face(line);

		face >> tmp_str;
		if (tmp_str == "facet")
		{
			// 法线坐标
			face >> tmp_str >> n1 >> n2 >> n3;
			// outer loop
			infile.getline(line, sizeof(line));
			// 三个顶点坐标
			for (int i = 0; i < 3; i++)
			{
				infile.getline(line, sizeof(line));
				std::istringstream vertex(line);
				vertex >> tmp_str >> x >> y >> z;
				vertices.emplace_back(x, y, z, n1, n2, n3, 0.0f, 0.0f);
			}
			// end loop
			infile.getline(line, sizeof(line));
		}
		// end facet
		infile.getline(line, sizeof(line));
	}
}

//========================================== Model ======================================

void disc0ver::Model::draw(Shader& shader)
{
	/* .obj 模型绘制 */
	transform.use();
	if (useCullFace)
		glEnable(GL_CULL_FACE);
	for (auto& mesh : meshes)
	{
		mesh.Draw(shader);
	}
	glDisable(GL_CULL_FACE);
}

void disc0ver::Model::loadModel(const std::string path)
{
	/*
		.obj 加载模型文件(.obj)

		说一下比较常见的属性：

		# 开头的是注释行

		v(vertex) 开头的是顶点位置信息 后跟3个空格分隔的float值 代表xyz三维坐标

		vt(vertex texture) 开头的是顶点纹理信息 后跟2个空格分隔的float值 代表uv纹理坐标

		vn(vertex normal) 开头的是顶点法线信息 后跟3个空格分隔的float值 代表法线的xyz三维坐标

		f(face) 开头的是模型的三角面列表 后跟3组空格分隔的面顶点信息 每一组由三个/分割的int值组成 分别代表该点的v、vt、vn索引(注意 这个是从1开始的)
		要拿到具体信息的话需要依据索引从之前读取的v、vt、vn列表中取得

		mtllib(material library) 开头的是材质库 后跟.mtl文件的名称(可能会有多个 这个例子中只有1个)

		usemtl 后跟材质名称 你可以在.mtl文件中找到对应名称的材质信息
		usemtl指定了材质之后 以后的面都是使用这一材质 直到遇到下一个usemtl来指定新的材质

		o 对象名

		g 组名称

		s 光滑组 一般在f前出现

		.mtl文件：

		一个mtl文件可能定义了多个材质 每个材质以newmtl打头 比如 newmtl materialName1

		Ka 开头的是材质的环境颜色 后跟三个[0,1]的float值 代表rgb

		Kd 开头的是材质的漫反射颜色 同上

		Ks 开头的是材质的镜面反射颜色 同上

		Ns 开头的是Phong光照模型中静脉反射的高光系数 后跟1个float

		d 开头的是不透明度 后跟1个float 1.0代表完全不透明 Tr与它相反 可以认为Tr = 1.0 - d

		Ni 开头的是折射率 后跟1个float

		map_Ka 开头的是环境贴图 它通常和漫反射贴图相同

		map_Kd 开头的是漫反射贴图

		map_Ks 开头的是镜面光贴图

		map_Ns 开头的是镜面高光贴图

		map_d 开头的是透明度贴图

		map_bump 开头的是凹凸贴图

		如果你想了解更多信息 可以去看wiki： https://en.wikipedia.org/wiki/Wavefront_.obj_file

	*/
	std::cout << "Loading model......\n" << "Path: " << path << '\n' << std::endl;
	std::ifstream infile;
	std::string tmp_str;
	infile.open(path);

	if (!infile.is_open())
	{
		throw "Model file not found";
	}

	char line[256];
	std::vector<Position> v, vn;
	std::vector<glm::vec2> vt;
	std::vector<Material> materials;
	unsigned int Index[9];
	int flag = 0;
	std::string materialName;

	while (!infile.eof())
	{
		infile.getline(line, sizeof(line));
		float n1, n2, n3;
		float uvx, uvy;
		float x, y, z;
		std::istringstream ss(line);

		ss >> tmp_str;
		// 顶点位置坐标
		if (tmp_str == "v")
		{
			ss >> x >> y >> z;
			v.emplace_back(x, y, z);
		}
		// 顶点法线坐标
		else if (tmp_str == "vn")
		{
			ss >> n1 >> n2 >> n3;
			vn.emplace_back(n1, n2, n3);
		}
		// 顶点纹理坐标
		else if (tmp_str == "vt")
		{
			ss >> uvx >> uvy;
			vt.emplace_back(uvx, uvy);
		}
		else if (tmp_str == "f")
		{
			// TODO: 不同形式的 f 参数实现
			std::string s;
			int index = 0;
			while (ss >> s)
			{
				s = s + "/";
				while (s.find('/') != std::string::npos) {
					int pos = s.find('/');
					std::istringstream i(s.substr(0, pos));
					i >> Index[index++];
					s = s.substr(pos + 1, s.size());
				}
			}
			for (int i = 0; i < index; i += 3)
			{
				vertices.emplace_back(v[Index[i] - 1], vn[Index[i + 2] - 1], vt[Index[i + 1] - 1]);
			}
		}
		else if (tmp_str == "mtllib")
		{
			std::string mtPath;
			ss >> mtPath;
			if (path.find('/') != std::string::npos)
				mtPath = path.substr(0, path.find_last_of('/') + 1) + mtPath;
			loadMaterial(materials, mtPath);
		}
		else if (tmp_str == "usemtl")
		{
			ss >> materialName;
		}
		else if (tmp_str == "s")
		{
			flag = 1;
		}
		else if (tmp_str == "o")
		{
			if (flag == 1)
			{
				createMesh(materialName, materials);
				materialName.clear();
				flag = 0;
			}
		}
	}
	if (flag == 1)
		createMesh(materialName, materials);
}

void disc0ver::Model::createMesh(const std::string& materialName, std::vector<Material>& materials)
{
	/* 创建新网格 */

	indices.resize(vertices.size());
	for (int i = 0; i < indices.size(); i++)
		indices[i] = i;
	meshes.emplace_back(std::move(vertices), std::move(indices), std::vector<Texture>());
	if (!materialName.empty())
	{
		for (auto& material : materials)
		{
			if (material.name == materialName)
			{
				meshes.back().addMaterial(material);
				break;
			}
		}
	}
}

void disc0ver::Model::loadMaterial(std::vector<Material>& materials, std::string path)
{
	/*
		加载mtl文件

		一个mtl文件可能定义了多个材质 每个材质以newmtl打头 比如 newmtl materialName1

		Ka 开头的是材质的环境颜色 后跟三个[0,1]的float值 代表rgb

		Kd 开头的是材质的漫反射颜色 同上

		Ks 开头的是材质的镜面反射颜色 同上

		Ns 开头的是Phong光照模型中静脉反射的高光系数 后跟1个float

		d 开头的是不透明度 后跟1个float 1.0代表完全不透明 Tr与它相反 可以认为Tr = 1.0 - d

		Ni 开头的是折射率 后跟1个float

		map_Ka 开头的是环境贴图 它通常和漫反射贴图相同

		map_Kd 开头的是漫反射贴图

		map_Ks 开头的是镜面光贴图

		map_Ns 开头的是镜面高光贴图

		map_d 开头的是透明度贴图

		map_bump 开头的是凹凸贴图

		如果你想了解更多信息 可以去看wiki： https://en.wikipedia.org/wiki/Wavefront_.obj_file
	*/
	std::cout << "Loading material......\n" << "Path: " << path << '\n' << std::endl;
	std::ifstream infile;
	std::string tmp_str;
	infile.open(path);

	if (!infile.is_open())
	{
		std::cout << "Loading material fail!!!!!\n" << std::endl;
		return;
	}

	char line[256];
	Material tempMaterial;
	bool listening = false;
	std::string directory = "";
	if (path.find('/') != std::string::npos)
		directory = path.substr(0, path.find_last_of('/') + 1);

	while (!infile.eof())
	{
		infile.getline(line, sizeof(line));
		std::istringstream ss(line);

		ss >> tmp_str;
		if (tmp_str == "newmtl")
		{
			if (!listening)
			{
				ss >> tempMaterial.name;
				listening = true;
			}
			else
			{
				materials.push_back(tempMaterial);

				tempMaterial = Material();
				ss >> tempMaterial.name;
			}
		}
		else if (tmp_str == "Ka")
		{
			ss >> tempMaterial.Ka[0] >> tempMaterial.Ka[1] >> tempMaterial.Ka[2];
		}
		else if (tmp_str == "Kd")
		{
			ss >> tempMaterial.Kd[0] >> tempMaterial.Kd[1] >> tempMaterial.Kd[2];
		}
		else if (tmp_str == "Ks")
		{
			ss >> tempMaterial.Ks[0] >> tempMaterial.Ks[1] >> tempMaterial.Ks[2];
		}
		else if (tmp_str == "Ns")
		{
			// mtl中Ns的范围是0-1000
			ss >> tempMaterial.Ns;
		}
		else if (tmp_str == "Ni")
		{
			ss >> tempMaterial.Ni;
		}
		else if (tmp_str == "d")
		{
			ss >> tempMaterial.d;
		}
		else if (tmp_str == "illum")
		{
			ss >> tempMaterial.illum;
		}
		else if (tmp_str == "map_Ka")
		{
			std::string mapPath;
			ss >> mapPath;
			tempMaterial.map_Ka = directory + mapPath;
		}
		else if (tmp_str == "map_Kd")
		{
			std::string mapPath;
			ss >> mapPath;
			tempMaterial.map_Kd = directory + mapPath;
		}
		else if (tmp_str == "map_Ks")
		{
			std::string mapPath;
			ss >> mapPath;
			tempMaterial.map_Ks = directory + mapPath;
		}
		else if (tmp_str == "map_Ns")
		{
			std::string mapPath;
			ss >> mapPath;
			tempMaterial.map_Ns = directory + mapPath;
		}
		else if (tmp_str == "map_d")
		{
			std::string mapPath;
			ss >> mapPath;
			tempMaterial.map_d = directory + mapPath;
		}
		else if (tmp_str == "map_bump")
		{
			std::string mapPath;
			ss >> mapPath;
			tempMaterial.map_bump = directory + mapPath;
		}
		tmp_str = "";
	}
	if (listening)
		materials.push_back(tempMaterial);
}

//========================================== skyBox ======================================
void disc0ver::skyBox::setupSkyBox()
{
	// 一个立方体
	vertices = {
		// positions          
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f
	};
	// 初始化、绑定 VAO、VBO对象
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0));
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

void disc0ver::skyBox::draw(Shader& skyboxShader)
{
	// 最后绘制天空盒
	glDepthFunc(GL_LEQUAL);
	texture.use(0);
	// 注意glsl代码中的samplerCube对象名称要与这个对应 即应为skybox
	skyboxShader.setInt("skybox", 0);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthFunc(GL_LESS);
}
