#pragma once
#ifndef WINDOWSTOOLS_H
#define WINDOWSTOOLS_H

#include <windows.h>

//About MessageBox

extern "C"
{
	int WINAPI MessageBoxTimeoutA(IN HWND hwnd, IN LPCSTR lpText, IN LPCSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
	int WINAPI MessageBoxTimeoutW(IN HWND hwnd, IN LPCWSTR lpText, IN LPCWSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
}

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

//About Window

void sHideWindow(HWND hwnd);
void sShowWindow(HWND hwnd);
void sMinWindow(HWND hwnd);
void sMaxWindow(HWND hwnd);

//About RealRandom

int RealRandom();

#endif 
