#include <iostream>
#include <GL/glut.h>
#include "common.h"
using namespace std;

int main(int argc, char** argv)
{
	cout << "\aYour name : ";
	cin >> name;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(750, 500);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(hantei);
	glutTimerFunc(msec,timer,SENTINEL); // �^�C�}�[�B�P�ڂ̈����̓~���b�B�Ō�̈�����timer()�ɓn������
	glClearColor(0.9, 0.9, 0.9, 1.0);
	glutMainLoop();

	return 0;
}