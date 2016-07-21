#ifndef _SUPERSHAPE2D_SUPERSHAPE2D_H
#define _SUPERSHAPE2D_SUPERSHAPE2D_H

#include <GL\glut.h>
#include <GL\glew.h>

class SuperShape2D
{
	struct Vertex2D{ 
		float x;
		float y;
		int col;
	};
public:
	SuperShape2D(float m, float n1, float n2, float n3, float a, float b);
	~SuperShape2D();
private:
	float m;
	float n1;
	float n2;
	float n3;
	float a;
	float b;

	Vertex2D * vertexBuffer;
}

#endif 