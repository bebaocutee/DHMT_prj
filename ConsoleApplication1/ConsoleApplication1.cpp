#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

float x = 1.0;
float y = 2.0;
float z = 1.0;
const float PI = 3.14159;

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
void truc()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(50.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 50);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); //xóa bộ đệm màu| xóa chiều sâu trục z k bị chồng

	glPopMatrix();
	glPushMatrix();

	truc();

	//////////// đầu

	glColor3f(0.9, 0.8, 0.0);
	glutWireSphere(0.5, 20, 20);

	////////////// thân1 ////////////
	
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.95, 0.0, 0.0);//tinh tien
	glScalef(0.9, 0.7, 0.7);//co dan
	//glTranslatef(1.25, 0.0, 0.0);
	glutWireSphere(0.5, 20, 20);

	///////////// thân2 ////////////
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.65, 0.0, 0.0);
	glScalef(2.55, 0.7, 1.0);//co dan
	glutWireSphere(0.5, 20, 20);

	/////////// Mắt phải to////////////

	
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
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
	glColor3f(1.0, 1.0, 1.0);
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
	glTranslatef(-0.35, 0.0, 0.2);
	glScalef(0.3, 0.3, 0.3);//co dan
	//glutSolidSphere(0.5, 100, 100);
	glutSolidCone(0.5, 0.5, 20, 20);

	/////////// Râu phải ////////////

	/////////// Râu trái ////////////
	
	glPushMatrix();
	glRotatef(145, 0, 1, 0);
	glTranslatef(-0.35, 0.0, 0.2);
	glScalef(-1.0, 1.0, 1.0);
	drawArc(x - y * 0.5, y * 0.5, y / 0.5, y, 0.5, PI / 1.0, 40, 0.5);
	glPopMatrix();
	/////////// Chân phải 1 ////////////

	/////////// Chân trái 1 ////////////


	/////////// cánh phải 1////////////

	//glColor3f(1.0, 0.0, 0.2);
	//glPopMatrix();
	//glPushMatrix();
	//glRotatef(40, -1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(2.5, 1.0, 4.0);//co dan
	//glTranslatef(0.3, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);
	//

	///////////// cánh trái 1 ////////////

	//glPopMatrix();
	//glPushMatrix();
	//glRotatef(40, 1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(2.5, 1.0, -4.0);//co dan
	//glTranslatef(0.3, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);

	///////////// cánh phải 2////////////

	//glColor3f(0.8, 0.4, 1.0);
	//glPopMatrix();
	//glPushMatrix();
	//glRotatef(50, -1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(2.5, 1.0, 4.0);//co dan
	//glTranslatef(0.3, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);


	///////////// cánh trái 2////////////

	//glPopMatrix();
	//glPushMatrix();
	//glRotatef(0, 1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(2.5, 1.0, -4.0);//co dan
	//glTranslatef(0.3, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);


	///////////// cánh phải 2////////////

	//glColor3f(0.8, 0.4, 1.0);
	//glPopMatrix();
	//glPushMatrix();
	//glRotatef(50, -1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(2.5, 1.0, 4.0);//co dan
	//glTranslatef(0.3, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);


	///////////// cánh trái 2////////////

	//glPopMatrix();
	//glPushMatrix();
	//glRotatef(0, 1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	//glScalef(2.5, 1.0, -4.0);//co dan
	//glTranslatef(0.3, 0.0, 0.5);
	//glutWireSphere(0.5, 20, 20);

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
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	gluPerspective(45,(GLfloat) w/(GLfloat )h, 1, 200);//ma tran chieu
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.0, 5, 10.0, 0, 0, 0, 0, 1, 0);// nhin truc z=10, cho trục y lên trên x=0, y=1, z=0

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}














