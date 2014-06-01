#ifndef ___COMMONHEADER___
#define ___COMMONHEADER___

// �ԕ�
const int SENTINEL = -1;

// �F�w��p�񋓑�
enum color { Black, Gray, Aqua, Yellow, Green, Red, Blue, Orange, Purple };
// �F�z��
extern double colors[][3];
// �P�i�K�Â��F
extern double colors2[][3];

// �^�C�g��
extern char* title;

// �X�R�A�\���p
// �����̓X�R�A(�}�C�i�X�͍l�����Ȃ�)
void displayScore(int score);

// HOLD�\���p
void displayHold(int num);

// NEXT�\���p
void displayNext(int next1, int next2, int next3);

// �L�[�{�[�h(�ʏ�)
void keyboard(unsigned char key, int x, int y);
// �L�[�{�[�h(�����L�[�ȂǓ���L�[)
void hantei(int hantei, int x0, int y0);

// �u���b�N�`��(���㌴�_)
template <class Type> void displayBlock(int x, int y, Type col);
// �S�[�X�g�u���b�N�`��(���㌴�_)
template <class Type> void displayGhostBlock(int x, int y, Type col);

// �t�B�[���h�`��
void displayField();

// �`��̍ۂɌĂяo�����֐�
void display();

// ���Ԍo�߂ŌĂяo�����֐�
// int�^�̈������󂯎���
// glutTimerFunc()�̂ق��Ŏ��ԂȂǂ͎w�肷��
void timer(int value);

// ���T�C�Y
void resize(int w, int h);

#endif