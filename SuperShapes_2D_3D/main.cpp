#include <GL\glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3d(-0.5f,-0.5f, -5.0f);
		
		glVertex3d(-0.5f, 0.5f, -5.0f);
		
		glVertex3d( 0.5f, 0.5f, -5.0f);
		
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