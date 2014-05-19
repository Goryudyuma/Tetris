#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <GL/glut.h>
#include "common.h"
using namespace std;
#define GLUT_SLEEP 13


double colors[][3] = {
	{ 0.2, 0.2, 0.2 },
	{ 0.4, 0.4, 0.4 },
	{ 0.0, 1.0, 1.0 },
	{ 1.0, 1.0, 0.0 },
	{ 0.67, 1.0, 0.02 },
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 0.64, 0.0 },
	{ 0.71, 0.0, 0.71 }
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
	{ 0.51, 0.0, 0.51 }
};


char* title = "Tetris";

char* numbers = "0123456789";


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

	color hairetsu[2][12][22]; 
	color c=(color)1,d=(color)0;
	color Block[7][4][4];
	color Block2[7][4][4] = {
		{
			{ d, d, d, d },
			{ d, d, d, d },
			{ c, c, c, c },
			{ d, d, d, d },
		},
		{
			{ d, d, d, d },
			{ d, c, c, d },
			{ d, c, c, d },
			{ d, d, d, d },
		},
		{
			{ d, d, d, d },
			{ d, c, c, d },
			{ c, c, d, d },
			{ d, d, d, d },
		},
		{
			{ d, d, d, d },
			{ c, c, d, d },
			{ d, c, c, d },
			{ d, d, d, d },
		},
		{
			{ c, d, d, d },
			{ c, c, c, d },
			{ d, d, d, d },
			{ d, d, d, d },
		},
		{
			{ d, d, c, d },
			{ c, c, c, d },
			{ d, d, d, d },
			{ d, d, d, d },
		},
		{
			{ d, c, d, d },
			{ c, c, c, d },
			{ d, d, d, d },
			{ d, d, d, d },
		}
	};
	color BlockMove[4][4];
	int dyuma_flag[10];
	int x, y,z;
	int houkou;
	int tensuu;
}

void irekae(int i, int j){
	BlockMove[i][j] = (color)(z+2 - BlockMove[i][j]);
}

void kaiten_2(){
	color dyuma_color;
	dyuma_color = BlockMove[0][0];
	BlockMove[0][0] = BlockMove[0][2];
	BlockMove[0][2] = BlockMove[2][2];
	BlockMove[2][2] = BlockMove[2][0];
	BlockMove[2][0] = dyuma_color;
	dyuma_color = BlockMove[0][1];
	BlockMove[0][1] = BlockMove[1][2];
	BlockMove[1][2] = BlockMove[2][1];
	BlockMove[2][1] = BlockMove[1][0];
	BlockMove[1][0] = dyuma_color;
}


void SHOKIKA(){
	srand((unsigned)time(NULL));

	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 4; k++){
				if (Block2[i][j][k]){
					Block[i][j][k] = (color)(i + 2);
				}
			}
		}
	}
	tensuu = 0;
}

int Judge(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (BlockMove[i][j] != 0){
				if (hairetsu[1][i + x][j + y] != 0){
					return 1;
				}
				if (x + i>10 || x + i<1 || y + j>20 || y + j < 0){
					return 1;
				}
			}
		}
	}
	return 0;
}

void kaiten(int j){
	switch (z){
	case 0:irekae(0, 1);
		irekae(1, 1);
		irekae(3, 1);
		irekae(2, 0);
		irekae(2, 2);
		irekae(2, 3);
	case 1:
		break;
	default:
		kaiten_2();
		break;
	}
	if (Judge() == 1&&j!=1){
		for (int i = 0; i < 3; i++){
			kaiten(1);
		}
	}
}

void makeBlock(){
	x = 4;
	y = 0;
	z = rand() % 7;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			BlockMove[i][j] = Block[z][i][j];
		}
	}
	if (Judge() == 1){
		cout << "GameOver!" << "\n" << tensuu << "�_�ł����I";
		exit(0);
	}
	dyuma_flag[0] = 1;
}

void kurikaeshi(int j){
	int flag3=0;
	for (int i = 1; i <= 10; i++){
		if (hairetsu[0][i][j] != 0){
			flag3++;
		}
	}
	if (flag3 == 10){
		dyuma_flag[2]++;
		kurikaeshi(j-1);
	}
}

int tensuukeisann(int i){
	if (i == 1){
		return 1;
	}
	else{
		return tensuukeisann(i - 1)*2;
	}
}

void Del_Judge(){
	dyuma_flag[2] = 0;
	dyuma_flag[3] = 20;
	for (int j = 20; j >= 1 + dyuma_flag[2]; j--){
		
		if (dyuma_flag[2]+j <=  dyuma_flag[3]){
			kurikaeshi(j);
			dyuma_flag[3] = j;
		}
		for (int k = 1; k <= 10; k++){
			hairetsu[0][k][j] = hairetsu[0][k][j - dyuma_flag[2]];
			hairetsu[1][k][j] = hairetsu[1][k][j - dyuma_flag[2]];
		}
	}
	if (dyuma_flag[2] != 0){
		tensuu += tensuukeisann(dyuma_flag[2])*10;
	}
	cout << "\n" << tensuu;
}

int hantei(){
	switch (houkou) {
	case GLUT_KEY_UP: // ��L�[
		cout << "up\n";
		kaiten(0);
		break;
	case GLUT_KEY_DOWN: // ���L�[
	case GLUT_SLEEP: // �҃L�[
		cout << "down\n";
		if (dyuma_flag[0] == 0){
			makeBlock();
		}
		else{
			y++;
			if (Judge() == 1){
				y--;
				/*�Œ艻����������*/
				for (int i = 0; i < 4; i++){
					for (int j = 0; j < 4; j++){
						if (BlockMove[i][j] != 0){
							hairetsu[1][x + i][y + j] = BlockMove[i][j];
						}
					}
				}
				dyuma_flag[0] = 0;
			}
		}
		break;
	case GLUT_KEY_LEFT: // ���L�[
		cout << "left\n";
		x--;
		if (Judge() == 1){
			x++;
		}
		break;
	case GLUT_KEY_RIGHT: // �E�L�[
		cout << "right\n";
		x++;
		if (Judge() == 1){
			x--;
		}
		break;
	default:
		break;
	}
	
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 20; j++){
			hairetsu[0][i][j] = hairetsu[1][i][j];
		}
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (BlockMove[i][j]){
				hairetsu[0][i + x][j + y] = BlockMove[i][j];
			}
		}
	}
	if (dyuma_flag[0] == 0){
		Del_Judge(); 
	}
	return 0;
}

// �����ɕ`��̏���������
void display()
{
	if (hantei() == 0){
		glClear(GL_COLOR_BUFFER_BIT);
		displayField();
		displayScore(0); // �����ɃX�R�A��n���Ă�������

		// �����ɕ`��̏���������
		int i, j;
		for (i = 1; i <= 10; i++){
			for (j = 1; j <= 20; j++){
				displayBlock(i - 1, j - 1, hairetsu[0][i][j]);
			}
		}
		

		glutSwapBuffers();
	}
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

	houkou = GLUT_SLEEP;
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
/*	switch (key) {
	case GLUT_KEY_UP: // ��L�[
		break;
	case GLUT_KEY_DOWN: // ���L�[
		cout << "down\n";
		break;
	case GLUT_KEY_LEFT: // ���L�[
		break;
	case GLUT_KEY_RIGHT: // �E�L�[
		break;
	default:
		break;
	}
*/
	houkou = key;
	glutPostRedisplay();
}


// �X�R�A�\���p
// �����̓X�R�A
void displayScore(int score)
{
	glColor3dv(colors[Black]);
	glRasterPos2d(size * 3 / 5, size);
	for (char* str = title; *str; str++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);
	}

	int pos = 5;
	for (int i = 0; i < width; i += width - 2) {
		glBegin(GL_LINES);
		glVertex2d((i + 1.0 / 2.0)*size, pos*size);
		glVertex2d((i + 1.0 / 2.0)*size, (pos + 3)*size);
		glEnd();
	}

	glBegin(GL_LINES);
	glVertex2d((width - 1.5)*size, pos*size);
	glVertex2d((width - 1.5)*size, (pos - 0.5)*size);
	glVertex2d((width - 1.5)*size, (pos - 0.5)*size);
	glVertex2d((width - 2.5)*size, (pos - 0.5)*size);
	glVertex2d(size / 2.0, (pos + 3)*size);
	glVertex2d((width - 1.5)*size, (pos + 3)*size);
	glEnd();

	glRasterPos2d(size, (pos - 1.0 / 5.0)*size);
	for (char* str = "SCORE"; *str; str++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);
	}

	int num[size] = { 0 };
	for (int i = 1; i < size; i++) {
		num[i] = SENTINEL;
	}
	int i;
	for (i = 0; score; i++) {
		num[i] = score % 10;
		score /= 10;
	}
	if (i) {
		i--;
	}
	
	glRasterPos2d(size * 2, (pos + 9.0 / 5.0)*size);
	while (i >= 0) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[num[i--]]);
	}
}