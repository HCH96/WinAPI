#include "pch.h"
#include "CTimeMgr.h"
#include "mCore.h"

CTimeMgr::CTimeMgr()
	:m_llCurCount{}
	,m_llPrevCount{}
	,m_llFrequency{}
	,m_dDT(0.)
	,m_dAcc(0.)
	,m_iCallCount(0)
	,m_iFPS(0)
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);
	
	// 초당 카운트 횟수
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart)/ (double)m_llFrequency.QuadPart ;


	// 이전 카운트 값을 현재 값으로 갱신
	m_llPrevCount = m_llCurCount;

	++m_iCallCount;
	m_dAcc += m_dDT;

	if (m_dAcc >= 1.) 
	{
		m_iFPS = m_iCallCount;
		
		
		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %f", m_iFPS, m_dDT);
		SetWindowText(mCore::GetInst()->GetMainHwnd(), szBuffer);

		m_dAcc = 0.;
		m_iCallCount = 0;
	}

	
}
