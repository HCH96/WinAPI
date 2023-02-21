#pragma once

class mCore {

	SINGLE(mCore);

private:
	HWND	m_hWnd;			// ���� ������ �ڵ�
	POINT	m_ptResolution; // �ػ�
	HDC		m_hDC;			// ���� ������ �ڵ�

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void update();
	void render();

public:
	HWND GetMainHwnd() { return m_hWnd; }
};