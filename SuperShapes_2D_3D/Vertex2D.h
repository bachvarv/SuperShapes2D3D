#pragma once
class Vertex2D
{
public:
	Vertex2D(){x = 0; y = 0;}
	Vertex2D(float x, float y);

	~Vertex2D(void);
private:
	float x;
	float y;
};

