#include "shader.hpp"

#include <iostream>

using std::cout;
using std::string;
using std::ifstream;
using std::stringstream;

string loadShader(string shaderName) {

	ifstream* file = new ifstream("Shaders/" + shaderName);
	if (!(*file)) {
		std::cout << "ERROR:SHADER:LOAD_SHADER ";
		std::cout << "Shader file not found or corrupted, please check file existence and integrity in the Shaders folder.\n";
		return "";
	}
	stringstream* str = new stringstream();
	
	*str << file->rdbuf();

	string toReturn = str->str();

	delete str;
	delete file;

	return toReturn;
}

void createShader(unsigned int *shaderID, string shaderName, int shaderKind) {
	string tmpSource = loadShader(shaderName);
	const char *shaderSource = tmpSource.c_str();
	*shaderID = glCreateShader(shaderKind);
	glShaderSource(*shaderID, 1, &shaderSource, NULL);
}

bool genShaders(unsigned int* shaderProgram, string vertexShaderName, string fragmentShaderName) {
	unsigned int vertexShader, fragmentShader;
	createShader(&vertexShader, vertexShaderName, GL_VERTEX_SHADER);
	createShader(&fragmentShader, fragmentShaderName, GL_FRAGMENT_SHADER);
	*shaderProgram = glCreateProgram();

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	// valid compilation check
	{
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return false;
		}
		else {
			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

			if (!success) {
				glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

				glDeleteShader(vertexShader);
				glDeleteShader(fragmentShader);

				return false;
			}
		}
	}

	glAttachShader(*shaderProgram, vertexShader);
	glAttachShader(*shaderProgram, fragmentShader);
	glLinkProgram(*shaderProgram);
	// link status check
	{
		int success;
		char infoLog[512];
		glGetShaderiv(*shaderProgram, GL_LINK_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return false;
		}
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return true;
}


// CLASS 

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
	success = genShaders(&this->ID, vertexPath, fragmentPath);
}

Shader::~Shader() {
	glDeleteProgram(this->ID);
}

void Shader::use() {
	glUseProgram(this->ID);
}

void Shader::setBool(const std::string &name, bool value) const {
	glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const {
	glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
	glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}

bool Shader::loadSuccess() const {
	return success;
}