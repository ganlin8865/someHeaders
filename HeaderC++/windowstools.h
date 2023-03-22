#pragma once
#ifndef WINDOWSTOOLS_H
#define WINDOWSTOOLS_H

#include <windows.h>

//About Window

void sHideWindow(HWND hwnd);
void sShowWindow(HWND hwnd);
void sMinWindow(HWND hwnd);
void sMaxWindow(HWND hwnd);


//About RealRandom

int RealRandom();

#endif 
