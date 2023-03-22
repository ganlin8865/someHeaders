#include "windowstools.h"

void sHideWindow(HWND hwnd)
{
	ShowWindow(hwnd, SW_HIDE);
}

void sShowWindow(HWND hwnd)
{
	ShowWindow(hwnd, SW_SHOW);
}
