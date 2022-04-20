
#define FREEGLUT_STATIC
#include <gl/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <iostream>
#include"vector"
using namespace std;
GLint imagewidth0, imagewidth1, imagewidth2, imagewidth3, imagewidth4, imagewidth5, imagewidth6, imagewidth7;
GLint imageheight0, imageheight1, imageheight2, imageheight3, imageheight4, imageheight5, imageheight6, imageheight7;
GLint pixellength0, pixellength1, pixellength2, pixellength3, pixellength4, pixellength5, pixellength6, pixellength7;

int windowWidth = 600; //Default window size
int windowHeight = 400;
float fltFOV = 60; //Field Of View
float X = 500; //Camera position
float Y = 0;
float Z = 200;
float angle = 0;
float factor = 1;




GLuint texture[8];
vector<GLubyte*>p;

void light() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	GLfloat light_ambient1[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse1[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_specular1[] = { 0.3, 0.6, 0.9, 0.0 };
	GLfloat light_position1[] = { 0.0, 0.0, 1200.0, 1.0 };

	GLfloat spot_direction1[] = { 0.0, 0.0, -1.0 };

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);//Default
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient1);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
}


void floor() {

	glPushMatrix();//floor
	glTranslatef(0.0, 0.0, -5.0);
	glScalef(1200.0, 960.0, 10.0);
	glColor3f(0.8, 0.6, 0.4);
	glutSolidCube(1);
	glColor3f(0.9, 0.9, 0.9);
	glutWireCube(1);
	glPopMatrix();
	
	glPushMatrix();//front wall
	glTranslatef(600, 0.0, 265.0);
	glScalef(10, 950.0, 540);
	glColor3f(0.8, 0.6, 0.4);
	glutSolidCube(1);
	glColor3f(0.9, 0.9, 0.9);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//left wall
	glTranslatef(0, 480.0, 265.0);
	glScalef(1200, 10.0, 540);
	glColor3f(0.8, 0.6, 0.4);
	glutSolidCube(1);
	glColor3f(0.9, 0.9, 0.9);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//right wall
	glTranslatef(0, -480.0, 265.0);
	glScalef(1200, 10.0, 540);
	glColor3f(0.8, 0.6, 0.4);
	glutSolidCube(1);
	glColor3f(0.9, 0.9, 0.9);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//left behind wall
	glTranslatef(-600, -380, 265.0);
	glScalef(10, 200.0, 540);
	glColor3f(0.8, 0.6, 0.4);
	glutSolidCube(1);
	glColor3f(0.9, 0.9, 0.9);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//right behind wall
	glTranslatef(-600, 380, 265.0);
	glScalef(10, 200.0, 540);
	glColor3f(0.8, 0.6, 0.4);
	glutSolidCube(1);
	glColor3f(0.9, 0.9, 0.9);
	glutWireCube(1);
	glPopMatrix();





	

	glEnable(GL_TEXTURE_2D);//地板
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(600, 490, 5);
	glTexCoord2f(0.0, 1.0); glVertex3f(600, -490, 5);
	glTexCoord2f(1.0, 1.0); glVertex3f(-600, -490, 5);
	glTexCoord2f(1.0, 0.0); glVertex3f(-600, 490, 5);
	glEnd();
	glDisable(GL_TEXTURE_2D);




	glEnable(GL_TEXTURE_2D);//左外墙
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-600, 490, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-600, 490, 535);
	glTexCoord2f(1.0, 1.0); glVertex3f(600, 490, 535);
	glTexCoord2f(1.0, 0.0); glVertex3f(600, 490, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);//右外墙
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-600, -490, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-600, -490, 535);
	glTexCoord2f(1.0, 1.0); glVertex3f(600, -490, 535);
	glTexCoord2f(1.0, 0.0); glVertex3f(600, -490, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);//前外墙
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(610, -490, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(610, -490, 535);
	glTexCoord2f(1.0, 1.0); glVertex3f(610, 490, 535);
	glTexCoord2f(1.0, 0.0); glVertex3f(610, 490, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);//左后墙
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-610, -490, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-610, -490, 535);
	glTexCoord2f(1.0, 1.0); glVertex3f(-610, -280, 535);
	glTexCoord2f(1.0, 0.0); glVertex3f(-610, -280, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);//右后墙
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-610, 280, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-610, 280, 535);
	glTexCoord2f(1.0, 1.0); glVertex3f(-610, 490, 535);
	glTexCoord2f(1.0, 0.0); glVertex3f(-610, 490, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	

}




void chair() 
{
	glPushMatrix(); //right low board
	glColor3f(0.4, 0.2, 0);
	glTranslatef(0, 25, 0);
	glScalef(20, 5, 80);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//right high board
	glColor3f(0.4, 0.2, 0);
	glTranslatef(-20, 25, 20);
	glScalef(20, 5, 120);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//sit board
	glColor3f(0.4, 0.2, 0);
	glTranslatef(-10, 25 + 60, 10);
	glScalef(40, 120, 5);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//back board
	glColor3f(0.4, 0.2, 0);
	glTranslatef(-30, 25 + 60, 20);
	glScalef(5, 120, 120);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix(); //left low board
	glColor3f(0.4, 0.2, 0);
	glTranslatef(0, 25 + 120, 0);
	glScalef(20, 5, 80);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//left high board
	glColor3f(0.4, 0.2, 0);
	glTranslatef(-20, 25 + 120, 20);
	glScalef(20, 5, 120);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

}

void central_pillar()
{
	glPushMatrix();//base
	glScalef(30.0, 30.0, 60.0);
	glColor3f(0.4, 0.2, 0);
	glutSolidCone(1, 1, 32, 3);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCone(1, 1, 32, 3);
	glPopMatrix();

	glPushMatrix();//pillar
	glScalef(30.0, 30.0, 100.0);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(0.5, 5.0, 20, 16);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCylinder(0.5, 5.0, 10, 16);
	glPopMatrix();

	glPushMatrix();//top bottom
	glTranslatef(0.0, 0.0, 500.0);
	glScalef(70.0, 70.0, 10.0);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(0.5, 1.0, 20, 16);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCylinder(0.5, 1.0, 10, 16);
	glPopMatrix();

	glPushMatrix();//top centre
	glTranslatef(0.0, 0.0, 510.0);
	glScalef(70.0, 70.0, 70.0);
	glColor3f(1, 1, 0.8);
	glutSolidTorus(0.1, 0.5, 128, 64);
	glColor3f(0.0, 0.0, 0.0);
	glutWireTorus(0.1, 0.5, 4, 64);
	glPopMatrix();

	glPushMatrix();//top top
	glTranslatef(0.0, 0.0, 520.0);
	glScalef(75.0, 75.0, 10.0);
	glColor3f(1, 1, 0.8);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

}

void table_pillar()
{
	glPushMatrix();//base
	glScalef(30.0, 30.0, 60.0);
	glColor3f(1, 1, 0.8);
	glutSolidCone(1, 1, 32, 3);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCone(1, 1, 32, 3);
	glPopMatrix();

	glPushMatrix();//pillar
	glScalef(30.0, 30.0, 100.0);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(0.5, 1.0, 20, 16);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCylinder(0.5, 1.0, 10, 16);
	glPopMatrix();

	glPushMatrix();//top bottom
	glTranslatef(0.0, 0.0, 80.0);
	glScalef(70.0, 70.0, 10.0);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(0.5, 1.0, 20, 16);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCylinder(0.5, 1.0, 10, 16);
	glPopMatrix();

	glPushMatrix();//top centre
	glTranslatef(0.0, 0.0, 90.0);
	glScalef(70.0, 70.0, 70.0);
	glColor3f(1, 1, 0.8);
	glutSolidTorus(0.1, 0.5, 128, 64);
	glColor3f(0.0, 0.0, 0.0);
	glutWireTorus(0.1, 0.5, 4, 64);
	glPopMatrix();

	glPushMatrix();//top top
	glTranslatef(0.0, 0.0, 100.0);
	glScalef(75.0, 75.0, 10.0);
	glColor3f(1, 1, 0.8);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

}

void lamp() 
{
	glPushMatrix();
	glScalef(1, 1, 1);
	glColor3f(1, 0.6, 0.2);
	glutSolidCylinder(20, 20, 8, 1);
	glColor3f(1, 1, 1);
	glutWireCylinder(20, 20, 8, 1);
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(0, 0, 20);
	glScalef(1, 1, 1);
	glColor3f(1, 0.6, 0.2);
	glutSolidCone(20, 60, 8, 1);
	glColor3f(1, 1, 1);
	glutWireCone(20, 60, 8, 1);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 1);
	glColor3f(1, 1, 1);
	glutSolidCylinder(0.5, 240, 100, 1);
	glColor3f(1, 1, 1);
	glutWireCylinder(0.5, 240, 100, 1);
	glPopMatrix();
}

void table()
{
	//table pillar
	glPushMatrix();
	glTranslatef(0, -30, 0);
	glScalef(0.2, 0.2, 0.8);
	table_pillar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -60, 0);
	glScalef(0.2, 0.2, 0.8);
	table_pillar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 30, 0);
	glScalef(0.2, 0.2, 0.8);
	table_pillar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 60, 0);
	glScalef(0.2, 0.2, 0.8);
	table_pillar();
	glPopMatrix();

	//table board
	glPushMatrix();
	glTranslatef(0, 0, 90);
	glColor3f(1, 1, 0.8);
	glScalef(50, 200, 10);
	glutSolidCube(1);
	glColor3f(0, 0, 0);
	glutWireCube(1);
	glPopMatrix();

}

void cross() {
	glPushMatrix(); //vertical
	glColor3f(1, 1, 0.8);
	glTranslatef(0, 0, 0);
	glScalef(10, 10, 180);
	glutSolidCube(1);
	//glColor3f(0.0, 0.0, 0.0);
	//glutWireCube(1);
	glPopMatrix();

	glPushMatrix();//horizontal
	glColor3f(1, 1, 0.8);
	glTranslatef(0, 0, 40);
	glScalef(10, 80, 10);
	glutSolidCube(1);
	//glColor3f(0.0, 0.0, 0.0);
	//glutWireCube(1);
	glPopMatrix();
}

void font() {

	glPushMatrix();
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(50, 10, 8, 1);
	glColor3f(0, 0, 0);
	glutWireCylinder(50, 10, 8, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 10);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(40, 10, 8, 1);
	glColor3f(0, 0, 0);
	glutWireCylinder(40, 10, 8, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 20);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(30, 10, 8, 1);
	glColor3f(0, 0, 0);
	glutWireCylinder(30, 10, 8, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 30);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(10, 30, 100, 1);
	glColor3f(0, 0, 0);
	glutWireCylinder(10, 30, 100, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 60);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(15, 10, 8, 1);
	glColor3f(0, 0, 0);
	glutWireCylinder(15, 10, 8, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 70);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(20, 30, 8, 1);
	glColor3f(0, 0, 0);
	glutWireCylinder(20, 30, 8, 1);
	glPopMatrix();

}

void altar()
{
	glPushMatrix(); 
	glTranslatef(0, 0, 150);
	glScalef(30, 400, 300);
	glColor3f(0.8, 0.8, 0.6);
	glutSolidCube(1);
	glColor3f(0.8, 0.8, 0.6);
	glutWireCube(1);
	glPopMatrix();

	//outside low
	glPushMatrix();
	glTranslatef(-30, 140, 0);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.6);
	glutSolidCylinder(5, 200, 10, 1);
	//glColor3f(1, 1, 0.8);
	//glutWireCylinder(5, 200, 10, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30, 155, 0);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.6);
	glutSolidCylinder(5, 200, 10, 1);
	//glColor3f(1, 1, 0.8);
	//glutWireCylinder(5, 200, 10, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30, -140, 0);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.6);
	glutSolidCylinder(5, 200, 10, 1);
	//glColor3f(1, 1, 0.8);
	//glutWireCylinder(5, 200, 10, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30, -155, 0);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.6);
	glutSolidCylinder(5, 200, 10, 1);
	//glColor3f(1, 1, 0.8);
	//glutWireCylinder(5, 200, 10, 1);
	glPopMatrix();

	//inside high
	glPushMatrix();
	glTranslatef(-30, 90, 0);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.6);
	glutSolidCylinder(5, 350, 100, 1);
	//glColor3f(1, 1, 0.8);
	//glutWireCylinder(5, 300, 100, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30, 105, 0);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.6);
	glutSolidCylinder(5, 350, 100, 1);
	//glColor3f(1, 1, 0.8);
	//glutWireCylinder(5, 300, 100, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30, -90, 0);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.6);
	glutSolidCylinder(5, 350, 100, 1);
	//glColor3f(1, 1, 0.8);
	//glutWireCylinder(5, 300, 100, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30, -105, 0);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.6);
	glutSolidCylinder(5, 350, 100, 1);
	//glColor3f(1, 1, 0.8);
	//glutWireCylinder(5, 300, 100, 1);
	glPopMatrix();

	////box
	//glPushMatrix();
	//glTranslatef(-30, 50, 100);
	//glScalef(15, 15, 200);
	//glColor3f(0.4, 0.4, 0.4);
	//glutSolidCube(1);
	//glColor3f(0.4, 0.4, 0.4);
	//glutWireCube(1);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-30, -50, 100);
	//glScalef(15, 15, 200);
	//glColor3f(0.4, 0.4, 0.4);
	//glutSolidCube(1);
	//glColor3f(0.4, 0.4, 0.4);
	//glutWireCube(1);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-30, 0, 200);
	//glScalef(15, 115, 15);
	//glColor3f(0.4, 0.4, 0.4);
	//glutSolidCube(1);
	//glColor3f(0.4, 0.4, 0.4);
	//glutWireCube(1);
	//glPopMatrix();


}

void wall_pillar() {

	glPushMatrix(); 
	glTranslatef(0, 0, 20);
	glScalef(30, 30, 20);
	glColor3f(1, 1, 0.8);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 20);
	glScalef(1, 1, 1);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(10, 400, 20, 16);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCylinder(10, 400, 10, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 420);
	glScalef(30, 30, 20);
	glColor3f(1, 1, 0.8);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 480);
	glScalef(300, 30, 100);
	glColor3f(1, 1, 0.8);
	glutSolidCube(1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1);
	glPopMatrix();




}


typedef struct { GLfloat x, y, z; } point; // define a 3D point
point p0 = { 0, 0, 0 };
point p1 = { 0, 0, 0 };
GLfloat step = 10; // declare incremental step

int time_interval = 100; // declare refresh interval in ms






void when_in_mainloop() // idle callback function
{
	glutPostRedisplay(); // force OpenGL to redraw the current window
}

void OnTimer(int value)
{
	p0.y += step;
	if (p0.y <= 0) {
		
		step = - step;
	}
	else if (p0.y > 200)
		step = -step;

	//when_in_mainloop();
	glutTimerFunc(time_interval, OnTimer, 1);
}

void door() {

	glPushMatrix();
	glScalef(10, 290.0, 540);
	glColor3f(0.8, 0.6, 0.4);
	glutSolidCube(1);
	glColor3f(0.8, 0.6, 0.4);
	glutWireCube(1);
	glPopMatrix();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-10, -145, -267);
	glTexCoord2f(0.0, 1.0); glVertex3f(-10, -145, 267);
	glTexCoord2f(1.0, 1.0); glVertex3f(-10, 145, 267);
	glTexCoord2f(1.0, 0.0); glVertex3f(-10, 145, -267);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	
}


void tree() {
	glPushMatrix();
	glScalef(5, 5, 25.0);
	glColor3f(1, 1, 0.8);
	glutSolidCylinder(1, 5.0, 20, 16);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCylinder(1, 5.0, 10, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 100);
	glScalef(30.0, 30.0, 50.0);
	glColor3f(0, 1, 0);
	glutSolidCone(1, 2.5, 32, 3);
	glColor3f(1, 1, 0.8);
	glutWireCone(1, 3, 32, 3);
	glPopMatrix();


}

void snow() {
	glPushMatrix();
	glScalef(1, 1, 1);
	glColor3f(1, 1, 1);
	glutSolidSphere(2, 100, 100);
	glPopMatrix();
}



void room()
{
	glPushMatrix();
	glRotatef(angle, 0, 0, 1);


	glPushMatrix();
	glTranslatef(300, -360, 0);
	tree();
	glPopMatrix();

	const int MIN_VALUE = -30;
	const int MAX_VALUE = 30;
	int number = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
	for (int i = 300 - 100; i <= 300 + 100; i += 10) {
		for (int j = -360 - 100; j <= -360 + 100; j += 10) {
			const int MIN_VALUE = 0;
			const int MAX_VALUE = 40;
			int number = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

			glPushMatrix();
			glTranslatef(p1.x + i, p1.y + j, p1.z + number * 10 + 100);
			snow();
			glPopMatrix();
		}
	}





	//left chair
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {

			glPushMatrix();
			glTranslatef(-300 + 80 * j, 50 + 200 * i, 40);
			chair();
			glPopMatrix();
		}

	}

	//right chair
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {

			glPushMatrix();
			glTranslatef(-300 + 80 * j, -220 - 200 * i, 40);
			chair();
			glPopMatrix();
		}

	}


	//left pillar
	for (int i = 0; i < 4; i++) {
			glPushMatrix();
			glTranslatef(-500 + 300 * i, 230 , 0);
			glScalef(0.8, 0.8, 1);
			central_pillar();
			glPopMatrix();
	}


	//right pillar
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-500 + 300 * i, -230, 0);
		glScalef(0.8, 0.8, 1);
		central_pillar();
		glPopMatrix();
	}

	//left lamp
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-500 + 150 + 300 * i, 230, 300);
		glScalef(1, 1, 1);
		lamp();
		glPopMatrix();
	}

	//right lamp
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-500 + 150 + 300 * i, -230, 300);
		glScalef(1, 1, 1);
		lamp();
		glPopMatrix();
	}

	//left wall_pillar
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-500 + 50 + 300 * i, 460, 0);
		wall_pillar();
		glPopMatrix();
	}

	//right wall_pillar
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-500 + 50 + 300 * i, -460, 0);
		wall_pillar();
		glPopMatrix();
	}
	 
	
	//table
	glPushMatrix();
	glTranslatef(400, 0, 0);
	table();
	glPopMatrix();

	//cross
	glPushMatrix();
	glTranslatef(500, 0, 90);
	cross();
	glPopMatrix();

	//font
	glPushMatrix();
	glTranslatef(500, 350, 0);
	font();
	glPopMatrix();

	//altar
	glPushMatrix();
	glTranslatef(550, 0, 0);
	altar();
	glPopMatrix();

	//leftdoor
	glPushMatrix();
	glTranslatef(-610, 140 + p0.y, 265.0);
	door();
	glPopMatrix();

	//rughrdoor
	glPushMatrix();
	glTranslatef(-610, -140 - p0.y, 265.0);
	door();
	glPopMatrix();

	floor();

	//地毯
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-350, -100, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-350, 100, 10);
	glTexCoord2f(1.0, 1.0); glVertex3f(50, 100, 10);
	glTexCoord2f(1.0, 0.0); glVertex3f(50, -100, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//front left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(150, 100, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(150, 400, 10);
	glTexCoord2f(1.0, 1.0); glVertex3f(350, 400, 10);
	glTexCoord2f(1.0, 0.0); glVertex3f(350, 100, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//front right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(150, -100, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(150, -400, 10);
	glTexCoord2f(1.0, 1.0); glVertex3f(350, -400, 10);
	glTexCoord2f(1.0, 0.0); glVertex3f(350, -100, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//behind left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-350, 100, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-350, 400, 10);
	glTexCoord2f(1.0, 1.0); glVertex3f(-550, 400, 10);
	glTexCoord2f(1.0, 0.0); glVertex3f(-550, 100, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//behind right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-350, -100, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-350, -400, 10);
	glTexCoord2f(1.0, 1.0); glVertex3f(-550, -400, 10);
	glTexCoord2f(1.0, 0.0); glVertex3f(-550, -100, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);



	//window front left 1
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(160, 470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(160, 470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(440, 470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(440, 470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	//window front right 1
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(160, -470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(160, -470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(440, -470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(440, -470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//window front left 2
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-150, 470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-150, 470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(150, 470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(150, 470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//window front right 2
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-150, -470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-150, -470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(150, -470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(150, -470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	

	//window front left 3
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-440, 470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-440, 470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(-160, 470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(-160, 470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	//window front right 3
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-440, -470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-440, -470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(-160, -470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(-160, -470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//window left behind
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-600, 470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-600, 470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(-460, 470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(-460, 470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//window right behind
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-600, -470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(-600, -470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(-460, -470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(-460, -470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//window left front
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(460, 470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(460, 470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(600, 470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(600, 470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//window right front
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(460, -470, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(460, -470, 430);
	glTexCoord2f(1.0, 1.0); glVertex3f(600, -470, 430);
	glTexCoord2f(1.0, 0.0); glVertex3f(600, -470, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	



	//front wall
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(590, -450, 10);
	glTexCoord2f(0.0, 1.0); glVertex3f(590, -450, 540);
	glTexCoord2f(1.0, 1.0); glVertex3f(590, 450, 540);
	glTexCoord2f(1.0, 0.0); glVertex3f(590, 450, 10);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	
	glPopMatrix();
}







void ReadImage(const char path[256], GLint& imagewidth, GLint& imageheight, GLint&
	pixellength) {
	GLubyte* pixeldata;
	FILE* pfile;
	fopen_s(&pfile, path, "rb");
	if (pfile == 0) exit(0);
	fseek(pfile, 0x0012, SEEK_SET);
	fread(&imagewidth, sizeof(imagewidth), 1, pfile);
	fread(&imageheight, sizeof(imageheight), 1, pfile);
	pixellength = imagewidth * 3;
	while (pixellength % 4 != 0)pixellength++;
	pixellength *= imageheight;
	pixeldata = (GLubyte*)malloc(pixellength);
	if (pixeldata == 0) exit(0);
	fseek(pfile, 54, SEEK_SET);
	fread(pixeldata, pixellength, 1, pfile);
	p.push_back(pixeldata);
	fclose(pfile);
}

void myinit1(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_FLAT);
	glEnable(GL_TEXTURE_2D);

	ReadImage("centrefloor.bmp", imagewidth0, imageheight0, pixellength0);
	ReadImage("floor.bmp", imagewidth1, imageheight1, pixellength1);
	ReadImage("window1.bmp", imagewidth2, imageheight2, pixellength2);
	ReadImage("window2.bmp", imagewidth3, imageheight3, pixellength3);
	ReadImage("window3.bmp", imagewidth4, imageheight4, pixellength4);
	ReadImage("frontwall.bmp", imagewidth5, imageheight5, pixellength5);
	ReadImage("outwall.bmp", imagewidth6, imageheight6, pixellength6);
	ReadImage("centrefloor2.bmp", imagewidth7, imageheight7, pixellength7);


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // set pixel storage mode (in the memory)
	glGenTextures(7, &texture[0]); // number of texture names to be generated and array of texture names
	glBindTexture(GL_TEXTURE_2D, texture[0]); // target to which texture is bound and name of a texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imagewidth0, imageheight0, 0, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, p[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imagewidth1, imageheight1, 0, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, p[1]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imagewidth2, imageheight2, 0, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, p[2]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imagewidth3, imageheight3, 0, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, p[3]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imagewidth4, imageheight4, 0, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, p[4]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imagewidth5, imageheight5, 0, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, p[5]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imagewidth6, imageheight6, 0, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, p[6]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imagewidth7, imageheight7, 0, GL_BGR_EXT,
		GL_UNSIGNED_BYTE, p[7]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);






	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);



}


void displayFB_and_clear()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fltFOV, 1, 0.1, 7000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(- X * factor, Y * factor, Z * factor * 2, 0, 0, 0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.4, 0.5, 0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	room();
	light();
	
	glutSwapBuffers();
}




void reshapeWindow(GLint intNewWidth, GLint intNewHeight) {
	glViewport(0, 0, intNewWidth, intNewHeight);
}



void keyboard_input(unsigned char key, int x, int y) {
	if (key == 'a' || key == 'A') { angle += 1; }
	if (key == 'd' || key == 'D') { angle -= 1; }
	if (key == 'w' || key == 'W')
		Z += 10;
	if (key == 's' || key == 'S')
		Z -= 10;
	if (key == 'z' || key == 'Z') {
		glDisable(GL_LIGHT1);
	}
	if (key == 'x' || key == 'X') {
		glEnable(GL_LIGHT1);
	}
	glutPostRedisplay();
	if (key == 'i' || key == 'I')
		factor -= 0.2;
	if (key == 'o' || key == 'O')
		factor += 0.2;
}


void mouse_input(int button, int state, int x, int y) // mouse interactions
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
		step = 0; // decrement step
	else if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON && step <= 1)
		step = 10; // increment step
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(200, 150);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("church");
	myinit1();
	glutDisplayFunc(displayFB_and_clear);
	
	glutIdleFunc(when_in_mainloop);
	glutTimerFunc(time_interval, OnTimer, 1);

	glutReshapeFunc(reshapeWindow);
	glutKeyboardFunc(keyboard_input);
	glutMouseFunc(mouse_input);


	glutMainLoop();
}
