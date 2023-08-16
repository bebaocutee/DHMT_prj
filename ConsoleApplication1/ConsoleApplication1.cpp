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

GLfloat initialPositionX = 0.0f; // Vị trí ban đầu của vật thể theo trục x
GLfloat initialPositionY = 0.0f; // Vị trí ban đầu của vật thể theo trục y
GLfloat initialPositionZ = 0.0f; // Vị trí ban đầu của vật thể theo trục z

float transX = 0.0;// vị trí ban đầu trên trục x
float transY = 0.0;
float transZ = 0.0;
float step = 0.006;// bước di chuyển chậm hơn
bool movingForward = true;// hướng đi chuyển

bool rotating = true;// hướng xoay

//GLfloat position = 0.0; // Vị trí của vật thể
//GLfloat speed = 0.01;   // Tốc độ di chuyển
GLfloat rotationAngle = 0.0f; // Góc xoay

//GLboolean movingForward = true; // Hướng di chuyển
GLboolean isRotatingLeft = false; // Trạng thái quay trái
GLboolean isRotatingRight = false; // Trạng thái quay phải

const float PI = 3.14159;


void truc()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(10.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, 0.0, 10);
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

	glDisable(GL_LIGHTING);

	truc();

	glutPostRedisplay();
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);// mặc định đc truyền màu light1-7 k dc màu đen
	GLfloat ambient[] = { 1.0, 0.5, 1.0, 1.0 };// ánh sáng môi trường, gt cuối là anpha
	GLfloat diffuse[] = { 0.9, 0.8, 0.0, 1.0 };// as khuếch tán
	GLfloat specular[] = { 1.0, 0.0, 0.0, 0.0 };// phản xạ
	GLfloat position[] = { 1.0, 1.0, 1.0, 1.0 };// vị trí nguồn sáng
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);// nguồn sáng, hàm số, gt
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	//////////// đầu

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);
	glutSolidSphere(0.5, 20, 20);
	//glutWireSphere(0.5, 20, 20);

	///////////// thân ////////////
	
	glPopMatrix();
	glPushMatrix();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat ambient1[] = { 1.0, 0.5, 1.0, 1.0 };// ánh sáng môi trường, gt cuối là anpha
	GLfloat diffuse1[] = { 0.9, 0.5, 0.3, 1.0 };// as khuếch tán
	GLfloat specular1[] = { 1.0, 0.0, 0.0, 0.0 };// phản xạ
	GLfloat position1[] = { 1.0, 1.0, 1.0, 1.0 };// vị trí nguồn sáng
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);// nguồn sáng, hàm số, gt
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(1.7, 0.0, 0.0);
	glScalef(3.0, 1.0, 1.0);//co dan
	glutSolidSphere(0.5, 20, 20);
	
	/////////// Mắt phải to////////////
	
	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHTING);

	glColor3f(1.0, 0.9, 0.6);
	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glRotatef(20, 1.0, 0.0, 0.0);
	glTranslatef(-0.4, 0.2, 0.2);
	glScalef(0.35, 0.45, 0.35);//co dan	
	glutSolidSphere(0.5, 100, 100);

	/////////// Mắt phải bé////////////
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glRotatef(20, 1.0, 0.0, 0.0);
	glTranslatef(-0.5, 0.15, 0.2);
	glScalef(0.2, 0.2, 0.2);//co dan	
	glutSolidSphere(0.5, 100, 100);


	/////////// Mắt trái ////////////

	glPopMatrix();
	glPushMatrix();

	glColor3f(1.0, 0.9, 0.6);
	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glRotatef(20, -1.0, 0.0, 0.0);
	glTranslatef(-0.4, 0.2, -0.2);
	glScalef(0.35, 0.45, 0.35);//co dan
	glutSolidSphere(0.5, 100, 100);

	/////////// Mắt trái bé////////////
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glRotatef(20, -1.0, 0.0, 0.0);
	glTranslatef(-0.5, 0.15, -0.2);
	glScalef(0.2, 0.2, 0.2);//co dan	
	glutSolidSphere(0.5, 100, 100);

	/////////// Miệng ////////////
	
	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHTING);

	glColor3f(0.9, 0.0, 0.8);
	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(-0.34, 0.0, 0.2);
	glScalef(0.3, 0.3, 0.3);//co dan
	glutSolidCone(0.5, 0.5, 20, 20);

	/////////// Râu phải ////////////
	
	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHTING);

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glRotatef(90, 0.0, -1.0, 0.0);
	glTranslatef(-0.7, 0.4, 0.0);
	drawArc(0.0, 0.0, 0.0, 0.5, 0, 0.5 * PI / 0.75, 50, 0.01);


	/////////// Râu trái ////////////
	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-0.7, 0.4, 0.0);
	drawArc(0.0, 0.0, 0.0, 0.5, 0, 0.5 * PI / 0.75, 50, 0.01);
	

	///////////// Chân phải trên 1 ////////////
	
	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHTING);

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(0.7, -0.2, 0.25);
	glRotatef(130, 0.0, -1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	///////////// Chân phải dưới 1 ////////////

	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(0.3, -0.2, 0.75);
	glRotatef(-120, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);

	///////////// Chân phải trên 2 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(1.4, -0.2, 0.25);
	glRotatef(130, 0.0, -1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	///////////// Chân phải dưới 2 ////////////

	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(1.0, -0.2, 0.75);
	glRotatef(-90, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);

	///////////// Chân phải trên 3 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(2.1, -0.2, 0.25);
	glRotatef(130, 0.0, -1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	///////////// Chân phải dưới 3 ////////////

	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(1.7, -0.2, 0.75);
	glRotatef(-50, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);


	/////////// Chân trái trên 1 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(0.7, -0.2, -0.25);
	glRotatef(130, 0.0, 1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	/////////// Chân trái dưới 1 ////////////

	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(0.3, -0.2, -0.75);
	glRotatef(-120, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);


	/////////// Chân trái trên 2 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(1.4, -0.2, -0.25);
	glRotatef(130, 0.0, 1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	/////////// Chân trái dưới 2 ////////////

	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(0.95, -0.2, -0.75);
	glRotatef(-90, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);


	/////////// Chân trái trên 3 ////////////

	glColor3f(0.0, 0.0, 0.0);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(2.1, -0.2, -0.25);
	glRotatef(130, 0.0, 1.0, 0.0);
	drawLine(0.0, 0.0, 0.0, 0.7, 0.0, 0.0);

	/////////// Chân trái dưới 3 ////////////

	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);

	glTranslatef(1.7, -0.2, -0.75);
	glRotatef(-50, 0.0, 0.0, 1.0);
	drawLine(0.0, 0.0, 0.0, 0.4, 0.0, 0.0);

	/////////// cánh phải 1////////////

	glPopMatrix();
	glPushMatrix();

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	GLfloat ambient2[] = { 1.0, 0.5, 1.0, 1.0 };// ánh sáng môi trường, gt cuối là anpha
	GLfloat diffuse2[] = { 0.9 , 0.2 ,0.1, 1.0 };// as khuếch tán
	GLfloat specular2[] = { 1.0, 0.0, 0.0, 0.0 };// phản xạ
	GLfloat position2[] = { 1.0, 1.0, 1.0, 1.0 };// vị trí nguồn sáng
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient2);// nguồn sáng, hàm số, gt
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular2);
	
	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);
	glRotatef(teta, 1, 0, 0);// teta cánh

	glRotatef(70, -1, 0, 0);
	glScalef(2.0, 0.2, 4.0);
	glTranslatef(0.5, 0.2, 0.5);
	glutSolidSphere(0.5, 20, 20);


	/////////// cánh trái 1 ////////////

	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);
	glRotatef(teta , -1, 0, 0);

	glRotatef(70, 1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	glScalef(2.0, 0.2, -4.0);
	glTranslatef(0.5, 0.2, 0.5);
	glutSolidSphere(0.5, 20, 20);


	/////////////// cánh phải 2////////////

	glPopMatrix();
	glPushMatrix();

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	GLfloat ambient3[] = { 1.0, 0.5, 1.0, 1.0 };// ánh sáng môi trường, gt cuối là anpha
	GLfloat diffuse3[] = { 0.8, 0.4, 1.0, 1.0 };// as khuếch tán
	GLfloat specular3[] = { 1.0, 0.0, 0.0, 0.0 };// phản xạ
	GLfloat position3[] = { 1.0, 1.0, 1.0, 1.0 };// vị trí nguồn sáng
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient3);// nguồn sáng, hàm số, gt
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse3);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular3);

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);
	glRotatef(teta , 1, 0, 0);

	glRotatef(70, -1, 0, 0);
	//glTranslatef(0.0, 0.0, 0.0);
	glScalef(1.5, 0.2, 2.5);
	glTranslatef(1.3, 0.2, 0.5);
	glutSolidSphere(0.5, 20, 20);


	///////////// cánh trái 2////////////

	glPopMatrix();
	glPushMatrix();

	glTranslatef(transX, transY, transZ);
	glRotatef(rotationAngle, 0.0, 1.0, 0.0);
	glRotatef(teta, -1, 0, 0);

	glRotatef(70, 1, 0,0);
	//glTranslatef(0.0, 0.0, 0.0);
	glScalef(1.5, 0.2, -2.5);
	glTranslatef(1.3, 0.2, 0.5);
	glutSolidSphere(0.5, 20, 20);

	///// nền////////
	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(0.1, 1.0, 0.0);
	//glRotatef(90, 0, -1, 0);
	glTranslatef(0.0, -7.5, 0);
	glScalef(2.5, 1, -2.5);
	glutSolidCube(5);

	/////hoa///

	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(0.7, 0.7, 0.1);
	//glRotatef(90, 0, -1, 0);
	glTranslatef(3.0, -4.25,4.75);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(0.5, 20, 20);

	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(0.7, 0.7, 0.1);
	//glRotatef(90, 0, -1, 0);
	glTranslatef(3.0, -4.25, 4.25);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(0.5, 20, 20);

	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(0.7, 0.7, 0.1);
	//glRotatef(90, 0, -1, 0);
	glTranslatef(3.75, -4.25, 4.5);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(0.5, 20, 20);
	 


	glFlush();
	
}


void update(int value) {
	if (movingForward) {
		transX = transX - step * cos(rotationAngle * PI / 180) ;
		transY = transX - step * sin(rotationAngle * PI / 180);
		transZ = transX - step * sin(rotationAngle * PI / 180);
		/*movingForward = true;*/
		
	}
	//else {
	//	transX = transX - step;
	//	transX = transY - step;
	//	transX = transZ - step;
	//	if (transX < -7.0) {
	//		movingForward = false;
	//	}
	//	else {
	//		movingForward = true;
	//	}
	//}
	/////cánh//
	if (rotating) {
		teta += 1.0; // tăng góc xoay lên 1 độ

		if (teta > 70.0) {
			rotating = false; // bắt đầu xoay ngược lại
		}
	}
	else {
		teta -= 1.0; // giảm góc xoay xuống 1 độ

		if (teta < 0.0) {
			rotating = true; // bắt đầu xoay ngược lại
		}
	}
	/// quay trái phải
	if (isRotatingLeft) {
		rotationAngle -= 1.0f; // Góc xoay tăng dần khi quay trái
	}

	if (isRotatingRight) {
		rotationAngle += 1.0f; // Góc xoay giảm dần khi quay phải
	}


	glutPostRedisplay(); // Gọi hàm display lại để cập nhật hình ảnh
	glutTimerFunc(15, update, 0); // Gọi lại hàm update sau 100ms
}

void keyboardDown(unsigned char key, int x, int y) {
	if (key == ' ') { // Nhấn phím Space để dừng di chuyển
		movingForward = false;
	}
	if (key == 'a') { // Nhấn phím 'a' để quay trái
		isRotatingLeft = true;
	}
	if (key == 'd') { // Nhấn phím 'd' để quay phải
		isRotatingRight = true;
	}
	if (key == 'r') { // Nhấn phím 'r' để quay về vị trí ban đầu
		transX = initialPositionX;
		transY = initialPositionY;
		transZ = initialPositionZ;
		rotationAngle = 0.0;
	}
}

void keyboardUp(unsigned char key, int x, int y) {
	if (key == ' ') { // Nhả phím Space để tiếp tục di chuyển
		movingForward = true;
	}
	if (key == 'a') { // Nhả phím 'a' để ngừng quay trái
		isRotatingLeft = false;
	}
	if (key == 'd') { // Nhả phím 'd' để ngừng quay phải
		isRotatingRight = false;
	}
}


void init() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST); // kiểm tra chiều sâu

}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,(GLfloat) w/(GLfloat )h, 1, 200);//ma tran chieu
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-13.0, 3.0, 5.0, 0, 0, 0, 0, 1, 0);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(0, update, 0);
	glutKeyboardFunc(keyboardDown); // Đăng ký hàm xử lý sự kiện nhấn phím
	glutKeyboardUpFunc(keyboardUp); // Đăng ký hàm xử lý sự kiện nhả phím


	init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}














