
#define _USE_MATH_DEFINES

#include <GL\glew.h>
#include <GL\glut.h>



#include <math.h>
#include "SuperShape2D.h"




int   wireframe = 0;
float segments = 0.1;
int   main_window;

SuperShape2D* shape = NULL;


void myGlutIdle( void )
{
  /* According to the GLUT specification, the current window is
     undefined during an idle callback.  So we need to explicitly change
     it if necessary */
  if ( glutGetWindow() != main_window )
    glutSetWindow(main_window);

  //glutPostRedisplay();
}

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

void renderFrame()
{
	double dAspectRatio = double(800)/double(600);
	
	float m_dFieldOfView = 30.0;
	float m_nWidth = 1;
	float m_nHeight = 1;
	float m_dSceneRadius = 2.0;
	float m_dCenter = m_dSceneRadius/ sin(m_dFieldOfView*((2*M_PI)/180));
	
	//init();

	//The usual OpenGL stuff to clear the screen and set up viewing.
	//glClearColor(0, 0, 0, 0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat fTop, fRight, fNear, fFar;
	
	fNear   = float(m_dCenter - m_dSceneRadius);
	fFar    = float(m_dCenter + m_dSceneRadius);
	
	if (dAspectRatio > 1.0) {
		fRight = fNear * float(tan(m_dFieldOfView*((2*M_PI)/180)));
		fTop   = fRight * float(dAspectRatio);		
	} else {
		fTop   = fNear * float(tan(m_dFieldOfView*((2*M_PI)/180)));
		fRight = fTop / float(dAspectRatio);
	} 
	
	glViewport(0,0,m_nWidth,m_nHeight);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum( -fTop, fTop, -fRight, fRight, fNear, 10*fFar);

	//CMatrix matModel = m_pCameraArcball->getRotatonMatrix().getInverse();
	
	//double matrix[16];
	//matModel.get(matrix[ 0], matrix[ 4], matrix[ 8], matrix[12],
	//	matrix[ 1], matrix[ 5], matrix[ 9], matrix[13],
	//	matrix[ 2], matrix[ 6], matrix[10], matrix[14],
	//	matrix[ 3], matrix[ 7], matrix[11], matrix[15]);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslated(m_dTranslateX * m_dSceneRadius/m_dZoom, m_dTranslateY*m_dSceneRadius/m_dZoom, -m_dCenter);
	//glMultMatrixd(matrix);
	//glTranslated(m_vecCameraPosition[0], m_vecCameraPosition[1], m_vecCameraPosition[2]);

	//glClear(GL_COLOR_BUFFER_BIT);

	//glutSwapBuffers();
}

void gl_DrawShape()
{
	float radius = 5;
	float oldX = radius * cos(0.0f);
	float oldY = radius * sin(0.0f);
	float m = rand()%7;
	float n1 = rand()%3;
	float n2 = rand()%4;
	float n3 = rand()%5;
	float a = 1;
	float b = 1;

	shape = new SuperShape2D(m, n1, n2, n3, a, b, 100);
}



void display()
{

	
		gl_DrawShape();
	

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//renderFrame();

	//

	shape->draw();


	glutSwapBuffers();
}

void init()
{
	glewInit();

    GLfloat ambient[] =
	{0.4f, 0.4f, 0.4f, 1.0f};
    GLfloat diffuse[] =
	{1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat specular[] =
	{0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat position[] =
	{1.0f, 1.0f, 1.0f, 1.0f};
    
    GLfloat lmodel_ambient[] =
	{0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat local_view[] =
	{0.0f};
    
    //glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    //glLightfv(GL_LIGHT0, GL_POSITION, position);
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    //glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    
    /* Select Color and Projection*/
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //glColor3f(1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
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

//void gl_DrawShape()
//{
//	float radius = 5;
//	float oldX = radius * cos(0.0f);
//	float oldY = radius * sin(0.0f);
//	float m = rand()%7;
//	float n1 = rand()%3;
//	float n2 = rand()%4;
//	float n3 = rand()%5;
//	float a = 1;
//	float b = 1;
//
//	SuperShape2D* shape = new SuperShape2D(m, n1, n2, n3, a, b, 100);
//}



int main(int argc, char** args)
{

	

	glutInit(&argc, args);
	



	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	

	

    //glutPassiveMotionFunc(move);

	

	
	//init();
	
	main_window = glutCreateWindow("3D and 2D Super shapes");
	glutDisplayFunc(display);
	glutReshapeFunc(reshapeWindow);


	//shape->draw();
	//renderFrame(shape);
	//setup();
	//draw();
	//shape->draw();



	glutMainLoop();

    // Create a CMyWindow object

    // Run the application's message loop
	return 0;
}