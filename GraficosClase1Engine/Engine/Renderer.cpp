#include "Renderer.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"
#include <chrono>
using namespace std;

float vertices[] = {
	 0.0f,  0.5f, // Vertex 1 (X, Y)
	 0.5f, -0.5f, // Vertex 2 (X, Y)
	-0.5f, -0.5f  // Vertex 3 (X, Y)
};

const char* vertexSource = R"glsl(
    #version 150 core

    in vec2 position;
uniform mat4 trans;
    void main()
    {
        gl_Position = trans*vec4(position, 0.0, 1.0);
    }
)glsl";
const char* fragmentSource = R"glsl(
   #version 150 core
uniform vec3 triangleColor;
out vec4 outColor;

void main()
{
    outColor = vec4(triangleColor, 1.0);
}
)glsl";

GLuint vertexBuffer;
GLuint vbo;
GLuint vao;
glm::mat4 trans;
GLint uniTrans;
GLuint shaderProgram;


std::chrono::time_point<std::chrono::system_clock> then;
Renderer::Renderer()
{
	then = std::chrono::system_clock::now();
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

	shaderProgram = glCreateProgram();					// crean un programa que va a tener el codigo de los shader
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glBindFragDataLocation(shaderProgram, 0, "outColor");

	glLinkProgram(shaderProgram);								//linkean el "programa"
	glUseProgram(shaderProgram);
	GLint uniColor = glGetUniformLocation(shaderProgram, "triangleColor");
	glUniform3f(uniColor, 1.0f, 1.0f, 0.0f);			//cambiar color aca
	//glUniform3f(uniColor, (sin()+0.5f);



		

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");		//ver si se puede camb pos por aca
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);			//es para leer desde donde empieza y cuantos atributos saltea
	glEnableVertexAttribArray(posAttrib);




}
double TimeForward()
{
	typedef std::chrono::high_resolution_clock clock;
	typedef std::chrono::duration<float, std::milli> duration;

	static clock::time_point start = clock::now();
	duration elapsed = clock::now() - start;
	return elapsed.count();
}
void SpinTriangle(int speed)
{
	trans = glm::mat4(1.0f);					//crea una matriz de 4*4 inicializada con la identidad
	float t = TimeForward();
	trans = glm::rotate(trans, glm::radians((0.0f+t/20)*speed), glm::vec3(0.0f, 0.0f, 1.0f));	//esto lo rota de entrada, ver como hacer en el loop desp
	uniTrans = glGetUniformLocation(shaderProgram, "trans");					//le pasa al shader trans
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));				//agarra el trans, le indica cuantas matrices le pasamos, si le hacemos cambios antes de pasarselo, la convierte en un array de floats
}
void BackgroundColor() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);			//con esto podemos cambiar el color del fondo
}
void Renderer::Draw(GLFWwindow* window)
{
	//gl clear
	
	SpinTriangle(1);
	BackgroundColor();
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	

	/* Swap front and back buffers */
	
	glfwSwapBuffers(window);


	
}

Renderer::~Renderer()
{
	
}
