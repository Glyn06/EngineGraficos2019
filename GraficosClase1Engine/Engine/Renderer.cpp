#include "Renderer.h"


using namespace std;
float vertices[] = {
	 0.0f,  0.5f, // Vertex 1 (X, Y)
	 0.5f, -0.5f, // Vertex 2 (X, Y)
	-0.5f, -0.5f  // Vertex 3 (X, Y)
};

const char* vertexSource = R"glsl(
    #version 150 core

    in vec2 position;

    void main()
    {
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";
const char* fragmentSource = R"glsl(
   #version 150 core

out vec4 outColor;

void main()
{
    outColor = vec4(1.0, 1.0, 1.0, 1.0);
}
)glsl";

GLuint vertexBuffer;
GLuint vbo;
GLuint vao;

Renderer::Renderer()
{
	glewInit();

	glGenBuffers(1, &vertexBuffer);
	
	glGenBuffers(1, &vbo); 
	glGenVertexArrays(1, &vao);									//genera 3 buffer; para verlos
	glBindVertexArray(vao);										//los buffer los tiene que bindear
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glsl ver

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);	//crea un shader vacio
	glShaderSource(vertexShader, 1, &vertexSource, NULL);	//lo carga con el source
	glCompileShader(vertexShader);							//compila el vertex shader

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();					// crean un programa que va a tener el codigo de los shader
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");

	glLinkProgram(shaderProgram);								//linkean el "programa"
	glUseProgram(shaderProgram);

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");		//ver si se puede camb pos por aca
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);			//es para leer desde donde empieza y cuantos atributos saltea
	glEnableVertexAttribArray(posAttrib);




}

void Renderer::Draw(GLFWwindow* window)
{
	//gl clear
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);			//con esto podemos cambiar el color del fondo
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	

	/* Swap front and back buffers */
	
	glfwSwapBuffers(window);


	
}

Renderer::~Renderer()
{
	
}
