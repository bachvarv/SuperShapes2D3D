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
	float cord[3];
	float col[3];
};

