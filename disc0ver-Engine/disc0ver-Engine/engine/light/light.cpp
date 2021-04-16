/*
 * @Description: 光源类
 * @Author: 妄想
 * @Email: long452a@163.com
 * @Date: 2020-10-16
 *
 * @Author: xiji
 * @Email: wncka@foxmail.com
 * @Date: 2021-04-13
 */

#include "light.h"

using std::vector;
using std::string;
using std::to_string;
using disc0ver::Shader;
using disc0ver::DirLight;
using disc0ver::PointLight;
using disc0ver::SpotLight;


void disc0ver::setLightAllAttribute(const Shader& shader, const string& uniformName, const vector<DirLight>& dirLights)
{
	/*
		为glsl中的方向光uniform变量设置所有属性的值：
		direction ambient diffuse specular
	*/
	if (dirLights.size() == 1)
	{
		shader.setVec3(uniformName + ".direction", dirLights[0].direction);
		shader.setVec3(uniformName + ".ambient", dirLights[0].ambient);
		shader.setVec3(uniformName + ".diffuse", dirLights[0].diffuse);
		shader.setVec3(uniformName + ".specular", dirLights[0].specular);
	}
	else
	{
		for (int i = 0; i < dirLights.size(); i++)
		{
			shader.setVec3(uniformName + "[" + to_string(i) + "].direction", dirLights[i].direction);
			shader.setVec3(uniformName + "[" + to_string(i) + "].ambient", dirLights[i].ambient);
			shader.setVec3(uniformName + "[" + to_string(i) + "].diffuse", dirLights[i].diffuse);
			shader.setVec3(uniformName + "[" + to_string(i) + "].specular", dirLights[i].specular);
		}
	}
}

void disc0ver::setLightAllAttribute(const Shader& shader, const string& uniformName, const vector<PointLight>& pointLights)
{
	/*
		为glsl中的点光源uniform变量设置所有属性的值:
		position ambient diffuse specular constant linear quadratic
	*/
	if (pointLights.size() == 1)
	{
		shader.setVec3(uniformName + ".position", pointLights[0].position);
		shader.setVec3(uniformName + ".ambient", pointLights[0].ambient);
		shader.setVec3(uniformName + ".diffuse", pointLights[0].diffuse);
		shader.setVec3(uniformName + ".specular", pointLights[0].specular);
		shader.setFloat(uniformName + ".constant", pointLights[0].constant);
		shader.setFloat(uniformName + ".linear", pointLights[0].linear);
		shader.setFloat(uniformName + ".quadratic", pointLights[0].quadratic);
	}
	else
	{
		for (int i = 0; i < pointLights.size(); i++)
		{
			shader.setVec3(uniformName + "[" + to_string(i) + "].position", pointLights[i].position);
			shader.setVec3(uniformName + "[" + to_string(i) + "].ambient", pointLights[i].ambient);
			shader.setVec3(uniformName + "[" + to_string(i) + "].diffuse", pointLights[i].diffuse);
			shader.setVec3(uniformName + "[" + to_string(i) + "].specular", pointLights[i].specular);
			shader.setFloat(uniformName + "[" + to_string(i) + "].constant", pointLights[i].constant);
			shader.setFloat(uniformName + "[" + to_string(i) + "].linear", pointLights[i].linear);
			shader.setFloat(uniformName + "[" + to_string(i) + "].quadratic", pointLights[i].quadratic);
		}
	}
}

void disc0ver::setLightAllAttribute(const Shader& shader, const string& uniformName, const vector<SpotLight>& spotLights)
{
	/*
		为glsl中的聚光灯uniform变量设置所有属性的值:
		position direction ambient diffuse specular constant linear quadratic cutOff outerCutOff
	*/
	if (spotLights.size() == 1)
	{
		shader.setVec3(uniformName + ".position", spotLights[0].position);
		shader.setVec3(uniformName + ".direction", spotLights[0].direction);
		shader.setVec3(uniformName + ".ambient", spotLights[0].ambient);
		shader.setVec3(uniformName + ".diffuse", spotLights[0].diffuse);
		shader.setVec3(uniformName + ".specular", spotLights[0].specular);
		shader.setFloat(uniformName + ".constant", spotLights[0].constant);
		shader.setFloat(uniformName + ".linear", spotLights[0].linear);
		shader.setFloat(uniformName + ".quadratic", spotLights[0].quadratic);
		shader.setFloat(uniformName + ".cutOff", spotLights[0].cutOff);
		shader.setFloat(uniformName + ".outerCutOff", spotLights[0].outerCutOff);
	}
	else
	{
		for (int i = 0; i < spotLights.size(); i++)
		{
			shader.setVec3(uniformName + "[" + to_string(i) + "].position", spotLights[i].position);
			shader.setVec3(uniformName + "[" + to_string(i) + "].direction", spotLights[i].direction);
			shader.setVec3(uniformName + "[" + to_string(i) + "].ambient", spotLights[i].ambient);
			shader.setVec3(uniformName + "[" + to_string(i) + "].diffuse", spotLights[i].diffuse);
			shader.setVec3(uniformName + "[" + to_string(i) + "].specular", spotLights[i].specular);
			shader.setFloat(uniformName + "[" + to_string(i) + "].constant", spotLights[i].constant);
			shader.setFloat(uniformName + "[" + to_string(i) + "].linear", spotLights[i].linear);
			shader.setFloat(uniformName + "[" + to_string(i) + "].quadratic", spotLights[i].quadratic);
			shader.setFloat(uniformName + "[" + to_string(i) + "].cutOff", spotLights[i].cutOff);
			shader.setFloat(uniformName + "[" + to_string(i) + "].outerCutOff", spotLights[i].outerCutOff);
		}
	}
}
