#include<Windows.h>
#include<windowsx.h>
#include<tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HBRUSH hPaleyellowBrush, hYellowBrush, hBrownBrush;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hMainWnd;
	TCHAR szClassName[] = _T("MyClass");
	MSG msg;
	WNDCLASSEX wc;
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 205));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassExW(&wc)) {
		MessageBoxW(NULL, _T("Cannot registr class"), _T("Error"), MB_OK);
		return 0;
	}
	hMainWnd = CreateWindow(szClassName, _T("Zadanie A22"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,
		hInstance, NULL);

	ShowWindow(hMainWnd, nCmdShow);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	switch (uMsg) {
	case WM_CREATE:
		hPaleyellowBrush = CreateSolidBrush(RGB(255, 255, 224));
		hYellowBrush = CreateSolidBrush(RGB(255, 255, 0));
		hBrownBrush = CreateSolidBrush(RGB(139, 69, 19));
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SelectBrush(hdc, hPaleyellowBrush);
		Rectangle(hdc, 0, 0, 400, 400);
		SelectBrush(hdc, hYellowBrush);
		Rectangle(hdc, 100, 100, 400, 400);
		SelectBrush(hdc, hBrownBrush);
		Rectangle(hdc, 200, 200, 400, 400);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		DeleteObject(hPaleyellowBrush);
		DeleteObject(hYellowBrush);
		DeleteObject(hBrownBrush);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;

}