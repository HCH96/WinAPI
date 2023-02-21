#pragma once

class mCore {

	SINGLE(mCore);

private:
	HWND	m_hWnd;			// 메인 윈도우 핸들
	POINT	m_ptResolution; // 해상도
	HDC		m_hDC;			// 메인 윈도우 핸들

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();

public:
	HWND GetMainHwnd() { return m_hWnd; }
};