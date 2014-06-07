#ifndef ___COMMONHEADER___
#define ___COMMONHEADER___

#include <string>
using namespace std;

// �ԕ�
const int SENTINEL = -1;

// z_R[]�̗v�f��
const unsigned zrnum = 3;

// �t�B�[���h�̉���(�u���b�N������)
const int width = 10;
// �t�B�[���h�̏c��(�u���b�N������)
const int height = 20;

// �u���b�N�̃f�[�^
const int Block[][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 2, 2, 2, 2 },
		{ 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 3, 3, 0 },
		{ 0, 3, 3, 0 },
		{ 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 4, 4, 0 },
		{ 4, 4, 0, 0 },
		{ 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 0, 0 },
		{ 5, 5, 0, 0 },
		{ 0, 5, 5, 0 },
		{ 0, 0, 0, 0 },
	},
	{
		{ 6, 0, 0, 0 },
		{ 6, 6, 6, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 7, 0 },
		{ 7, 7, 7, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	},
	{
		{ 0, 8, 0, 0 },
		{ 8, 8, 8, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	}
};

// �F�w��p�񋓑�
// �Ō��Invalid�Ƃ���BInvalid�������ɗ^�������̋����͕ۏ؂��Ȃ�
enum color { Black, Gray, Aqua, Yellow, Green, Red, Blue, Orange, Purple, Invalid };

// �^�C�g��
extern char* title;

// ���~���b���Ƃɗ����Ă��邩
extern int msec;

// ���F��
extern string name;

// �t�@�C����
extern char* file;


// �����������ŕ`�悷�ׂ����̂�����֐�
// �X�R�A�̕\���AHOLD�̕\���ANEXT�̕\���ƃt�B�[���h��̃u���b�N�`���S������B
void inner_display();



// �ȉ�openGL�֘A

// �X�R�A�\���p
// �����̓X�R�A(�}�C�i�X�͍l�����Ȃ�)
void displayScore(int score);

// HOLD�\���p
// �����͏�L��Block[i][][]��i�Ńu���b�N�̌`���w��
void displayHold(int num);

// NEXT�\���p
// �����͎��ɗ����Ă���u���b�N�A���̎��ɗ����Ă���u���b�N�E�E�E�Ƃ������w��ł���B
// �����ɉ����w�肵�Ȃ������ꍇ��next����\���ɂȂ�
void displayNext(int next = SENTINEL, ...);

// HIGH-SCORE�\���p
void displayHighScore();

// �L�[�{�[�h(�ʏ�)
void keyboard(unsigned char key, int x, int y);
// �L�[�{�[�h(�����L�[�ȂǓ���L�[)
void hantei(int hantei, int x0, int y0);

// �u���b�N�`��(���㌴�_)
// �R�ڂ̈����͐F�̎w��Bint��color�^���w��ł���
void displayBlock(int x, int y, int col);
void displayBlock(int x, int y, color col);

// �S�[�X�g�u���b�N�`��(���㌴�_)
// �R�ڂ̈����͐F�̎w��Bint��color�^���w��ł���B
void displayGhostBlock(int x, int y, int col);
void displayGhostBlock(int x, int y, color col);

// �`��̍ۂɌĂяo�����֐�
void display();

// ���Ԍo�߂ŌĂяo�����֐�
// int�^�̈��������R�Ɏ󂯎���
// glutTimerFunc()�̂ق��Ŏ��ԂȂǂ͎w�肷��
void timer(int value);

// ���T�C�Y
void resize(int w, int h);

#endif