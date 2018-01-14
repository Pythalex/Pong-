#include "graphics.hpp"
#include "shader.hpp"

using std::vector;

#define BLACK 0.0f, 0.0f, 0.0f, 1.0f
#define WHITE 1.0f, 1.0f, 1.0f, 1.0f

vector<unsigned int> VAOs;
vector<unsigned int> EBOs;
vector<unsigned int> VBOs;
vector<unsigned int> nbOfVertices;
Shader* shader;

int WIN_WIDTH;
int WIN_HEIGHT;

void initGraphics() {

	VAOs = vector<unsigned int>(0);
	EBOs = vector<unsigned int>(0);
	nbOfVertices = vector<unsigned int>();

	shader = new Shader("VertexShader.glsl", "FragmentShader.glsl");

	if (!shader->loadSuccess()) { // terminates if there's a problem
		std::cerr << "The shaders didn't load successfully.";
	}

	shader->use();
}

void terminateGraphics() {
	delete shader;

	destroyObjects();
}

void drawEverything(GLFWwindow* win) {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwGetWindowSize(win, &WIN_WIDTH, &WIN_HEIGHT);

	for (int i = 0; i < VAOs.size(); i++) {
		glBindVertexArray(VAOs[i]);

		shader->use();
		glUniform1f(glGetUniformLocation(shader->ID, "width"), WIN_WIDTH);
		glUniform1f(glGetUniformLocation(shader->ID, "height"), WIN_HEIGHT);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[i]);
		glDrawElements(GL_TRIANGLES, nbOfVertices[i], GL_UNSIGNED_INT, 0);
	}
	
	glfwSwapBuffers(win);

	destroyObjects();

	VAOs.clear();
	EBOs.clear();
	nbOfVertices.clear();
}

void destroyObjects() {
	for(unsigned int i = 0; i < VAOs.size(); i++) {
		glDeleteVertexArrays(1, &VAOs[i]);
		glDeleteBuffers(1, &EBOs[i]);
	}
}

bool indexOf(vector<unsigned int> arr, unsigned int elm, int *index) {
	for (*index = 0; *index < arr.size(); *index++) {
		if (arr[*index] == elm) {
			return true;
		}
	}
	*index = -1;
	return false;
}

void drawRect(GLFWwindow* win, float x, float y, float width, float height) {
	glfwGetWindowSize(win, &WIN_WIDTH, &WIN_HEIGHT);

	float x1 = x, y1 = y;
	float x2 = x + width, y2 = y + height;

	float vertices[] = {
		x1, y1, 0.0f, // top left
		x1, y2, 0.0f, // bottom left
		x2, y1, 0.0f, // top right
		x2, y2, 0.0f  // bottom right
	};

	unsigned int indices[] = {
		0, 1, 2, // first triangle
		2, 3, 1  // second triangle
	};

	// create buffers
	unsigned int VAO, EBO, VBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);

	// bind VAO
	glBindVertexArray(VAO);

	// bind vbo and load vertices
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// bind ebo and load indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// activate the coordinate attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// unbind to prevent conflicts
	glBindVertexArray(0); 

	glDeleteBuffers(1, &VBO);

	// sotre VAO and VBO
	VAOs.push_back(VAO);
	EBOs.push_back(EBO);
	nbOfVertices.push_back(6);
}

void drawTriangle(GLFWwindow* win, float x1, float y1, float x2, float y2, float x3, float y3) {
	glfwGetWindowSize(win, &WIN_WIDTH, &WIN_HEIGHT);


	float vertices[] = {
		x1, y1, 0.0f,
		x1, y2, 0.0f, 
		x2, y1, 0.0f 
	};

	unsigned int indices[] = {
		0, 1, 2, // triangle
	};

	// create buffers
	unsigned int VAO, EBO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);

	// bind VAO
	glBindVertexArray(VAO);

	// bind vbo and load vertices
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// bind ebo and load indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// activate the coordinate attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// unbind to prevent conflicts
	glBindVertexArray(0);

	// store VAO and EBO
	VAOs.push_back(VAO);
	EBOs.push_back(EBO);
	nbOfVertices.push_back(3);
}