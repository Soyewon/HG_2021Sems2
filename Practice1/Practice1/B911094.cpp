#include "pch.h"
#include "B911094.h"

void B911094::drawSphere(){

	GLfloat matx[] = { 0.0f,2.0f,0.0f,0.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matx);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matx);
	//glMaterialfv(GL_FRONT, GL_EMISSION, matx); // 초록색에 대한 물체 속성 지정. 빛에 영향이 없도록 한다
	glColor3f(0.0f, 1.0f, 0.0f); // 초록색
	glBegin(GL_LINE_LOOP);
	glVertex3f(10.0, 0.0, 0.0); // x축 시작점 10
	glVertex3f(-10.0, 0.0, 0.0); // x축 끝점 -10
	glEnd();

	GLfloat maty[] = { 2.0f,0.0f,0.0f,0.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, maty);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, maty);
	//glMaterialfv(GL_FRONT, GL_EMISSION, maty); // 빨간색에 대한 물체 속성 지정. 빛에 영향이 없도록 한다
	glColor3f(1.0f, 0.0f, 0.0f); // 빨간색
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 10.0, 0.0);
	glVertex3f(0.0, -10.0, 0.0);
	glEnd();

	GLfloat matz[] = { 0.0f,0.0f,2.0f,0.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matz);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matz);
	//glMaterialfv(GL_FRONT, GL_EMISSION, matz); // 파란색에 대한 물체 속성 지정. 빛에 영향이 없도록 한다
	glColor3f(0.0f, 0.0f, 1.0f); // 파란색
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 0.0, 10.0);
	glVertex3f(0.0, 0.0, -10.0);
	glEnd();

	/*정육면체 그리기*/
	GLfloat mat_ambient[] = { 0.3f,0.3f,1.0f,1.0f}; // 주변광 반사도
	GLfloat mat_diffuse[] = { 0.3f,0.3f,1.0f,1.0f }; // 분산광 반사도 
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	// 면 v1v2v3v4
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f); 
	glVertex3f(0.5f, 0.5f, 0.5f); // v1
	glVertex3f(0.5f, 0.5f, -0.5f); // v2
	glVertex3f(-0.5f, 0.5f, -0.5f); //v4

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); // v3
	
	glEnd();

	// 면 v1v2v5v6
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f); // v2
	glVertex3f(0.5f, 0.5f, 0.5f); // v1
	glVertex3f(0.5f, -0.5f, 0.5f); // v6

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f); // v5

	glEnd();

	//면 v1v3v6v8
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); // v3
	glVertex3f(0.5f, 0.5f, 0.5f); // v1
	glVertex3f(0.5f, -0.5f, 0.5f); // v6

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); // v8

	glEnd();

	//면 v3v4v7v8
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); // v3
	glVertex3f(-0.5f, 0.5f, -0.5f); //v4
	glVertex3f(-0.5f, -0.5f, -0.5f); // v7	

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); // v8

	glEnd();

	//면 v2v4v5v7
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f); //v4
	glVertex3f(0.5f, 0.5f, -0.5f); // v2
	glVertex3f(0.5f, -0.5f, -0.5f); // v5

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f); // v7	

	glEnd();

	//면 v5v6v7v8
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f); // v6
	glVertex3f(0.5f, -0.5f, -0.5f); // v5
	glVertex3f(-0.5f, -0.5f, -0.5f); // v7

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); // v8

	glEnd();

	/*광원 설정*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT6); //광원 2,6 ON

	GLfloat light_position[] = { 0.0f,0.0f,1.0f,1.0f };
	glLightfv(GL_LIGHT2, GL_POSITION, light_position); // 고정된 광원의 위치 설정

	GLfloat light_spot_direction[] = { 0.0f,0.0f,-1.0f };
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_spot_direction); // 고정된 광원의 방향 설정

	GLfloat ambient_light[] = { 1.0f,1.0f,1.0f,1.0f };
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient_light); // ambient 속성 부여(하얀색 빛)
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 5.0f); // 광원 효과 거리
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 1.0f); // 노출 조정

	GLfloat fixed_position[] = { 3.0f,3.0f,6.0f,1.0f }; // 초기 위치의 광원 설정
	glLightfv(GL_LIGHT6, GL_POSITION, fixed_position);
	GLfloat diffuse_light[] = { 0.4f,0.4f,1.0f,1.0f };
	glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuse_light); // specular 속성 부여

	/*광원 끄기*/
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT6);

	/*스포트라이트 설정*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light);

	GLfloat spot_Direction[] = {3.0f,3.0f,-6.0f }; // 스포트라이트 방향 설정
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 80.0f); // 스포트라이트 각도 조정-80도
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 80.0f); // 노출초점 설정
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_Direction); // 방향 설정 적용


	return;

}

void B911094::initialize() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void B911094::destroy() {

}