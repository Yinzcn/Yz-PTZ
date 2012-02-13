
struct Button
{
	HWND hwnd;
	void *proc;
	void *defproc;
};


LRESULT CALLBACK
Button_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	struct Button *button = (void *)GetWindowLong(hwnd, GWL_USERDATA);
	void *proc    = button->proc;
	void *defproc = button->defproc;
	if (msg == WM_NCDESTROY) {
		free(button);
	}
	return CallWindowProc((WNDPROC)proc,    hwnd, msg, wParam, lParam) ?
	TRUE : CallWindowProc((WNDPROC)defproc, hwnd, msg, wParam, lParam);
}


HWND
Button_Create(HWND hwndParent, char *name, int x, int y, int w, int h, void *proc)
{
	struct Button *button = calloc(1, sizeof(struct Button));
	HWND hwnd = CreateWindowEx(WS_EX_WINDOWEDGE,
		WC_BUTTON,
		name,
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_TABSTOP, 
		x,
		y,
		w,
		h,
		hwndParent,
		NULL,
		(HINSTANCE)GetWindowLong(hwndParent, GWL_HINSTANCE),
		NULL);
	SendMessage(hwnd, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
	button->defproc = (void *)GetWindowLong(hwnd, GWL_WNDPROC);
	button->proc = proc;
	SetWindowLong(hwnd, GWL_WNDPROC, (LONG)Button_WndProc);
	SetWindowLong(hwnd, GWL_USERDATA, (LONG)button);
	ShowWindow(hwnd, SW_SHOWNORMAL);
	return hwnd;
}
