#define _USE_MATH_DEFINES
#include "SuperShape2D.h"

#include <GL\glew.h>
#include <GL\GL.h>
#include <GL\glut.h>
#include <math.h>


SuperShape2D::SuperShape2D(float mV, float n1V, float n2V, float n3V, float aV, float bV, int points)
{
	vboID = 0;
	cboID = 0;
	iboID = 0;
	initialized = false;

	m  = mV;
	n1 = n1V;
	n2 = n2V;
	n3 = n3V;
	a  = aV;
	b  = bV;

	v_points = points;

	vertexBuffer = new Vertex2D[v_points];

	//fillVertexBuffer();
}

SuperShape2D::SuperShape2D()
{

	vboID = 0;
	iboID = 0;
	cboID = 0;

	m = 0;
	n1 = 0;
	n2 = 0;
	n3 = 0;
	a = 0;
	b = 0;

	initialized = false;

	v_points = 0;
	//fillVertexBuffer();
	//setupVertexAndIndexBuffer();
}

SuperShape2D:: ~SuperShape2D()
{
	vboID = 0;
	iboID = 0;
	cboID = 0;

	m = 0;
	n1 = 0;
	n2 = 0;
	n3 = 0;
	a = 0;
	b = 0;

	
	
	delete [] vertexBuffer;
}

float SuperShape2D::evaluateR(float angle)
{
	float result = 1;

	float part1 = abs((1/a) * cos((m/4) * angle));
	part1 = pow(part1, n2);

	float part2 = abs((1/b)*sin((m/4) * angle));
	part2 = pow(part2, n3);

	result = part1 + part2;
	result = 1/ pow(result, 1/n1);

	return result;
}

void SuperShape2D::fillVertexBuffer()
{
	float radius = 0;
	float p = 2*M_PI /(float) v_points;
	int i = 0;
	for( float y = 0; y < 2*M_PI; y += p)
	{
		radius = evaluateR(y);
		float xC = 5*radius * cos(y);
		float yC = 5*radius * sin(y);
		int c = 0xff0000;
		vertexBuffer[i] = Vertex2D(xC,yC, c);
		i++;
	}

}

void SuperShape2D::setupVertexAndIndexBuffer(){

	glewInit();

	int size = (v_points)*3;
	float *vb = new float[size + 6];
	float *cb = new float[size + 3];
	int *ib = new int[size + 6];

	vb[0] = 0.0f;
	vb[1] = 0.0f;
	vb[2] = -15.0f;
	//vb[size + 3] = vertexBuffer[0].cord[0];
	//vb[size + 4] = vertexBuffer[0].cord[1];
	//vb[size + 5] = vertexBuffer[0].cord[2];
	int index = 3;
	int cindex = 0;
	int ii = 0;
	for(int i = 0; i < v_points ; i++)
	{
	
		Vertex2D v = vertexBuffer[i];

		//if(index == 0)
		//{
		//	
		//}

		vb[index++] = v.cord[0];
		vb[index++] = v.cord[1];
		vb[index++] = v.cord[2];
		
		cb[cindex++] = 0.5f;
		cb[cindex++] = 1.0f;
		cb[cindex++] = 0.2f;
	}

	ib[v_points] = 1;
	
	

	if(vboID == 0){
		glGenBuffers(1, &vboID);
		glGenBuffers(1, &cboID);
		glGenBuffers(1, &iboID);
	}

	glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind the buffer (vertex array data)

    glBufferData(GL_ARRAY_BUFFER, (size+2)*sizeof(float) , vb, GL_STATIC_DRAW);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_COLOR_ARRAY, cboID);
	glBufferData(GL_COLOR_ARRAY, size*sizeof(float), cb, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (v_points + 1) * sizeof(int), ib, GL_STATIC_DRAW);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	delete [] vb;
	delete [] cb;
}

void SuperShape2D::draw()
{

	if(!initialized){
		fillVertexBuffer();
		setupVertexAndIndexBuffer();
		initialized = true;
	}

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 3*sizeof(float), 0);

	
	glEnableClientState(GL_COLOR_ARRAY);
	glBindBuffer(GL_COLOR_ARRAY, cboID);
	glColorPointer(3, GL_FLOAT, 3*sizeof(float), 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	glLineWidth(4.0f);
	

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	glEnableClientState(GL_INDEX_ARRAY);

	glDrawElements(GL_TRIANGLE_FAN, v_points + 2, GL_INT, 0);
}