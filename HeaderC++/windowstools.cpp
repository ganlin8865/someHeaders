#include "windowstools.h"

HCRYPTPROV prov;

void sHideWindow(HWND hwnd)
{
	ShowWindow(hwnd, SW_HIDE);
}

void sShowWindow(HWND hwnd)
{
	ShowWindow(hwnd, SW_SHOW);
}

int RealRandom()
{
    if (prov == NULL)
            if (!CryptAcquireContext(&prov, NULL, NULL, PROV_RSA_FULL, CRYPT_SILENT | CRYPT_VERIFYCONTEXT))
                ExitProcess(1);
        int out;
        CryptGenRandom(prov, sizeof(out), (BYTE*)(&out));
        return out & 0x7fffffff;
}
