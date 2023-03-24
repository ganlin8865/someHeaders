#pragma once
#ifndef WINDOWSTOOLS_H
#define WINDOWSTOOLS_H

#include <windows.h>
#include <cstdlib>
#include <string>

//About MessageBox

extern "C"
{
	int WINAPI MessageBoxTimeoutA(IN HWND hwnd, IN LPCSTR lpText, IN LPCSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
	int WINAPI MessageBoxTimeoutW(IN HWND hwnd, IN LPCWSTR lpText, IN LPCWSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
}

enum Color 
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

enum Soft
{
	NOTEPAD,
	MSPAINT,
	CALC,
	WRITE
};

namespace wintools
{
	//About MsgBox
	namespace msgbox
	{
		void MsgBoxA(LPCSTR lpTitle, LPCSTR lpInfo, UINT uTypename);
		void MsgBoxW(LPCWSTR lpTitle, LPCWSTR lpInfo, UINT uTypename);

		void MsgErrorA(LPCSTR lpTitle, LPCSTR lpInfo);
		void MsgErrorW(LPCWSTR lpTitle, LPCWSTR lpInfo);

		void MsgWarningA(LPCSTR lpTitle, LPCSTR lpInfo);
		void MsgWarningW(LPCWSTR lpTitle, LPCWSTR lpInfo);

		void MsgInfoA(LPCSTR lpTitle, LPCSTR lpInfo);
		void MsgInfoW(LPCWSTR lpTitle, LPCWSTR lpInfo);

		void MsgQuestionA(LPCSTR lpTitle, LPCSTR lpInfo);
		void MsgQuestionW(LPCWSTR lpTitle, LPCWSTR lpInfo);
	}
	//About Window
	namespace window
	{
		void sHideWindow(HWND hWindow);
		void sShowWindow(HWND hWindow);
		void sMinWindow(HWND hWindow);
		void sMaxWindow(HWND hWindow);
		void sHideForeWindow();
	}
	namespace consle
	{
		void cSetColor(Color Foreground,Color Background);
		void cCls();
		void cPause();
		void cOpenSoft(Soft Software);
		void cSetTitle(LPCWSTR Title);
	}
	namespace playtone
	{
		void PlayError();
		void PlayWarning();
		void PlayInfo();
		void PlayQuestion();
	}
}

//About RealRandom

int RealRandom();

#endif 