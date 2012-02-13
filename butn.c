
struct Butn
{
	HWND hwnd;
	void *proc;
	void *defproc;
};


LRESULT CALLBACK
Butn_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	struct Butn *butn = (void *)GetWindowLong(hwnd, GWL_USERDATA);
	void *proc    = butn->proc;
	void *defproc = butn->defproc;
	if (msg == WM_NCDESTROY) {
		free(butn);
	}
	return CallWindowProc((WNDPROC)proc,    hwnd, msg, wParam, lParam) ?
	TRUE : CallWindowProc((WNDPROC)defproc, hwnd, msg, wParam, lParam);
}


HWND
Butn_Create(HWND hwndParent, char *name, int x, int y, int w, int h, void *proc)
{
	struct Butn *butn = calloc(1, sizeof(struct Butn));
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
	butn->defproc = (void *)GetWindowLong(hwnd, GWL_WNDPROC);
	butn->proc = proc;
	SetWindowLong(hwnd, GWL_WNDPROC, (LONG)Butn_WndProc);
	SetWindowLong(hwnd, GWL_USERDATA, (LONG)butn);
	ShowWindow(hwnd, SW_SHOWNORMAL);
	return hwnd;
}
