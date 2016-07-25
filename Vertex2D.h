#pragma once
struct Vertex2D
{
	Vertex2D(void){};
	Vertex2D(float x, float y, int c) 
	{
		cord[0] = x; 
		cord[1] = y;
		cord[2] = -15.0f;
		col[0] = 1.0f;
		col[1] = 0.0f;
		col[2] = 0.0f;
	};
	void createVertex3D(float x, float y, float z)
	{
		cord[0] = x;
		cord[1] = y;
		cord[2] = z;
	};

	void setColor(float r, float g, float b)
	{
		col[0] = r;
		col[1] = g;
		col[2] = b;
	};

	float cord[3];
	float col[3];
};

