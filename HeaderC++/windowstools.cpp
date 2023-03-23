#include "windowstools.h"

HCRYPTPROV prov;

//About MessageBox

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

void MsgQuestionA(LPCSTR lpTitle, LPCSTR lpInfo)
{
	MsgBoxA(lpTitle, lpInfo, 0x00000020L);
}

void MsgQuestionW(LPCWSTR lpTitle, LPCWSTR lpInfo)
{
	MsgBoxW(lpTitle, lpInfo, 0x00000020L);
}

//About Window

void sHideWindow(HWND hwnd)
{
	ShowWindow(hwnd, SW_HIDE);
}

void sShowWindow(HWND hwnd)
{
	ShowWindow(hwnd, SW_SHOW);
}

void sMinWindow(HWND hwnd)
{
    ShowWindow(hwnd, SW_SHOWMINIMIZED);
}

void sMaxWindow(HWND hwnd)
{
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

//About Random

int RealRandom()
{
    if (prov == NULL)
    {
        if (!CryptAcquireContext(&prov, NULL, NULL, PROV_RSA_FULL, CRYPT_SILENT | CRYPT_VERIFYCONTEXT))
        {
            ExitProcess(1);
        }         
    }       
    int out;
    CryptGenRandom(prov, sizeof(out), (BYTE*)(&out));
    return out & 0x7fffffff;
}


