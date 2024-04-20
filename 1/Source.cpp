#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using glm::mat4;
using glm::vec3;
using glm::rotate;

#define M_PI 3.14159265358979323846

int main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 640, "Gimme that", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	const int numVertices = 51; // Number of vertices for the plane
	float plane_vertices[numVertices * 3] = {
		0.0f, 0.3f, 0.0f,
		0.3f, 0.3f, 0.0f,
		0.0f, 0.0f, 0.0f,

		0.3f, 0.3f, 0.0f,
		0.5f, 0.2f, 0.0f,
		0.0f, 0.0f, 0.0f,

		0.5f, 0.2f, 0.0f,
		0.7f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,

		0.7f, 0.0f, 0.0f,
		0.5f, -0.2f, 0.0f,
		0.0f, 0.0f, 0.0f,

		0.5f, -0.2f, 0.0f,
		0.3f, -0.2f, 0.0f,
		0.0f, 0.0f, 0.0f,

		0.3f, -0.2f, 0.0f,
		-0.1f, -0.2f, 0.0f,
		0.0f, 0.0f, 0.0f,

		-0.1f, -0.2f, 0.0f,
		-0.5f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,

		-0.5f, 0.0f, 0.0f,
		-0.5f, 0.2f, 0.0f,
		0.0f, 0.0f, 0.0f,

		-0.5f, 0.2f, 0.0f,
		-0.3f, 0.2f, 0.0f,
		0.0f, 0.0f, 0.0f,

		-0.3f, 0.2f, 0.0f,
		0.0f, 0.3f, 0.0f,
		0.0f, 0.0f, 0.0f,

		-0.7f, 0.4f, 0.0f,
		-0.8f, 0.3f, 0.0f,
		-0.7f, 0.1f, 0.0f,

		-0.7f, 0.4f, 0.0f,
		-0.5f, 0.2f, 0.0f,
		-0.7f, 0.1f, 0.0f,

		-0.7f, -0.2f, 0.0f,
		-0.8f, -0.1f, 0.0f,
		-0.7f, 0.1f, 0.0f,

		-0.7f, -0.2f, 0.0f,
		-0.5f, 0.0f, 0.0f,
		-0.7f, 0.1f, 0.0f,

		-0.7f, 0.1f, 0.0f,
		-0.5f, 0.2f, 0.0f,
		-0.5f, 0.0f, 0.0f,

		-0.1f, -0.2f, 0.0f,
		0.0f, -0.4f, 0.0f,
		0.2f, -0.4f, 0.0f,

		-0.1f, -0.2f, 0.0f,
		0.2f, -0.4f, 0.0f,
		0.3f, -0.2f, 0.0f,
	};

	GLfloat colours_coords[numVertices * 3] = {
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
	};


	GLuint vbo[3];
	glGenBuffers(3, vbo);
	GLuint plane_vbo = vbo[0];
	GLuint colours_vbo = vbo[1];
	GLuint texture_coords_vbo = vbo[2];

	glBindBuffer(GL_ARRAY_BUFFER, plane_vbo);
	glBufferData(GL_ARRAY_BUFFER, numVertices * 3 * sizeof(float), plane_vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glBufferData(GL_ARRAY_BUFFER, numVertices * 3 * sizeof(float), colours_coords, GL_STATIC_DRAW);

	GLfloat texture_coords[numVertices * 2] = {
		// Triangle 1
		0.53f, 0.875f,
		0.73f, 0.875f,
		0.53f, 0.5f,
		
		// Triangle 2
		0.73f, 0.875f,
		0.86f, 0.75f,
		0.53f, 0.5f,

		// Triangle 3
		0.86f, 0.75f,
		1.0f, 0.5f,
		0.53f, 0.5f,

		// Triangle 4
		1.0f, 0.5f,
		0.86f, 0.25f,
		0.53f, 0.5f,

		// Triangle 5
		0.86f, 0.25f,
		0.73f, 0.25f,
		0.53f, 0.5f,

		// Triangle 6
		0.73f, 0.25f,
		0.46f, 0.25f,
		0.53f, 0.5f,

		// Triangle 7
		0.46f, 0.25f,
		0.2f, 0.5f,
		0.53f, 0.5f,

		// Triangle 8
		0.2f, 0.5f,
		0.2f, 0.75f,
		0.53f, 0.5f,

		// Triangle 9
		0.2f, 0.75f,
		0.33f, 0.75f,
		0.53f, 0.5f,

		// Triangle 10
		0.33f, 0.75f,
		0.53f, 0.875f,
		0.53f, 0.5f,

		// Triangle 11
		0.06f, 1.0f,
		0.0f, 0.875f,
		0.06f, 0.625f,
		
		// Triangle 12
		0.06f, 1.0f,
		0.2f, 0.75f,
		0.06f, 0.625f,

		// Triangle 13
		0.06f, 0.25f,
		0.0f, 0.375f,
		0.06f, 0.625f,

		// Triangle 14
		0.06f, 0.25f,
		0.2f, 0.5f,
		0.06f, 0.625f,

		// Triangle 15
		0.06f, 0.625f,
		0.2f, 0.5f,
		0.2f, 0.75f,
		
		// Triangle 16
		0.46f, 0.25f,
		0.53f, 0.0f,
		0.66f, 0.0f,
		
		// Triangle 17
		0.46f, 0.25f,
		0.66f, 0.0f,
		0.73f, 0.25f,
	};

	glBindBuffer(GL_ARRAY_BUFFER, texture_coords_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texture_coords), texture_coords, GL_STATIC_DRAW);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, plane_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, texture_coords_vbo);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(2);

	const char* vertex_shader =
		"#version 330 core\n"
		"in vec3 vertex_position;"
		"in vec3 vertex_colour;"
		"in vec2 texture_coords;"
		"out vec3 colour;"
		"out vec2 tex_coords;"
		"uniform mat4 model;"
		"void main() {"
		"    colour = vertex_colour;"
		"    tex_coords = texture_coords;"
		"    gl_Position = model * vec4(vertex_position, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 330 core\n"
		"in vec3 colour;"
		"in vec2 tex_coords;"
		"out vec4 frag_colour;"
		"uniform sampler2D texture_sampler;"
		"void main() {"
		"    frag_colour = texture(texture_sampler, tex_coords);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);

	glBindAttribLocation(shader_programme, 0, "vertex_position");
	glBindAttribLocation(shader_programme, 1, "vertex_colour");
	glBindAttribLocation(shader_programme, 2, "texture_coords");

	glLinkProgram(shader_programme);

	int width, height, channels;
	unsigned char* image = stbi_load("img2.png", &width, &height, &channels, STBI_rgb);
	if (!image)
	{
		fprintf(stderr, "ERROR: image not loaded\n");
		return -1;
	}

	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_image_free(image);

	GLuint texture_sampler_location = glGetUniformLocation(shader_programme, "texture_sampler");
	glUniform1i(texture_sampler_location, 0);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 model(1.0f);

		GLuint location = glGetUniformLocation(shader_programme, "model");
		if (location >= 0)
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, &model[0][0]);
		}

		glUseProgram(shader_programme);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, numVertices);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}
