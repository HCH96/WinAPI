#include "yaStageBG.h"
#include "yaSceneManager.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya
{
	Stage_BG::Stage_BG()
	{
	}
	Stage_BG::~Stage_BG()
	{
	}
	void Stage_BG::Initialize()
	{
		mImage = Resources::Load<Image>(L"Stage_BG", L"..\\Resources\\stageSelect.bmp");

		GameObject::Initialize();
	}
	void Stage_BG::Update()
	{
		GameObject::Update();
	}
	void Stage_BG::Render(HDC hdc)
	{
		BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void Stage_BG::Release()
	{
	}
}