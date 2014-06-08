#ifndef ___SCORE_FILE_ERROR___
#define ___SCORE_FILE_ERROR___
#include <cstdlib>
#include <fstream>
#include "Exception.h"
#include "common.h"
using namespace std;

class ScoreFileError :
	public Exception
{
public:
	ScoreFileError()
	{
		message = "\a���̃Z�[�u�f�[�^�͕s���ł��B\n�I�����܂��B�������͂��Ă��������F";
	}

	~ScoreFileError() {};

	void handling()
	{
		cout << message;

		while (!getchar());

		ofstream ofs(file, ios::binary);
		ofs;

		exit(1);
	}
};

#endif