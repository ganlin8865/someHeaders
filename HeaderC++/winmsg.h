#pragma once
#ifndef WINMSG_H
#define WINMSG_H

#include <Windows.h>

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

#ifdef UNICODE
#define MessageBoxTimeout MessageBoxTimeoutW
#define MsgBox MsgBoxW
#define MsgError MsgErrorW
#define MsgWarning MsgWarningW
#define MsgInfo MsgInfoW
#define MsgQuestion MsgQuestionW
#else
#define MessageBoxTimeout MessageBoxTimeoutA
#define MsgBox MsgBoxA
#define MsgError MsgErrorA
#define MsgWarning MsgWarningA
#define MsgInfo MsgInfoA
#define MsgQuestion MsgQuestionW
#endif

#endif