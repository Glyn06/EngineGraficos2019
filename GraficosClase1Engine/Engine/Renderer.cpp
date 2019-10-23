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
float texCoords[] = {
	1.0f, 1.0f,  // top-right corner  
	1.0f, 0.0f,  // lower-right corner
	0.0f, 0.0f,   // lower-left corner
	0.0f, 1.0f		//top-left corner
};
GLfloat VertexSquare2[] = {
	
	 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,		// Vertex 1 (X, Y, COLOR RGB) 0
	 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,		// Vertex 2 (X, Y, COLOR RGB) 1
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f,	// Vertex 3 (X, Y, COLOR RGB) 2
	-0.5f, 0.5f, 1.0f, 1.0f, 1.0f,	// Vertex 4 (X, Y, COLOR RGB) 3
};
GLfloat VertexSquare3[] = {
	 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,		// Vertex 1 (X, Y, COLOR RGB, TEXTURE COORDS XY) 0
	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,		// Vertex 2 (X, Y, COLOR RGB, TEXTURE COORDS XY) 1
	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,	// Vertex 3 (X, Y, COLOR RGB, TEXTURE COORDS XY) 2
	-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,	// Vertex 4 (X, Y, COLOR RGB, TEXTURE COORDS XY) 3
};

glm::vec2 rotatation = glm::vec2(0.0f, 0.0f);
//translate * *scale
const char* vertexSource = R"glsl(
    #version 330 core

    in vec2 position;
uniform mat4 translate;
uniform mat4 rotate;
uniform mat4 scale;
uniform mat4 view;
uniform mat4 proj;


    void main()
    {
        gl_Position = proj*view* translate*rotate*scale* vec4(position, 0.0, 1.0);
		
    }
)glsl";
const char* fragmentSource = R"glsl(
   #version 330 core
out vec4 outColor;

in vec3 ourColor;
in vec3 triangleColor;
//in vec2 textCoord;

//in vec3 outsColor		//<---


//uniform sampler2D ourTexture;
void main()
{
    //outColor = vec4(outsColor, 1.0);
outColor = vec4(triangleColor, 1.0);
//if(texture(ourColor), textCoord)) != null)
	//outColor = texture(ourColor, textCoord)* outColor;
}
)glsl";


GLuint vbo;
unsigned int ElementBufferObject;
GLuint vao;
unsigned int texture;
unsigned int TextureBufferObject;
GLint uniRot;
GLuint shaderProgram;

glm::vec3 tMatrix;
glm::vec3 sMatrix;

std::chrono::time_point<std::chrono::system_clock> then;

Renderer::Renderer()
{
	shape = new Shape(0);
	then = std::chrono::system_clock::now();
	glewInit();
	x = 0.0f;
	y = 0.0f;
	rotat = 0.0f;
	rotatation = glm::vec2(0.0f, 0.0f);
	//SpinTriangle(0);
	
	//DumbCodeTriangle();
	//DumbCodeSquare();
	//DumbCodeSquareTextured();
	Bind(VertexSquare2, sizeof(VertexSquare2));

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
	
	//LoadTexture();
	LoadShaders();
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");					//pos array apunta a donde esta la posicion en el "programa"
	glEnableVertexAttribArray(posAttrib);												//
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), 0);		//a donde, cuantas primitivas, que tipo de dato, false?, cuantos float usa cada primitva, cuanto te salteas			
	//nota importante: el 2 de 2*sizeof.... en el tutorial era un 5 porque usaba 3 float mas para los colores al pedo!!!!
}
/*
void Renderer::DumbCodeSquareTextured()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);										//los buffer los tiene que bindear
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexSqare), vertexSqare, GL_STATIC_DRAW);

	glGenBuffers(1, &ElementBufferObject);		
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareIndex), squareIndex, GL_STATIC_DRAW);	
	glGenBuffers(1, &TextureBufferObject);		//en vez de bindear vertices(VertexBufferObject), bindeamos elementos(ElementBufferObject)

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, TextureBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);




	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	width = 16;
	height = 16;
	nrChannels = 1;

	unsigned char *data = stbi_load("../Textures/BlueLink.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		//std::cout << "Failed to load texture" << std::endl;
	}




	stbi_image_free(data);
	
	LoadShaders();
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");					
	glEnableVertexAttribArray(posAttrib);											
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

}*/
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
void Renderer::SpinTriangle(float speed)
{
	glm::mat4 rotMatrix = glm::mat4(1.0f);					//crea una matriz de 4*4 inicializada con la identidad
	//float t = TimeForward();
	rotatation += glm::vec2(speed, 0.0f);
 	rotMatrix = glm::rotate(rotMatrix, glm::radians(rotatation.x+0.0f), glm::vec3(0.0f, 0.0f, 4.0f));	//1:matr a mult 2:velocidad 3: en que ejes rota
	uniRot = glGetUniformLocation(shaderProgram, "rotate");					//le pasa al shader trans
	glUniformMatrix4fv(uniRot, 1, GL_FALSE, glm::value_ptr(rotMatrix));				//agarra el trans, le indica cuantas matrices le pasamos, si le hacemos cambios antes de pasarselo, la convierte en un array de floats
	
}
void BackgroundColor(float r, float g, float b) 
{
	glClearColor(r, g, b, 1.0f);			//con esto podemos cambiar el color del fondo
}

void TranslateMatrix(glm::vec3 trans)
{
	glm::mat4 transMatrix = glm::translate(glm::mat4(1.0f), trans);

	GLint uniTrans = glGetUniformLocation(shaderProgram, "translate");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(transMatrix));			
}

void ScaleMatrix(glm::vec3 scale)
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);

	GLint uniScale = glGetUniformLocation(shaderProgram, "scale");
	glUniformMatrix4fv(uniScale, 1, GL_FALSE, glm::value_ptr(scaleMatrix));
}
void Renderer::movingRotatingAndScale()
{



	sMatrix = glm::vec3(1.0f, 1.0f, 1.0f);
	tMatrix = glm::vec3(x, y , 1.0f);
	//lo esta moviendo en 0.5 en x y y porque la camara, el cuadrado estan rotados en 45 grados y esto lo mueve en esa direccion, hay que verlo
	
	TranslateMatrix(tMatrix);
	ScaleMatrix(sMatrix);
	SpinTriangle(rotat);
	rotat = 0;
}
void Direction()
{
	glm::mat4 view = glm::lookAt(
		glm::vec3(0.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	);			// esto es una direccion, la w queda en 0
	GLint uniView = glGetUniformLocation(shaderProgram, "view");			//le pasamos eso al shader
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));			//a donde ?
}
void Projection(bool perspective)
{


	glm::mat4 proj;
	if (perspective)
		proj = glm::perspective(glm::radians(0.0f), 800.0f / 600.0f, 1.0f, 10.0f);		//perspective of the camera
	else {
		proj= glm::ortho(-1.0, 1.0, 1.0, 0.0, 0.0, 10.0);	//de donde empieza el left y right(en -0.5/0.5 esta muy cerca y parece que es mas grande la escala)
	}
	GLint uniProj = glGetUniformLocation(shaderProgram, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));
}

void Renderer::Draw(GLFWwindow* window)
{
	
	/*
	SpinTriangle(1);
	BackgroundColor(0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0,3);		//<- cambiar a draw elements para desp poder dibujar lo que queramos
	*/
	//movingRotatingAndScale();
	
	Direction();

	bool perspective = false;
	Projection(perspective);
	BackgroundColor(0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glBindTexture(GL_TEXTURE_2D, texture);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);		//hay que bindear las cosas bien antes, ya hice

	
	glfwSwapBuffers(window);

	movingRotatingAndScale();
	
}
void Renderer::MovePositionShape(float x, float y)
{
	this->x += x;
	this->y += y;
}
void Renderer::RotatationShape(float rot)
{
	rotat = rot;
}
Renderer::~Renderer()
{
	
	
	glfwTerminate();
}
void Renderer::LoadTexture()
{

	glGenBuffers(1, &TextureBufferObject);		//en vez de bindear vertices(VertexBufferObject), bindeamos elementos(ElementBufferObject)
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, TextureBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
	



	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	width = 16;
	height = 16;
	nrChannels = 1;

	//unsigned char *data = stbi_load("../Textures/BlueLink.png", &width, &height, &nrChannels, 0);
	/*
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		
	}

	*/


	

}
void Renderer::Bind(GLfloat _vertex[], int _arraySize) 
{
	for (int i= 0; i < 4; i++)
	{
		printf("vec %i", i);
		printf("position: %f",		_vertex[0 + (5 * i * sizeof(float))]);
		printf(" %f",				_vertex[1 + (5 * i * sizeof(float))]);
		printf(" color: %f",		_vertex[2 + (5 * i * sizeof(float))]);
		printf(" %f",				_vertex[3 + (5 * i * sizeof(float))]);
		printf(" %f \n ",			_vertex[4 + (5 * i * sizeof(float))]);
	}	//<<mal stride?
	





	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);										
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexSquare2), VertexSquare2, GL_STATIC_DRAW);

	glGenBuffers(1, &ElementBufferObject);		
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareIndex), squareIndex, GL_STATIC_DRAW);	

	//LoadTexture();
	LoadShaders2(_vertex);
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");					
	glEnableVertexAttribArray(posAttrib);												
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	
	/*GLint colAttrib = glGetAttribLocation(shaderProgram, "outsColor");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2*sizeof(float)));*/

	GLint colAttrib = glGetAttribLocation(shaderProgram, "triangleColor");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(float)));
	
	/*
	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7*sizeof(float), (void*)(5*sizeof(float)));
	*/

	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);


	/*

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	width = 16;
	height = 16;
	nrChannels = 1;

	unsigned char *data = stbi_load("../Textures/BlueLink.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		//std::cout << "Failed to load texture" << std::endl;
	}




	stbi_image_free(data);
	*/
	

}
void Renderer::Draw(GLfloat _vertex[], int _arraySize) 
{

}
void Renderer::LoadShaders2(GLfloat _vertex[])
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
	//glBindFragDataLocation(shaderProgram, 0, "outsColor");
	glLinkProgram(shaderProgram);								//linkean el "programa"
	glUseProgram(shaderProgram);
	/*
	GLint uniColor = glGetUniformLocation(shaderProgram, "triangleColor");
	glUniform3f(uniColor, 1.0f, 0.0f, 1.0f);			//cambiar color aca
	*/

}

/*



*/