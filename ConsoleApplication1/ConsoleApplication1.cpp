#include <iostream>
using namespace std;
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
GLfloat teta = 0;

float x = 0.0;
float y = 0.0;
float z = 0.0;
float headRadius = 0.5;
const float PI = 3.14159;


void truc()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 100);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
}

void drawArc(float startX, float startY, float startZ, float radius, float startAngle, float endAngle, int numSegments, float increaseZ = 0) {
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= numSegments; ++i) {
		float angle = startAngle + (endAngle - startAngle) * i / numSegments;
		float x = startX + radius * cos(angle);
		float y = startY + radius * sin(angle);
		glVertex3f(x, y, startZ + increaseZ);
	}
	glEnd();
}

void drawWing(float centerX, float centerY, float centerZ, float a, float b, int numPoints) {
	glBegin(GL_POINTS);
	for (int i = 0; i < numPoints; ++i) {
		float angle = 2.0 * PI * static_cast<float>(i) / static_cast<float>(numPoints);
		float x = centerX + a * cos(angle);
		float y = centerY + b * sin(angle);
		glVertex3f(x, y, centerZ);
	}
	glEnd();

}

//void drawLine(float x1, float y1, float z1, float x2, float y2, float z2, int numPoints) {
//	glBegin(GL_POINTS);
//
//	float dx = x2 - x1;
//	float dy = y2 - y1;
//	float dz = z2 - z1;
//
//	float xIncrement = dx / numPoints;
//	float yIncrement = dy / numPoints;
//	float zIncrement = dz / numPoints;
//
//	float x = x1;
//	float y = y1;
//	float z = z1;
//
//	for (int i = 0; i <= numPoints; ++i) {
//		glVertex3f(x, y, z);
//		x += xIncrement;
//		y += yIncrement;
//		z += zIncrement;
//	}
//
//	glEnd();
//}

void drawLine(float x1, float y1, float z1, float x2, float y2, float z2) {
	glBegin(GL_LINES);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glEnd();
}


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); //xóa bộ đệm màu| xóa chiều sâu trục z k bị chồng

	glPopMatrix();
	glPushMatrix();

	truc();

	glutPostRedisplay();
	//////////// đầu

	glColor3f(0.9, 0.8, 0.0);
	glutSolidSphere(0.5, 20, 20);
	//glutWireSphere(0.5, 20, 20);

	////////////// thân1 ////////////
	
	
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.95, 0.0, 0.0);//tinh tien
	//glScalef(0.9, 0.7, 0.7);//co dan
	////glTranslatef(1.25, 0.0, 0.0);
	//glutWireSphere(0.5, 20, 20);

	///////////// thân2 ////////////
	
	glColor3f(0.7, 1.0, 0.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.7, 0.0, 0.0);
	glScalef(3.0, 1.0, 1.0);//co dan
	//glutWireSphere(0.5, 20, 20);
	glutSolidSphere(0.5, 20, 20);

	/////////// Mắt phải to////////////

	
	glPopMatrix();
	glPushMatrix();

	glColor3f(1.0, 0.9, 0.6);
	glRotatef(20, 1.0, 0.0, 0.0);
	glTranslatef(-0.4, 0.2, 0.2);
	glScalef(0.35, 0.45, 0.35);//co dan	
	glutSolidSphere(0.5, 100, 100);

	/////////// Mắt phải bé////////////
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glRotatef(20, 1.0, 0.0, 0.0);
	glTranslatef(-0.5, 0.15, 0.2);
	glScalef(0.2, 0.2, 0.2);//co dan	
	glutSolidSphere(0.5, 100, 100);


	/////////// Mắt trái ////////////

	
	glPopMatrix();
	glPushMatrix();

	glColor3f(1.0, 0.9, 0.6);
	glRotatef(20, -1.0, 0.0, 0.0);
	glTranslatef(-0.4, 0.2, -0.2);
	glScalef(0.35, 0.45, 0.35);//co dan
	glutSolidSphere(0.5, 100, 100);

	/////////// Mắt trái bé////////////
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glRotatef(20, -1.0, 0.0, 0.0);
	glTranslatef(-0.5, 0.15, -0.2);
	glScalef(0.2, 0.2, 0.2);//co dan	
	glutSolidSphere(0.5, 100, 100);

	/////////// Miệng ////////////

	glPopMatrix();
	glPushMatrix();

	glColor3f(0.9, 0.0, 0.8);
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(-0.34, 0.0, 0.2);
	glScalef(0.3, 0.3, 0.3);//co dan
	//glutSolidSphere(0.5, 100, 100);
	glutSolidCone(0.5, 0.5, 20, 20);

	/////////// Râu phải ////////////
	glPopMatrix();
	glPushMatrix();

	glRotatef(90, 0.0, -1.0, 0.0);
	//glTranslatef(0.0, 0.6, -0.4);
	////drawArc(0.0 + 0.5 * 1.2, 0.5 * 0.8, 0.5 / 2, 0.5, PI, PI / 2, 50, 0.01);
	//drawArc(0.0, 0.0, 0.0, 0.5, PI, 2*PI/2, 50, 0.01);
	glTranslatef(-0.7, 0.4, 0.0);
	drawArc(0.0, 0.0, 0.0, 0.5, 0, 0.5 * PI / 0.75, 50, 0.01);


	/////////// Râu trái ////////////
	glPopMatrix();
	glPushMatrix();

	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-0.7, 0.4, 0.0);
	drawArc(0.0, 0.0, 0.0, 0.5, 0, 0.5 * PI / 0.75, 50, 0.01);
	

	///////////// Chân phải trên 1 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.7, -0.2, 0.25);
	glRotatef(130, 0.0, -1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	///////////// Chân phải dưới 1 ////////////

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.3, -0.2, 0.75);
	glRotatef(-120, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);

	///////////// Chân phải trên 2 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.4, -0.2, 0.25);
	glRotatef(130, 0.0, -1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	///////////// Chân phải dưới 2 ////////////

	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0, -0.2, 0.75);
	glRotatef(-120, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);

	///////////// Chân phải trên 3 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.1, -0.2, 0.25);
	glRotatef(130, 0.0, -1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	///////////// Chân phải dưới 3 ////////////

	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.7, -0.2, 0.75);
	glRotatef(-120, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);


	/////////// Chân trái trên 1 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.7, -0.2, -0.25);
	glRotatef(130, 0.0, 1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	/////////// Chân trái dưới 1 ////////////

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.3, -0.2, -0.75);
	glRotatef(-120, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);


	/////////// Chân trái trên 2 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.4, -0.2, -0.25);
	glRotatef(130, 0.0, 1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	/////////// Chân trái dưới 2 ////////////

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.95, -0.2, -0.75);
	glRotatef(-120, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);


	/////////// Chân trái trên 3 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.1, -0.2, -0.25);
	glRotatef(130, 0.0, 1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	/////////// Chân trái dưới 3 ////////////

	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.7, -0.2, -0.75);
	glRotatef(-120, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);

	/////////// cánh phải 1////////////

	glColor3f(0.9 , 0.5 ,0.1);
	glPopMatrix();
	glPushMatrix();
	glRotatef(40, -1, 0, 0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(1.5, 1.5, 3.0);//co dan
	glTranslatef(0.5, 0.0, 0.5);
	glutSolidSphere(0.5, 20, 20);

	//glColor3f(0.0, 0.0, 0.0);
	////glPopMatrix();
	////glPushMatrix();
	//glRotatef(40, 0, 0, -1);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(1.5, 1.5, 2.75);//co dan
	//glTranslatef(0.7, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);
	

	/////////// cánh trái 1 ////////////

	glPopMatrix();
	glPushMatrix();
	glRotatef(40, 1, 0, 0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(1.5, 1.5, -3.0);//co dan
	glTranslatef(0.5, 0.0, 0.5);
	glutSolidSphere(0.5, 20, 20);

	/////////////// cánh phải 2////////////

	glColor3f(0.8, 0.6, 0.0);
	glPopMatrix();
	glPushMatrix();
	glRotatef(40, -1, 0, 0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(2, 1.5, 2.5);//co dan
	glTranslatef(0.7, 0.0, 0.5);
	glutSolidSphere(0.5, 20, 20);


	///////////// cánh trái 2////////////

	glPopMatrix();
	glPushMatrix();
	glRotatef(40, 1, 0,0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(2.0, 1.5, -2.5);//co dan
	//glRotatef(0, 1, 0, 0);
	glTranslatef(0.7, 0.0, 0.5);
	glutSolidSphere(0.5, 20, 20);


	/////////////// cánh phải 3////////////

	//glColor3f(0.7, 0.4, 1.0);
	//glPopMatrix();
	//glPushMatrix();
	//glRotatef(-65, 1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(0.5, 0.5, 4.0);//co dan
	//glTranslatef(0.7, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);


	///////////// cánh trái 3////////////

	//glPopMatrix();
	//glPushMatrix();
	//glRotatef(65, 1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(0.5, 0.5, -4.0);//co dan
	//glTranslatef(0.7, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);

	//glPopMatrix();
	//glPushMatrix();
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glRotatef(90, 0, 1, 1);
	////glTranslatef(0.0, 0.0, 0.0);
	//glScalef(0.5, 0.5, -4.0);
	//glTranslatef(0.0, 2.0, 0.5);
	//drawWing(0.0, 0.0, 0.0, 4.0, 4.0, 200);

	glFlush();
	
}
void init() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST); // kiểm tra chiều sâu
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);//tbao su mt chieu
	glLoadIdentity();
	gluPerspective(45,(GLfloat) w/(GLfloat )h, 1, 200);//ma tran chieu
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-5.0, 10.0, 10.0, 0, 0, 0, 0, 1, 0);// nhin truc z=10, cho trục y lên trên x=0, y=1, z=0

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glEnable(GL_DEPTH_TEST);

	init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}














