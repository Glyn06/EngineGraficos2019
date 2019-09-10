#include "Renderer.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"
#include <chrono>
using namespace std;

float vertexTriangles[] = {
	 0.0f,  0.5f, // Vertex 1 (X, Y)
	 0.5f, -0.5f, // Vertex 2 (X, Y)
	-0.5f, -0.5f  // Vertex 3 (X, Y)

};


GLfloat vertexSqare[] = {
	 0.5f,  0.5f,	// Vertex 1 (X, Y)		0
	 0.5f, -0.5f,	// Vertex 2 (X, Y)		1
	-0.5f, -0.5f,	// Vertex 3 (X, Y)		2
	-0.5f, 0.5f,	// Vertex 4 (X, Y)		3
};
GLuint squareIndex[] = {
	0 , 1, 2,		// tirangulo derecho inferior
	2, 3, 0
};
GLuint triangleIndex[] = {
	0 , 1, 2,	
};

//translate * *scale
const char* vertexSource = R"glsl(
    #version 150 core

    in vec2 position;
uniform mat4 translate;
uniform mat4 rotate;
uniform mat4 scale;
    void main()
    {
        gl_Position =  translate*(rotate*(scale* vec4(position, 0.0, 1.0)));
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

GLuint vbo;
unsigned int ElementBufferObject;
GLuint vao;
glm::mat4 rotMatrix;
GLint uniRot;
GLuint shaderProgram;
glm::mat4 scaleMatrix;
glm::mat4 transMatrix;
GLint uniTrans;
GLint uniScale;
glm::vec3 tMatrix;
glm::vec3 sMatrix;
std::chrono::time_point<std::chrono::system_clock> then;
Renderer::Renderer()
{
	then = std::chrono::system_clock::now();
	glewInit();

	
	//DumbCodeTriangle();
	DumbCodeSquare();
	


}
void Renderer::DumbCodeTriangle()
{


	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);									//genera 3 buffer; para verlos
	glBindVertexArray(vao);										//los buffer los tiene que bindear
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexTriangles), vertexTriangles, GL_STATIC_DRAW);

	glGenBuffers(1, &ElementBufferObject);		//en vez de bindear vertices(VertexBufferObject), bindeamos elementos(ElementBufferObject)
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleIndex), triangleIndex, GL_STATIC_DRAW);
	LoadShaders();


	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);			//es para leer desde donde empieza y cuantos atributos saltea
	
}
void Renderer::DumbCodeSquare()
{
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);										//los buffer los tiene que bindear
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexSqare), vertexSqare, GL_STATIC_DRAW);

	glGenBuffers(1, &ElementBufferObject);		//en vez de bindear vertices(VertexBufferObject), bindeamos elementos(ElementBufferObject)
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareIndex), squareIndex, GL_STATIC_DRAW);	//que vamos a "tocar", cuanto espacio vamos a usar, que usamos y la primitiva
	LoadShaders();

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");					//pos array apunta a donde esta la posicion en el "programa"
	glEnableVertexAttribArray(posAttrib);												//
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), 0);		//a donde, cuantas primitivas, que tipo de dato, false?, cuantos float usa cada primitva, cuanto te salteas			
	//nota importante: el 2 de 2*sizeof.... en el tutorial era un 5 porque usaba 3 float mas para los colores al pedo!!!!
}
void Renderer::LoadShaders() 
{
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
	glUniform3f(uniColor, 0.0f, 1.0f, 0.0f);			//cambiar color aca
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
	rotMatrix = glm::mat4(1.0f);					//crea una matriz de 4*4 inicializada con la identidad
	float t = TimeForward();
	rotMatrix = glm::rotate(rotMatrix, glm::radians((0.0f+t/20)*speed), glm::vec3(0.0f, 0.0f, 4.0f));	//1:matr a mult 2:velocidad 3: en que ejes rota
	uniRot = glGetUniformLocation(shaderProgram, "rotate");					//le pasa al shader trans
	glUniformMatrix4fv(uniRot, 1, GL_FALSE, glm::value_ptr(rotMatrix));				//agarra el trans, le indica cuantas matrices le pasamos, si le hacemos cambios antes de pasarselo, la convierte en un array de floats
	
}
void BackgroundColor(float r, float g, float b) 
{
	glClearColor(r, g, b, 1.0f);			//con esto podemos cambiar el color del fondo
}

void TranslateMatrix(glm::vec3 trans)
{
	transMatrix = glm::translate(glm::mat4(1.0f), trans);

	uniTrans = glGetUniformLocation(shaderProgram, "translate");					
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(transMatrix));			
}

void ScaleMatrix(glm::vec3 scale)
{
	scaleMatrix = glm::scale(glm::mat4(1.0f), scale);

	uniScale = glGetUniformLocation(shaderProgram, "scale");
	glUniformMatrix4fv(uniScale, 1, GL_FALSE, glm::value_ptr(scaleMatrix));
}

void Renderer::Draw(GLFWwindow* window)
{
	
	/*
	SpinTriangle(1);
	BackgroundColor(0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0,3);		//<- cambiar a draw elements para desp poder dibujar lo que queramos
	*/
	sMatrix = glm::vec3(0.75f,0.25f, 1.0f);
	tMatrix = glm::vec3(0.5f, 0.5f, 0.0f);
	TranslateMatrix(tMatrix);
	ScaleMatrix(sMatrix);
	SpinTriangle(1);
	BackgroundColor(1.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);		//hay que bindear las cosas bien antes, ya hice

	
	glfwSwapBuffers(window);


	
}

Renderer::~Renderer()
{
	
	
	glfwTerminate();
}
/*



*/