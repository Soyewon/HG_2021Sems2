#include "pch.h"
#include "B911094.h"

void B911094::drawLines() {

	glColor3f(0.0f, 1.0f, 0.0f); // 초록색
	glBegin(GL_LINE_LOOP);
	glVertex3f(10.0, 0.0, 0.0); // x축 시작점 10
	glVertex3f(-10.0, 0.0, 0.0); // x축 끝점 -10
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f); // 빨간색
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 10.0, 0.0);
	glVertex3f(0.0, -10.0, 0.0);
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f); // 파란색
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 0.0, 10.0);
	glVertex3f(0.0, 0.0, -10.0);
	glEnd();

	return;

}

/*draw plane*/
void B911094::drawPlane() {

	glBegin(GL_TRIANGLES); // 비행기 중앙 몸체
	glColor3f(1, 0, 0);
	glVertex3f(0.0f,1.5f,0.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,-1.0f);
	glEnd();

	glBegin(GL_TRIANGLES); // 우측 날개
	glColor3f(0.5f,0.5f,1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(1.5f,0.0f,0.5f);
	glVertex3f(0.0f,2.0f,0.0f); 
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f,1.0f,0.5f); // 좌측 날개
	glVertex3f(0, 0, 0);
	glVertex3f(-1.5f,0.0f,0.5f);
	glVertex3f(0.0f,2.0f,0.0f); 
	glEnd();

}

/*draw stars*/
void B911094::drawStars() {

	glPointSize(3.0f);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 0);
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			for (int k = 0; k < 13; k++) {
				glVertex3f(5*i, 5*j, 5*k);
				glVertex3f(-5 * i, 5 * j, 5 * k);
				glVertex3f(5 * i, -5 * j, 5 * k);
				glVertex3f(5 * i, 5 * j, -5 * k);
			}
		}
	}

	glColor3f(0, 1, 1);
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			for (int k = 0; k < 13; k++) {
				glVertex3f(-5 * i, -5 * j, 5 * k);
				glVertex3f(5 * i, -5 * j,- 5 * k);
				glVertex3f(-5 * i, -5 * j, -5 * k);
				glVertex3f(-5 * i, 5 * j, -5 * k);
			}
		}
	}
	glEnd();

	glFlush();

}

void B911094::initialize() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void B911094::destroy() {

}