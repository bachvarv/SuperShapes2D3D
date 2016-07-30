#pragma once

//#include <GL\glut.h>
#include <vector>
#include "Vertex2D.h"

class SuperShape2D
{
	

public:
	SuperShape2D(float mV, float n1V, float n2V, float n3V, float aV, float bV, int points);
	SuperShape2D();
	~SuperShape2D();

	float getMV()	{	return m ;	}
	float getN1V()	{	return n1;	}
	float getN2V()	{	return n2;	}
	float getN3V()	{	return n3;	}
	float getAV()	{	return a ;	}
	float getBV()	{	return b ;	}

	void setMV	(float v)	{	m = v ;	
								setbool(false);}
	void setN1V	(float v)	{	n1 = v;	
								setbool(false);}
	void setN2V	(float v)	{	n2 = v;	
								setbool(false);}
	void setN3V	(float v)	{	n3 = v;	
								setbool(false);}
	void setAV	(float v)	{	a = v ;	
								setbool(false);}
	void setBV	(float v)	{	b = v ;	
								setbool(false);}
	void setbool(bool b)	{ initialized = b;};

	void setPoints(int points ) { v_points = points; 
									initialized = false;}

	int getPoints() { return v_points; }
	Vertex2D* getVertexBuffer() { return vertexBuffer;}


	void setupVertexAndIndexBuffer();

	
	void draw();

private:
	float m;
	float n1;
	float n2;
	float n3;
	float a;
	float b;

	int v_points;

	Vertex2D* vertexBuffer;
	float evaluateR(float angle);
	

protected:
	unsigned int vboID;
	unsigned int cboID;
	unsigned int iboID;

	bool initialized;
	void fillVertexBuffer();
};
