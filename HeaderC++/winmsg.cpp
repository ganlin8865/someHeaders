#include "winmsg.h"

void MsgBoxW(LPCWSTR lpTitle, LPCWSTR lpInfo, UINT uTypename)
{
	MessageBoxW(NULL, lpInfo, lpTitle, uTypename);
}

void MsgBoxA(LPCSTR lpTitle, LPCSTR lpInfo, UINT uTypename)
{
	MessageBoxA(NULL, lpInfo, lpTitle, uTypename);
}

void MsgErrorA(LPCSTR lpTitle, LPCSTR lpInfo)
{
	MsgBoxA(lpTitle, lpInfo, 0x00000010L);
}

void MsgErrorW(LPCWSTR lpTitle, LPCWSTR lpInfo)
{
	MsgBoxW(lpTitle, lpInfo, 0x00000010L);
}

void MsgWarningA(LPCSTR lpTitle, LPCSTR lpInfo)
{
	MsgBoxA(lpTitle, lpInfo, 0x00000030L);
}

void MsgWarningW(LPCWSTR lpTitle, LPCWSTR lpInfo)
{
	MsgBoxW(lpTitle, lpInfo, 0x00000030L);
}

void MsgInfoA(LPCSTR lpTitle, LPCSTR lpInfo)
{
	MsgBoxA(lpTitle, lpInfo, 0x00000040L);
}

void MsgInfoW(LPCWSTR lpTitle, LPCWSTR lpInfo)
{
	MsgBoxW(lpTitle, lpInfo, 0x00000040L);
}