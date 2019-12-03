#include "Renderer.h"
//#include "Utilis.h"
#include "glew.h"
#include "GLFW/glfw3.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

#include <chrono>

using namespace std;
glm::vec2 rotatation = glm::vec2(0.0f, 0.0f);
//translate * *scale

GLuint squareIndex[] = {	//index buffer
	0 , 1, 2,		// tirangulo derecho inferior
	2, 3, 0
};

GLfloat VertexSquare3[] = {	//vertex buffer
	 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,		// Vertex 1 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 0
	 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// Vertex 2 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 1
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,	// Vertex 3 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 2
	-0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,	// Vertex 4 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 3
};


const char* vertexSource = R"glsl(
    #version 330 core
out vec4 ourColor;
out vec2 textureCoords;
in vec4 triangleColor;
in vec2 textCoord;
in vec2 position;
uniform mat4 translate;
uniform mat4 rotate;
uniform mat4 scale;
uniform mat4 view;
uniform mat4 proj;


    void main()
    {
        gl_Position = proj*view* translate*rotate*scale* vec4(position, 0.0, 1.0);
		textureCoords = textCoord;		
		ourColor = triangleColor;
    }
)glsl";
const char* fragmentSource = R"glsl(
   #version 330 core
out vec4 outColor;

in vec4 ourColor;
in vec2 textureCoords;
uniform sampler2D ourTexture;

void main()
{
outColor = texture(ourTexture, textureCoords)* ourColor;
//outColor = ourColor;

}
)glsl";


unsigned int VBO;
unsigned int EBO;
unsigned int VAO;
unsigned int ourTexture;

GLint uniRot;
GLuint shaderProgram;

glm::vec3 tMatrix;
glm::vec3 sMatrix;

std::chrono::time_point<std::chrono::system_clock> then;
GLFWwindow* windForGl;
Renderer::Renderer()
{

	then = std::chrono::system_clock::now();
	//glewInit();
	x = 0.0f;
	y = 0.0f;
	rotat = 0.0f;
	rotatation = glm::vec2(0.0f, 0.0f);

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
	rotatation += glm::vec2(speed, 0.0f);
 	rotMatrix = glm::rotate(rotMatrix, glm::radians(rotatation.x+0.0f), glm::vec3(0.0f, 0.0f, 1.0f));	//1:matr a mult 2:velocidad 3: en que ejes rota
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


	//printf("x is %f and y is %f",x,y);
	sMatrix = glm::vec3(1.0f, 1.0f, 1.0f);
	tMatrix = glm::vec3(x, y , 0.5f);		//0.5 moves it to the middle of the screen
	//lo esta moviendo en 0.5 en x y y porque la camara, el cuadrado estan rotados en 45 grados y esto lo mueve en esa direccion, hay que verlo
	
	TranslateMatrix(tMatrix);
	ScaleMatrix(sMatrix);
	SpinTriangle(rotat);
	rotat = 0;
}
void Renderer::movingRotatingAndScaleUnMoving(float unmx, float unmy)
{

	sMatrix = glm::vec3(1.0f, 1.0f, 1.0f);
	tMatrix = glm::vec3(unmx, unmy, 0.5f);		//0.5 moves it to the middle of the screen
	//lo esta moviendo en 0.5 en x y y porque la camara, el cuadrado estan rotados en 45 grados y esto lo mueve en esa direccion, hay que verlo

	TranslateMatrix(tMatrix);
	ScaleMatrix(sMatrix);
	SpinTriangle(0);
}
void View()
{
	/*
	glm::mat4 view = glm::lookAt(
		glm::vec3(0.0f, 1.0f, -0.5f),		// 1.0 at the second value makes it not stretch vertically, third value at -0.5 to be inside the frustum
		glm::vec3(0.0f, 0.0f, 0.0f),		// wont touch
		glm::vec3(0.0f, 1.0f, 0.0f)		// wont touch
	);			// esto es una direccion, la w queda en 0
	*/

	glm::mat4 view = glm::lookAt(
		glm::vec3(0.0f, 1.0f, -0.5f),		// 1.0 at the second value makes it not stretch vertically, third value at -0.5 to be inside the frustum
		glm::vec3(0.0f, 0.0f, 0.0f),		// wont touch
		glm::vec3(0.0f, 1.0f, 0.0f)		// wont touch
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

void Renderer::Draw()
{
	View();

	bool perspective = false;

	Projection(perspective);
	BackgroundColor(0.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//printf(" algo         \r");
	//glBindTexture(GL_TEXTURE_2D, ourTexture);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);		//hay que bindear las cosas bien antes, ya hice

	
	

	movingRotatingAndScale();
	
}
void Renderer::MovePositionShape(float x, float y)
{
	this->x += x;
	this->y += y;
	printf("\n pos x: %f", this->x);
	printf("pos y: %f", this->y);
}
void Renderer::RotatationShape(float rot)
{
	rotat = rot;
}
Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);	
	glDisable(GL_BLEND);
	glfwTerminate();
}
void Renderer::LoadTexture(Entity* ent)
{
	unsigned char* data = ent->GetData();		//<--data is unitialized
	int width = ent->GetWidth();
	int height = ent->GetHeight();
		//, int width, int height
	/*
	glGenTextures(1, &ourTexture);
	glBindTexture(GL_TEXTURE_2D, ourTexture);
	
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);		//LINEAR
	if (data)
	{
		//printf("loaded texture correctly\n");
		//printf("Width: %i \n", width);
		//printf("Height: %i \n", height);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		printf( "Failed to load texture \n");
	}
	*/
}

void Renderer::Bind(Vertex* vertexBuffer, int _index[], int _vertexSize, int _indexSize)
{	//Esta de más, se usa float*, queda en caso de necesitarlo, de lo contrario borrar
	GLfloat _vertex[] = {
	vertexBuffer[0].x , vertexBuffer[0].y , vertexBuffer[0].r, vertexBuffer[0].g, vertexBuffer[0].b, vertexBuffer[0].a, vertexBuffer[0].u, vertexBuffer[0].v,
	vertexBuffer[1].x , vertexBuffer[1].y , vertexBuffer[1].r, vertexBuffer[1].g, vertexBuffer[1].b, vertexBuffer[1].a, vertexBuffer[1].u, vertexBuffer[1].v,
	vertexBuffer[2].x , vertexBuffer[2].y , vertexBuffer[2].r, vertexBuffer[2].g, vertexBuffer[2].b, vertexBuffer[2].a, vertexBuffer[2].u, vertexBuffer[2].v,
	vertexBuffer[3].x , vertexBuffer[3].y , vertexBuffer[3].r, vertexBuffer[3].g, vertexBuffer[3].b, vertexBuffer[3].a, vertexBuffer[3].u, vertexBuffer[3].v
	};

	int stride = 8;
	string xCoord = "";
	string yCoord = "";
	for (int i = 0; i < 4; i++)
	{
		printf("vec %i", i);
		printf("position: %f", _vertex[0 + (stride* i)]);
		printf(" %f", _vertex[1 + (stride* i)]);

		printf(" color: %f", _vertex[2 + (stride* i)]);
		printf(" %f", _vertex[3 + (stride* i)]);
		printf(" %f ", _vertex[4 + (stride* i)]);
		printf(" %f ", _vertex[5 + (stride* i)]);

		printf("Texture Coords is %f ", _vertex[6 + (stride* i)]);
		printf("%f  \n", _vertex[7 + (stride* i)]);
	}


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);										
	
	//SquareVertex
	//_vertex
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, _vertexSize, _vertex, GL_STATIC_DRAW);
	
	//squareIndex
	//_index
	glGenBuffers(1, &EBO);		
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indexSize, _index, GL_STATIC_DRAW);

	
	LoadShaders2(_vertex);
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(posAttrib);
	
	GLint colAttrib = glGetAttribLocation(shaderProgram, "triangleColor");
	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(colAttrib);
	/*
	GLint texAttrib = glGetAttribLocation(shaderProgram, "textCoord");
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(texAttrib);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	*/
	
}
void Renderer::Bind(float* vertexBuffer, int _index[], int _vertexSize, int _indexSize)
{
	GLfloat _vertex[] = {
	vertexBuffer[0] , vertexBuffer[1], vertexBuffer[2], vertexBuffer[3], vertexBuffer[4], vertexBuffer[5], vertexBuffer[6], vertexBuffer[7],
	vertexBuffer[8] , vertexBuffer[9], vertexBuffer[10], vertexBuffer[11], vertexBuffer[12], vertexBuffer[13], vertexBuffer[14], vertexBuffer[15],
	vertexBuffer[16] , vertexBuffer[17], vertexBuffer[18], vertexBuffer[19], vertexBuffer[20], vertexBuffer[21], vertexBuffer[22], vertexBuffer[23],
	vertexBuffer[24] , vertexBuffer[25], vertexBuffer[26], vertexBuffer[27], vertexBuffer[28], vertexBuffer[29], vertexBuffer[30], vertexBuffer[31]
	};
	int stride = 8;
	string xCoord = "";
	string yCoord = "";
	for (int i = 0; i < 4; i++)
	{
		printf("vec %i", i);
		printf("position: %f", _vertex[0 + (stride* i)]);
		printf(" %f", _vertex[1 + (stride* i)]);

		printf(" color: %f", _vertex[2 + (stride* i)]);
		printf(" %f", _vertex[3 + (stride* i)]);
		printf(" %f ", _vertex[4 + (stride* i)]);
		printf(" %f ", _vertex[5 + (stride* i)]);

		printf("Texture Coords is %f ", _vertex[6 + (stride* i)]);
		printf("%f  \n", _vertex[7 + (stride* i)]);
	}
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//SquareVertex
	//_vertex
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, _vertexSize, _vertex, GL_STATIC_DRAW);

	//squareIndex
	//_index
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indexSize, _index, GL_STATIC_DRAW);


	
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(posAttrib);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "triangleColor");
	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(colAttrib);

	LoadShaders2(_vertex);
	/*
	GLint texAttrib = glGetAttribLocation(shaderProgram, "textCoord");
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(texAttrib);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	*/
	
}

void Renderer::LoadShaders2(float _vertex[])
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);	
	glShaderSource(vertexShader, 1, &vertexSource, NULL);	
	glCompileShader(vertexShader);							

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();					
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);								//linkean el "programa"
	glUseProgram(shaderProgram);
}
void Renderer::OriginDraw()
{
	View();

	bool perspective = false;

	Projection(perspective);
	BackgroundColor(0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//printf(" algo         \r");
	glBindTexture(GL_TEXTURE_2D, ourTexture);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);		//hay que bindear las cosas bien antes, ya hice




//	movingRotatingAndScale();

}
void Renderer::OriginShaders()
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
void Renderer::OriginBind()
{
	GLfloat* _vertex = VertexSquare3;
	GLuint* _arraySize = squareIndex;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VertexSquare3), VertexSquare3, GL_STATIC_DRAW);

		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareIndex), squareIndex, GL_STATIC_DRAW);

		//LoadTexture();
		//LoadShaders2(_vertex);
		OriginShaders();
		/*
		GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
		glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
		glEnableVertexAttribArray(posAttrib);
		*/
		GLint colAttrib = glGetAttribLocation(shaderProgram, "triangleColor");
		glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(colAttrib);

		GLint texAttrib = glGetAttribLocation(shaderProgram, "textCoord");
		glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(texAttrib);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);


}
void Renderer::OriginLoadTexture(Entity* ent)
{
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(posAttrib);
	glGenTextures(1, &ourTexture);
	glBindTexture(GL_TEXTURE_2D, ourTexture);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);		//LINEAR
	unsigned char* data = ent->GetData();		//<--data is unitialized
	int width = ent->GetWidth();
	int height = ent->GetHeight();
	if (data)
	{
		printf("loaded texture correctly\n");
		printf("Width: %i \n", width);
		printf("Height: %i \n", height);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		printf("Failed to load texture \n");
	}

}
void Renderer::HalfDraw()
{
	View();

	bool perspective = false;

	Projection(perspective);
	BackgroundColor(0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::DrawEntity(Entity* ent)
{
	glBindTexture(GL_TEXTURE_2D, ourTexture);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);		//hay que bindear las cosas bien antes, ya hice
}