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

// �����W
extern char* numbers;

// �X�R�A�\���p
// �����̓X�R�A(�}�C�i�X�͍l�����Ȃ�)
void displayScore(int score);

// �}�E�X
void mouse(int button, int state, int x, int y);
// �L�[�{�[�h(�ʏ�)
void keyboard(unsigned char key, int x, int y);
// �L�[�{�[�h(�����L�[�ȂǓ���L�[)
void keyboard2(int key, int x, int y);

// �u���b�N�`��(���㌴�_)
void displayBlock(int x, int y, color color);

// �t�B�[���h�`��
void displayField();

// �`��̍ۂɌĂяo�����֐�
void display();

// ���Ԍo�߂ŌĂяo�����֐�
// int�^�̈������󂯎���
// glutTimerFunc()�̂ق��Ŏ��ԂȂǂ͎w�肷��
void timer(int value);

// �A�j���[�V����
void idle();

// ���T�C�Y
void resize(int w, int h);

//������
void SHOKIKA();

#endif