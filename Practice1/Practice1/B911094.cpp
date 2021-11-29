#include "pch.h"
#include "B911094.h"

void B911094::drawSphere(){

	GLfloat matx[] = { 0.0f,2.0f,0.0f,0.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matx);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matx);
	//glMaterialfv(GL_FRONT, GL_EMISSION, matx); // �ʷϻ��� ���� ��ü �Ӽ� ����. ���� ������ ������ �Ѵ�
	glColor3f(0.0f, 1.0f, 0.0f); // �ʷϻ�
	glBegin(GL_LINE_LOOP);
	glVertex3f(10.0, 0.0, 0.0); // x�� ������ 10
	glVertex3f(-10.0, 0.0, 0.0); // x�� ���� -10
	glEnd();

	GLfloat maty[] = { 2.0f,0.0f,0.0f,0.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, maty);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, maty);
	//glMaterialfv(GL_FRONT, GL_EMISSION, maty); // �������� ���� ��ü �Ӽ� ����. ���� ������ ������ �Ѵ�
	glColor3f(1.0f, 0.0f, 0.0f); // ������
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 10.0, 0.0);
	glVertex3f(0.0, -10.0, 0.0);
	glEnd();

	GLfloat matz[] = { 0.0f,0.0f,2.0f,0.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matz);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matz);
	//glMaterialfv(GL_FRONT, GL_EMISSION, matz); // �Ķ����� ���� ��ü �Ӽ� ����. ���� ������ ������ �Ѵ�
	glColor3f(0.0f, 0.0f, 1.0f); // �Ķ���
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 0.0, 10.0);
	glVertex3f(0.0, 0.0, -10.0);
	glEnd();

	/*������ü �׸���*/
	GLfloat mat_ambient[] = { 0.3f,0.3f,1.0f,1.0f}; // �ֺ��� �ݻ絵
	GLfloat mat_diffuse[] = { 0.3f,0.3f,1.0f,1.0f }; // �л걤 �ݻ絵 
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	// �� v1v2v3v4
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f); 
	glVertex3f(0.5f, 0.5f, 0.5f); // v1
	glVertex3f(0.5f, 0.5f, -0.5f); // v2
	glVertex3f(-0.5f, 0.5f, -0.5f); //v4

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); // v3
	
	glEnd();

	// �� v1v2v5v6
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f); // v2
	glVertex3f(0.5f, 0.5f, 0.5f); // v1
	glVertex3f(0.5f, -0.5f, 0.5f); // v6

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f); // v5

	glEnd();

	//�� v1v3v6v8
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); // v3
	glVertex3f(0.5f, 0.5f, 0.5f); // v1
	glVertex3f(0.5f, -0.5f, 0.5f); // v6

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); // v8

	glEnd();

	//�� v3v4v7v8
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f); // v3
	glVertex3f(-0.5f, 0.5f, -0.5f); //v4
	glVertex3f(-0.5f, -0.5f, -0.5f); // v7	

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); // v8

	glEnd();

	//�� v2v4v5v7
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f); //v4
	glVertex3f(0.5f, 0.5f, -0.5f); // v2
	glVertex3f(0.5f, -0.5f, -0.5f); // v5

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f); // v7	

	glEnd();

	//�� v5v6v7v8
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f); // v6
	glVertex3f(0.5f, -0.5f, -0.5f); // v5
	glVertex3f(-0.5f, -0.5f, -0.5f); // v7

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f); // v8

	glEnd();

	/*���� ����*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT6); //���� 2,6 ON

	GLfloat light_position[] = { 0.0f,0.0f,1.0f,1.0f };
	glLightfv(GL_LIGHT2, GL_POSITION, light_position); // ������ ������ ��ġ ����

	GLfloat light_spot_direction[] = { 0.0f,0.0f,-1.0f };
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_spot_direction); // ������ ������ ���� ����

	GLfloat ambient_light[] = { 1.0f,1.0f,1.0f,1.0f };
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient_light); // ambient �Ӽ� �ο�(�Ͼ�� ��)
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 5.0f); // ���� ȿ�� �Ÿ�
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 1.0f); // ���� ����

	GLfloat fixed_position[] = { 3.0f,3.0f,6.0f,1.0f }; // �ʱ� ��ġ�� ���� ����
	glLightfv(GL_LIGHT6, GL_POSITION, fixed_position);
	GLfloat diffuse_light[] = { 0.4f,0.4f,1.0f,1.0f };
	glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuse_light); // specular �Ӽ� �ο�

	/*���� ����*/
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT6);

	/*����Ʈ����Ʈ ����*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light);

	GLfloat spot_Direction[] = {3.0f,3.0f,-6.0f }; // ����Ʈ����Ʈ ���� ����
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 80.0f); // ����Ʈ����Ʈ ���� ����-80��
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 80.0f); // �������� ����
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_Direction); // ���� ���� ����


	return;

}

void B911094::initialize() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void B911094::destroy() {

}