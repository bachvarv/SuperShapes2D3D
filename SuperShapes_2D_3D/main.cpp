
#define _USE_MATH_DEFINES

#include <GL\glut.h>
#include <math.h>

float evalR(float m, float n1, float n2, float n3, float a, float b, float angle)
{
	float result = 1;

	float part1 = abs((1/a) * cos((m/4) * angle));
	part1 = pow(part1, n2);

	float part2 = abs((1/b)*sin((m/4)*angle));
	part2 = pow(part2, n3);

	result = part1 + part2;
	result = 1/ pow(result, 1/n1);

	return result;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	float radius = 5;
	float oldX = radius * cos(0.0f);
	float oldY = radius * sin(0.0f);
	float m = rand()%7;
	float n1 = 10;
	float n2 = 32;
	float n3 = 12;
	float a = 0.5;
	float b = 0.5;

	glBegin(GL_TRIANGLE_STRIP);
	//2d SuperShape
		//for( float y = 0; y < 2*M_PI; y += 0.01)
		//{
		//	radius = evalR(m, n1, n2, n3, a, b, y);
		//	float xC = 5*radius * cos(y);
		//	float yC = 5*radius * sin(y);
		//	//glVertex3d(oldX, oldY, -20.0f);
		//	glVertex3d(xC, yC, -20.0f);
		//	glColor3d(1.0f,0.0f,1.0f);
		//	//oldX = xC;
		//	//oldY = yC;
		//		
		//}

	//3D SuperShape

	for(float y = -M_PI/2; y <M_PI/2; y += 0.2)
	{
		
		for( float x = -M_PI; x < M_PI + 0.1; x += 0.2)
		{
			float xC = radius * cos(x) * cos(y);
			float yC = radius * sin(x) * cos(y);
			float zC = radius * sin(y);

			glVertex3d(xC, yC, zC);
			xC = radius * cos(x + 0.2) * cos(y);
			glVertex3d(xC, yC, zC);
		}
	}

	glEnd();

	glutSwapBuffers();
}



void reshapeWindow(int w, int h)
{
	if(h == 0)
		h = 1;

	float ratio = w*1.0f/h;

	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();

	glViewport(0,0,w,h);
	gluPerspective(45, ratio, 1, 100);

	glMatrixMode(GL_MODELVIEW);


}

int main(int argc, char** args)
{
	glutInit(&argc, args);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("3D and 2D Super shapes");


    //glutPassiveMotionFunc(move);
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshapeWindow);

	glutMainLoop();


	return 0;
}