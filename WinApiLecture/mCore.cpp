#include "pch.h"
#include "mCore.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CObject.h"

CObject g_obj;

mCore::mCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
{
}

mCore::~mCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}


int mCore::init(HWND _hWnd, POINT _ptResolution)
{
	//��� �ʱ�ȭ
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	m_hDC = GetDC(m_hWnd);

	// �ػ󵵿� �°� ������ ũ�� ����
	RECT rt = { 0,0,m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	// Manager �ʱ�ȭ
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	


	g_obj.SetPos(Vec2((float)m_ptResolution.x / 2, (float)m_ptResolution.y / 2 ));
	g_obj.SetScale(Vec2(100,100));

	return S_OK;
}


void mCore::progress()
{
	//Manager Update
	CTimeMgr::GetInst()->update();

	update();
	render();
}

void mCore::update()
{
	Vec2 vPos = g_obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 200.f * fDT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 200.f * fDT;
	}

	g_obj.SetPos(vPos);


	//��ü���� ������ üũ

}

void mCore::render()
{
	//�׸���
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_hDC,
		int(vPos.x - vScale.x / 2.f),
		int(vPos.y - vScale.y / 2.f),
		int(vPos.x + vScale.x / 2.f),
		int(vPos.y + vScale.y / 2.f));
}
