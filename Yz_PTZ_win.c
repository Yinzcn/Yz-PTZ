
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <windowsx.h>
#define _WIN32_IE 0x0501
#include <commctrl.h>
#include <richedit.h>

#include <olectl.h>
#include <ole2.h>

#include "butn.c"
#include "pelco_d.c"
#include "wMsgToStr.c"


HANDLE hFile;
char Addr = 0;

HWND hAddr = 0,
	 hData = 0,
	 Button_S,
	 Button_R,
	 Button_L,
	 Button_U,
	 Button_D,
	 Button_UR,
	 Button_DR,
	 Button_DL,
	 Button_UL,
	 Button_ZT,
	 Button_ZW,
	 Button_FF,
	 Button_FN,
	 Button_IO,
	 Button_IC,
	 Button_SET_PRE,
	 Button_CLR_PRE,
	 Button_GET_PRE;


LRESULT CALLBACK
KeyboardProc(int code, WPARAM wParam, LPARAM lParam)
{
    char prev_state = lParam >> 30 & 1;
    char tran_state = lParam >> 31 & 1;
    printf("KeyboardProc %d, %d, p%d t%d\n", code, wParam, prev_state, tran_state);
    return 0;
}


int
get_wnd_dec(HWND hwnd)
{
	char buff[64];
	GetWindowText(hwnd, buff, sizeof(buff));
	return atoi(buff);
}


UINT
msg_trans(UINT msg, WPARAM wParam)
{
    if (msg == WM_KEYDOWN && (char)wParam == 0x20) {
        return WM_LBUTTONDOWN;
    } else
    if (msg == WM_KEYUP && (char)wParam == 0x20) {
        return WM_LBUTTONUP;
    }
    return msg;
}


LRESULT CALLBACK
Button_Proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	char addr = get_wnd_dec(hAddr);
	int  data = get_wnd_dec(hData);
	if (hwnd == Button_S) {
        //printf("%20s %d %d\n", wMsgToStr(msg), wParam, lParam);
        switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_R) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_R, 0x2000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_L) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_L, 0x2000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_U) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_U, 0x0020);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
        }
	} else
	if (hwnd == Button_D) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_D, 0x0020);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_UR) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_U | PD_R, 0x2020);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_DR) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_D | PD_R, 0x2020);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_UL) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_U | PD_L, 0x2020);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_DL) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_D | PD_L, 0x2020);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_ZT) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_ZT, 0x0000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_ZW) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_ZW, 0x0000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_FF) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_FF, 0x0000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_FN) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_FN, 0x0000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_IO) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_IO, 0x0000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_IC) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_IC, 0x0000);
				break;
			case WM_LBUTTONUP:
				PELCO_D_Send(hFile, addr, 0x0000, 0x0000);
				break;
		}
	} else
	if (hwnd == Button_SET_PRE) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_SET_PRE, data);
				break;
		}
	} else
	if (hwnd == Button_CLR_PRE) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_CLR_PRE, data);
				break;
		}
	} else
	if (hwnd == Button_GET_PRE) {
		switch (msg_trans(msg, wParam)) {
			case WM_LBUTTONDOWN:
				PELCO_D_Send(hFile, addr, PD_GET_PRE, data);
				break;
		}
	}

	return 0;
}


LRESULT CALLBACK
MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    //printf("%20s %d %d\n", wMsgToStr(msg), wParam, lParam);
	switch (msg) {
		case WM_CREATE:
		{
			int xscr, yscr;  
			RECT rect;  
			xscr = GetSystemMetrics(SM_CXSCREEN);  
			yscr = GetSystemMetrics(SM_CYSCREEN);  
			GetWindowRect(hwnd, &rect);  
			rect.left = (xscr - rect.right) / 2;  
			rect.top = (yscr - rect.bottom) / 2;  
			SetWindowPos(hwnd,
				HWND_TOP,
				rect.left,
				rect.top,
				rect.right,
				rect.bottom,
				SWP_SHOWWINDOW);
			break;
		}

        case WM_COMMAND:
            if (LOWORD(wParam) == 1) {
                Beep(40, 50);
            }
            break;

		case WM_CLOSE:
			DestroyWindow(hwnd);
			Close_Comm_Port(hFile);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


int APIENTRY
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	char AppName[] = "Yinz-PTZ PELCO";

	INITCOMMONCONTROLSEX icex;
	icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
	icex.dwICC = ICC_UPDOWN_CLASS | ICC_USEREX_CLASSES;
	InitCommonControlsEx(&icex);

	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof wcex);
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MainWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "YzWndClass";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wcex);

	hwnd = CreateWindowEx(WS_EX_WINDOWEDGE,
		"YzWndClass",
		AppName,
		WS_VISIBLE | WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_CLIPCHILDREN,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		320, 280,
		0,
		0,
		hInstance,
		0);

	Button_S  = Butn_Create(hwnd, "停", 144,  80, 28, 28, Button_Proc);
	Button_R  = Butn_Create(hwnd, "R",  184,  80, 28, 28, Button_Proc);
	Button_L  = Butn_Create(hwnd, "L",  104,  80, 28, 28, Button_Proc);
	Button_U  = Butn_Create(hwnd, "U",  144,  40, 28, 28, Button_Proc);
	Button_D  = Butn_Create(hwnd, "D",  144, 120, 28, 28, Button_Proc);
	Button_UR = Butn_Create(hwnd, "UR", 176,  48, 28, 28, Button_Proc);
	Button_DR = Butn_Create(hwnd, "DR", 176, 112, 28, 28, Button_Proc);
	Button_DL = Butn_Create(hwnd, "DL", 112, 112, 28, 28, Button_Proc);
	Button_UL = Butn_Create(hwnd, "UL", 112,  48, 28, 28, Button_Proc);

	Button_ZT = Butn_Create(hwnd, "ZT",  24, 152, 60, 24, Button_Proc);
	Button_ZW = Butn_Create(hwnd, "ZW",  24, 180, 60, 24, Button_Proc);
	Button_FF = Butn_Create(hwnd, "FF", 128, 152, 60, 24, Button_Proc);
	Button_FN = Butn_Create(hwnd, "FN", 128, 180, 60, 24, Button_Proc);
	Button_IO = Butn_Create(hwnd, "IO", 232, 152, 60, 24, Button_Proc);
	Button_IC = Butn_Create(hwnd, "IC", 232, 180, 60, 24, Button_Proc);

	Button_SET_PRE = Butn_Create(hwnd, "设预置", 240,  48, 52, 28, Button_Proc);
	Button_CLR_PRE = Butn_Create(hwnd, "清预置", 240,  80, 52, 28, Button_Proc);
	Button_GET_PRE = Butn_Create(hwnd, "调预置", 240, 112, 52, 28, Button_Proc);

	HWND hStatic1 = CreateWindow("static",
		"地址:",
		WS_VISIBLE | WS_CHILD | WS_TABSTOP, 
		24, 16, 56, 20,
		hwnd,
		NULL,
		hInstance,
		NULL);
	SendMessage(hStatic1, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);

    hAddr = CreateWindow("combobox",
		NULL, 
        WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
        80, 12, 60, 80,
        hwnd,
        NULL,
        hInstance,
        NULL);
	SendMessage(hAddr, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
	SendMessage(hAddr, CB_ADDSTRING, (WPARAM)0, (LPARAM)"01");
	SendMessage(hAddr, CB_ADDSTRING, (WPARAM)0, (LPARAM)"02");
	SendMessage(hAddr, CB_ADDSTRING, (WPARAM)0, (LPARAM)"03");
	SendMessage(hAddr, CB_ADDSTRING, (WPARAM)0, (LPARAM)"04");
	SendMessage(hAddr, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	HWND hStatic2 = CreateWindow("static",
		"数据:",
		WS_VISIBLE | WS_CHILD | WS_TABSTOP, 
		172, 16, 56, 20,
		hwnd,
		NULL,
		hInstance,
		NULL);
	SendMessage(hStatic2, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);

	hData = CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_EDIT,
		"",
		WS_VISIBLE | WS_CHILD | ES_NUMBER | WS_TABSTOP, 
		232, 12, 60, 20,
		hwnd,
		NULL,
		hInstance,
		NULL);
	SendMessage(hData, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);

	hFile = Open_Comm_Port();

    SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, hInstance, GetCurrentThreadId());

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
