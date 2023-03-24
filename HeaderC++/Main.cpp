#include "littletools.h"
#include "windowstools.h"

using namespace ltools;
using namespace wintools::consle;
using namespace std;

string Languege;

void EnglishMain()
{
	cCls();
	cout << "Hello! Welcome to the SomeHeaders tutorial program!";
	cPause();
	return;
}

void ChineseMain()
{
	cCls();
	cout << "你好！欢迎查看SomeHeaders教程程序！";
	cPause();
	return;
}

void ProgramMain()
{
	cout << "Please Input A Languege:\(Chinese/English\)";
	cin >> Languege;
	if (Languege == "Chinese")
	{
		ChineseMain();
		return;
	}
	else if (Languege == "English")
	{
		EnglishMain();
		return;
	}
	else
	{
		throw runtime_error("X");
		exit(1);
	}
}

int main() 
{
	ProgramMain();
	return 0;
}