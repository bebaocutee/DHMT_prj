#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

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

	glColor3f(0.1, 1.4, 0.0);
	glutSolidSphere(0.5, 20, 20);

	////////////// thân1 ////////////
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.9, 0.0, 0.0);//tinh tien
	glScalef(0.75, 0.75, 1.0);//co dan
	//glTranslatef(1.25, 0.0, 0.0);
	glutWireSphere(0.5, 20, 20);

	///////////// thân2 ////////////
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.35, 0.0, 0.0);
	glScalef(2.25, 0.75, 1.0);//co dan
	glutWireSphere(0.5, 20, 20);

	/////////// Mắt phải ////////////

	glColor3f(1.0, 1.0, 0.0);
	glPopMatrix();
	glPushMatrix();
	glRotatef(20, 1.0, 0.0, 0.0);
	glTranslatef(-0.4, 0.2, 0.2);
	glScalef(0.3, 0.4, 0.3);//co dan
	
	glutSolidSphere(0.5, 100, 100);

	/////////// Mắt trái ////////////

	glPopMatrix();
	glPushMatrix();
	glRotatef(20, -1.0, 0.0, 0.0);
	glTranslatef(-0.4, 0.2, -0.2);
	glScalef(0.3, 0.4, 0.3);//co dan
	glutSolidSphere(0.5, 100, 100);


	/////////// cánh phải ////////////

	glPopMatrix();
	glPushMatrix();
	glRotatef(40, -1, 0, 0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(2.5, 1.0, 4.0);//co dan
	glTranslatef(0.3, 0.0, 0.5);
	glutWireSphere(0.5, 20, 20);
	

	/////////// cánh trái ////////////

	glPopMatrix();
	glPushMatrix();
	glRotatef(40, 1, 0, 0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(2.5, 1.0, -4.0);//co dan
	glTranslatef(0.3, 0.0, 0.5);
	glutWireSphere(0.5, 20, 20);

	//glPushMatrix();
	//glutSolidCube(2);
	
	////ve dau
	//glColor3f(1.5, 0.0, 0.0);
	//glTranslatef(0, 1.5, 0);//tinh tien
	//glScalef(0.5, 0.5, 0.5);//co dan
	//glutSolidCube(2);
	//glPopMatrix();
	//glPushMatrix();

	////tay phai
	////glColor3f(1.5, 1.0, 0.0);
	//glTranslatef(1.5, 0.5, 0);
	//glScalef(0.5, 0.5, 0.5);
	//glutSolidCube(2);

	////tay trai
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(-1.5, 0.5, 0);
	//glScalef(0.5, 0.5, 0.5);
	//glutSolidCube(2);

	//// chan trai
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(-0.5, -1.5, 0);
	//glScalef(0.4, 1, 1);
	//glutSolidCube(2);

	////chan phai
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.5, -1.5, 0);
	//glScalef(0.4, 1, 1);
	//glutSolidCube(2);

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
	gluLookAt(-3, 10.0 , -4.0, 0, 0, 0, 0, 1, 0);// nhin truc z=10, cho trục y lên trên x=0, y=1, z=0

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














