// ��O�̂ЂȌ`�N���X�B
// ��O��V�K�쐬����Ƃ��͂�����p�����Ă�������

#ifndef ___SUPER_EXCEPTION___
#define ___SUPER_EXCEPTION___
#include <string>
#include <iostream>
using namespace std;

class Exception
{
protected:
	string message;
public:

	// ���b�Z�[�W�ȂǕϐ��̏��������s���ꏊ
	Exception()
	{
		message = "\a�G���[�������ɕ\�����郁�b�Z�[�W����͂��邱�ƁB\n";
	}

	virtual ~Exception() {};

	// �G���[���L���b�`�����Ƃ��ɍs������
	virtual void handling() = 0;
};

#endif