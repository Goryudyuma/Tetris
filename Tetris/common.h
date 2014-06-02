#ifndef ___COMMONHEADER___
#define ___COMMONHEADER___

// �ԕ�
const int SENTINEL = -1;

// z_R[]�̗v�f��
const unsigned zrnum = 3;

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

// �L�[�{�[�h(�ʏ�)
void keyboard(unsigned char key, int x, int y);
// �L�[�{�[�h(�����L�[�ȂǓ���L�[)
void hantei(int hantei, int x0, int y0);

// �u���b�N�`��(���㌴�_)
template <class Type> void displayBlock(int x, int y, Type col);
// �S�[�X�g�u���b�N�`��(���㌴�_)
template <class Type> void displayGhostBlock(int x, int y, Type col);

// �`��̍ۂɌĂяo�����֐�
void display();

// ���Ԍo�߂ŌĂяo�����֐�
// int�^�̈��������R�Ɏ󂯎���
// glutTimerFunc()�̂ق��Ŏ��ԂȂǂ͎w�肷��
void timer(int value);

// ���T�C�Y
void resize(int w, int h);

#endif