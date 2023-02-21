#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr);

private:
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llFrequency;

	double			m_dDT; //������ ���� �ð���
	double			m_dAcc;
	UINT			m_iCallCount;
	UINT			m_iFPS;

public:
	void init();
	void update();

public:
	double GetDT() { return m_dDT; }
	float getfDT() { return (float)m_dDT; }
};
