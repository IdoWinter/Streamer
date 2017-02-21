#include "stdafx.h"
#include "ScreenCapture.h"

RGBQUAD *getBitmap(int screenWidth, int screenHeight)
{
	HWND hDesktopWnd = GetDesktopWindow();
	HDC hDesktopDC = GetDC(hDesktopWnd);
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	HBITMAP hBmp = CreateCompatibleBitmap(GetDC(0), screenWidth, screenHeight);
	SelectObject(hCaptureDC, hBmp);
	BitBlt(hCaptureDC, 0, 0, screenWidth, screenHeight, hDesktopDC, 0, 0, SRCCOPY | CAPTUREBLT);
	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = screenWidth;
	bmi.bmiHeader.biHeight = screenHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	RGBQUAD *pPixels = new RGBQUAD[screenWidth*screenHeight];
	GetDIBits(hCaptureDC, hBmp, 0, screenHeight, pPixels, &bmi, DIB_RGB_COLORS);

	ReleaseDC(hDesktopWnd, hDesktopDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hBmp);

	return pPixels;
}
