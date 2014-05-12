#include <cstdlib>
#include <iostream>
#include <ctime>
#include <GL/glut.h>
#include "common.h"
using namespace std;

double colors[][3] = {
	{ 0.2, 0.2, 0.2 },
	{ 0.4, 0.4, 0.4 },
	{ 0.0, 1.0, 1.0 },
	{ 1.0, 1.0, 0.0 },
	{ 0.67, 1.0, 0.02 },
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 0.64, 0.0 },
	{ 0.31, 0.0, 0.31 }
};

double colors2[][3] = {
	{ 0.2, 0.2, 0.2 },
	{ 0.3, 0.3, 0.3 },
	{ 0.0, 0.9, 0.9 },
	{ 0.9, 0.9, 0.0 },
	{ 0.57, 0.9, 0.01 },
	{ 0.9, 0.0, 0.0 },
	{ 0.0, 0.0, 0.9 },
	{ 0.9, 0.54, 0.0 },
	{ 0.21, 0.0, 0.21 }
};

char* title = "Tetris";

// �u���b�N�̑傫��
const int size = 50;

// �t�B�[���h�̉���(�u���b�N������)
const int width = 10;
// �t�B�[���h�̏c��(�u���b�N������)
const int height = 20;

// �]��
const int frame = 2;

namespace {
	int crdnt = 0;
}

// �����ɕ`��̏���������
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	displayField();

	// �����ɕ`��̏���������

	displayBlock(0, crdnt, Aqua); // �T���v��Aqua
	displayBlock(1, crdnt + 1, Yellow); //�T���v��Yellow
	displayBlock(2, crdnt + 2, Green); // �T���v��Green
	displayBlock(3, crdnt + 3, Red); // �T���v��Red
	displayBlock(4, crdnt + 4, Blue); // �T���v��Blue
	displayBlock(5, crdnt + 5, Orange); // �T���v��Orange
	displayBlock(6, crdnt + 6, Purple); // �T���v��Purple

	glutSwapBuffers();
}

// �����ɃA�j���[�V���������⎞�Ԍo�߂ɂ��ĕ`�揈��������
void timer(int value)
{
	// �����ɏ���������
	
	// �ȉ��T���v��
	if (++crdnt >= height) {
		crdnt = 0;
	}
	glutTimerFunc(500, timer, 0); // ���̃^�C�}�[

	glutPostRedisplay(); // ������Ȃ�����
}

void idle()
{

}


// �u���b�N��x,y��color�F�ŕ`��("�t�B�[���h��"���オ���_)
void displayBlock(int x, int y, color color)
{
	glColor3dv(colors2[color]);
	glBegin(GL_QUADS);
	glVertex2d((width + frame / 2 + x)*size, (frame / 2 + y)*size);
	glVertex2d((width + frame / 2 + x + 1)*size, (frame / 2 + y)*size);
	glVertex2d((width + frame / 2 + x + 1)*size, (frame / 2 + y + 1)*size);
	glVertex2d((width + frame / 2 + x)*size, (frame / 2 + y + 1)*size);
	glEnd();
	glColor3dv(colors[color]);
	glBegin(GL_QUADS);
	glVertex2d((width + frame / 2 + x + 0.1)*size, (frame / 2 + y + 0.1)*size);
	glVertex2d((width + frame / 2 + x + 0.9)*size, (frame / 2 + y + 0.1)*size);
	glVertex2d((width + frame / 2 + x + 0.9)*size, (frame / 2 + y + 0.9)*size);
	glVertex2d((width + frame / 2 + x + 0.1)*size, (frame / 2 + y + 0.9)*size);
	glEnd();
}

void displayField()
{
	for (int i = -1; i <= width; ++i) {
		for (int j = -1; j <= height; ++j) {
			glColor3dv(colors[(i == -1 || j == -1 || i == width || j == height) ? Gray : Black]);
			glBegin(GL_QUADS);
			glVertex2d((width + frame / 2 + i)*size, (frame / 2 + j)*size);
			glVertex2d((width + frame / 2 + i + 1)*size, (frame / 2 + j)*size);
			glVertex2d((width + frame / 2 + i + 1)*size, (frame / 2 + j + 1)*size);
			glVertex2d((width + frame / 2 + i)*size, (frame / 2 + j + 1)*size);
			glEnd();
		}
	}
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(0, (width * 3 + frame)*size, (height + frame)*size, 0, -1, 1);
}

// �}�E�X�̋���������
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		break;
	case GLUT_RIGHT_BUTTON:
		break;
	default:
		break;
	}
}

// �L�[�{�[�h�̋���������
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':
	case 'Q':
	case '\033':
		exit(0);
	default:
		break;
	}

}

// ����L�[�������ꂽ�Ƃ��̋���������
void keyboard2(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP: // ��L�[
		break;
	case GLUT_KEY_DOWN: // ���L�[
		cout << "down\n";
		++crdnt;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT: // ���L�[
		break;
	case GLUT_KEY_RIGHT: // �E�L�[
		break;
	default:
		break;
	}
}