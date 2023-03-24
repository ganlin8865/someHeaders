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

void wintools::window::sHideWindow(HWND hWindow)
{
	ShowWindow(hWindow, SW_HIDE);
}

void wintools::window::sShowWindow(HWND hWindow)
{
	ShowWindow(hWindow, SW_SHOW);
}

void wintools::window::sMinWindow(HWND hWindow)
{
    ShowWindow(hWindow, SW_SHOWMINIMIZED);
}

void wintools::window::sMaxWindow(HWND hWindow)
{
    ShowWindow(hWindow, SW_SHOWMAXIMIZED);
}

void wintools::window::sHideForeWindow()
{
	HWND hForegroundWindow = GetForegroundWindow();
	wintools::window::sHideWindow(hForegroundWindow);
}

//About Consle

void wintools::consle::cSetColor(Color ForegroundColor, Color BackgroundColor)
{
    std::string command = "color ";
    if (BackgroundColor <= 9) 
    {
        command += std::to_string(BackgroundColor);
    }
    else 
    {
        command += 'A' + (BackgroundColor - 10);
    }
    if (ForegroundColor <= 9) 
    {
        command += std::to_string(ForegroundColor);
    }
    else 
    {
        command += 'A' + (ForegroundColor - 10);
    }
    system(command.c_str());
}

void wintools::consle::cCls()
{
    system("CLS");
}

void wintools::consle::cPause()
{
    system("PAUSE");
}

void wintools::consle::cOpenSoft(Soft Software)
{
    switch (Software)
    {
    case NOTEPAD : system("NOTEPAD"); break;
    case MSPAINT : system("MSPAINT"); break;
    case CALC : system("CALC"); break;
    case WRITE: system("WRITE"); break;
    }
}

void wintools::consle::cSetTitle(LPCWSTR Title)
{
    SetConsoleTitle(Title);
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

void wintools::playtone::PlayError()
{
	MessageBeep(0x00000010L);
}

void wintools::playtone::PlayWarning()
{
	MessageBeep(0x00000030L);
}

void wintools::playtone::PlayInfo()
{
	MessageBeep(0x00000040L);
}

void wintools::playtone::PlayQuestion()
{
	MessageBeep(0x00000020L);
}