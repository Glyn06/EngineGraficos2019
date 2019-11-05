#include "Renderer.h"

#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

#include <chrono>

using namespace std;
glm::vec2 rotatation = glm::vec2(0.0f, 0.0f);
//translate * *scale
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


outColor = texture(ourTexture, textureCoords);
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

Renderer::Renderer()
{
	entity = new Entity(SQUARE_SHAPE);
	// ON THE GAME IN EXE PLOX
	int width = 16;
	int height = 16;
	string str = "../Textures/BlueLink.png";
	int nrChannels = 1;
	int last = 0;

	entity->LoadSpriteAtribs(str, width, height, nrChannels, last);
	//
	float* Vertex = entity->GetVertex();
	int* index = entity->GetIndex();
	int vertNum = entity->GetVertexNum(0);
	int indNum = entity->GetVertexNum(1);

	//shape = new Shape();
	then = std::chrono::system_clock::now();
	glewInit();
	x = 0.0f;
	y = 0.0f;
	rotat = 0.0f;
	rotatation = glm::vec2(0.0f, 0.0f);
	//this should go here
	//********************************************************************************
	Bind(Vertex, index, vertNum, indNum);		//<---this should get called after we recieve this from the entity which should do what shape does
													//while the vertexes get loaded in SHAPE (to know if we are drawing a square or whatever)
	//********************************************************************************
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



	sMatrix = glm::vec3(1.0f, 1.0f, 1.0f);
	tMatrix = glm::vec3(x, y , 0.5f);		//0.5 moves it to the middle of the screen
	//lo esta moviendo en 0.5 en x y y porque la camara, el cuadrado estan rotados en 45 grados y esto lo mueve en esa direccion, hay que verlo
	
	TranslateMatrix(tMatrix);
	ScaleMatrix(sMatrix);
	SpinTriangle(rotat);
	rotat = 0;
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

void Renderer::Draw(GLFWwindow* window)
{
	
	/*
	SpinTriangle(1);
	BackgroundColor(0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0,3);		//<- cambiar a draw elements para desp poder dibujar lo que queramos
	*/
	//movingRotatingAndScale();
	
	View();

	bool perspective = false;
	Projection(perspective);
	BackgroundColor(0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, ourTexture);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);		//hay que bindear las cosas bien antes, ya hice

	
	glfwSwapBuffers(window);

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
void Renderer::LoadTexture()
{
	glGenTextures(1, &ourTexture);
	glBindTexture(GL_TEXTURE_2D, ourTexture);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);		//LINEAR
	unsigned char *data = entity->GetSprite();
	int width = entity->GetWidth();
	int height = entity->GetHeight();
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
		printf( "Failed to load texture \n");
	}

}
void Renderer::Bind(GLfloat _vertex[], GLint _index[], int _vertexSize, int _indexSize)
{
	int stride = 8;
	string xCoord = "";
	string yCoord = "";
	for (int i= 0; i < 4; i++)
	{
		printf("vec %i", i);
		printf("position: %f",		_vertex[0 + (stride* i )]);
		printf(" %f",				_vertex[1 + (stride* i )]);

		printf(" color: %f",		_vertex[2 + (stride* i )]);
		printf(" %f",				_vertex[3 + (stride* i )]);
		printf(" %f ",			_vertex[4 + (stride* i )]);
		printf(" %f ", _vertex[5 + (stride* i)]);
		
		printf("Texture Coords is %f ", _vertex[6+ (stride* i)]);
		printf("%f  \n" , _vertex[7 + (stride* i)]);
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

	LoadTexture();
	LoadShaders2(_vertex);
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(posAttrib);
	
	GLint colAttrib = glGetAttribLocation(shaderProgram, "triangleColor");
	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(colAttrib);
	
	GLint texAttrib = glGetAttribLocation(shaderProgram, "textCoord");
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(texAttrib);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

}
void Renderer::Draw(GLfloat _vertex[], int _arraySize) 
{

}
void Renderer::LoadShaders2(GLfloat _vertex[])
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