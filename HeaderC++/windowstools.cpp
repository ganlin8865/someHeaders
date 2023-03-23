#include "windowstools.h"

HCRYPTPROV prov;

//About MessageBox

void wintools::msgbox::MsgBoxW(LPCWSTR lpTitle, LPCWSTR lpInfo, UINT uTypename)
{
	MessageBoxW(NULL, lpInfo, lpTitle, uTypename);
}

void wintools::msgbox::MsgBoxA(LPCSTR lpTitle, LPCSTR lpInfo, UINT uTypename)
{
	MessageBoxA(NULL, lpInfo, lpTitle, uTypename);
}

void wintools::msgbox::MsgErrorA(LPCSTR lpTitle, LPCSTR lpInfo)
{
	wintools::msgbox::MsgBoxA(lpTitle, lpInfo, 0x00000010L);
}

void wintools::msgbox::MsgErrorW(LPCWSTR lpTitle, LPCWSTR lpInfo)
{
	wintools::msgbox::MsgBoxW(lpTitle, lpInfo, 0x00000010L);
}

void wintools::msgbox::MsgWarningA(LPCSTR lpTitle, LPCSTR lpInfo)
{
	wintools::msgbox::MsgBoxA(lpTitle, lpInfo, 0x00000030L);
}

void wintools::msgbox::MsgWarningW(LPCWSTR lpTitle, LPCWSTR lpInfo)
{
	wintools::msgbox::MsgBoxW(lpTitle, lpInfo, 0x00000030L);
}

void wintools::msgbox::MsgInfoA(LPCSTR lpTitle, LPCSTR lpInfo)
{
	wintools::msgbox::MsgBoxA(lpTitle, lpInfo, 0x00000040L);
}

void wintools::msgbox::MsgInfoW(LPCWSTR lpTitle, LPCWSTR lpInfo)
{
	wintools::msgbox::MsgBoxW(lpTitle, lpInfo, 0x00000040L);
}

void wintools::msgbox::MsgQuestionA(LPCSTR lpTitle, LPCSTR lpInfo)
{
	wintools::msgbox::MsgBoxA(lpTitle, lpInfo, 0x00000020L);
}

void wintools::msgbox::MsgQuestionW(LPCWSTR lpTitle, LPCWSTR lpInfo)
{
	wintools::msgbox::MsgBoxW(lpTitle, lpInfo, 0x00000020L);
}

//About Window

void wintools::window::sHideWindow(HWND hwnd)
{
	ShowWindow(hwnd, SW_HIDE);
}

void wintools::window::sShowWindow(HWND hwnd)
{
	ShowWindow(hwnd, SW_SHOW);
}

void wintools::window::sMinWindow(HWND hwnd)
{
    ShowWindow(hwnd, SW_SHOWMINIMIZED);
}

void wintools::window::sMaxWindow(HWND hwnd)
{
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

void wintools::window::sHideForeWindow()
{
	HWND hForegroundWindow = GetForegroundWindow();
	wintools::window::sHideWindow(hForegroundWindow);
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

//About PlayTone

void PlayError()
{
	MessageBeep(0x00000010L);
}

void PlayWarning()
{
	MessageBeep(0x00000030L);
}

void PlayInfo()
{
	MessageBeep(0x00000040L);
}

void PlayQuestion()
{
	MessageBeep(0x00000020L);
}



