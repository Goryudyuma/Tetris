#include <GL/glut.h>
#include "common.h"

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(750, 500);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard2);
	glutTimerFunc(500,timer,0); // �^�C�}�[�B�P�ڂ̈����̓~���b�B�Ō�̈�����timer()�ɓn������
	glutIdleFunc(idle);
	glClearColor(0.9, 0.9, 0.9, 1.0);
	SHOKIKA();
	glutMainLoop();
}