#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
	/// CONSTRUCTOR
public:
	/** 
	 * constructor reads and builds the shader
	 * vertexPath and fragmentPath are relative path FROM THE SHADERS FOLDER,
	 * THUS THE PATH MUST NOT CONTAIN "Shaders/" IN THEM, OR ELSE THEY'LL NOT BE FOUND
	 * @param vertexPath the path for the vertex shader
	 * @param fragmentPath the path for the fragment shader
	 */
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// delete the shader program
	~Shader();

	/// METHODS
public:
	// use/activate the shader
	void use();

	// utility uniform functions
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

	bool loadSuccess() const;

	/// ATTRIBUTES
public:
	// the program ID
	unsigned int ID;
private:
	// shader loaded and compile successfully
	bool success;
};

/**
* Generates a shader program, load vertex and fragment shaders and compile them.
* Attach them to the program;
* Returns true if everything went right, else returns false.
* @param shaderProgram : ptr to the shader program
*/
bool genShaders(unsigned int* shaderProgram, std::string vertexShaderName, std::string fragmentShaderName);

/**
* Loads a shader from the Shaders/ folder and
* returns its source code.
* @param shaderName : shader filename (relative path from {cd}/Shaders/)
* @return source code.
*/
std::string loadShader(std::string shaderName);

/**
* Creates shader given its filename and its kind (vertex, fragment)
* @param shaderID : ptr to the shaderID variable
* @param shaderName : filename of the shader in Shaders/ folder
* @param shaderKind : kind of shader
*/
void createShader(unsigned int *shaderID, std::string shaderName, int shaderKind);


#endif