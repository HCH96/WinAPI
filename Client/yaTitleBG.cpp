#include "yaTitleBG.h"
#include "yaSceneManager.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya
{
	Title_BG::Title_BG()
	{
	}
	Title_BG::~Title_BG()
	{
	}
	void Title_BG::Initialize()
	{
		mImage = Resources::Load<Image>(L"Title_BG", L"..\\Resources\\start_scene.bmp");

		GameObject::Initialize();
	}
	void Title_BG::Update()
	{
		GameObject::Update();
	}
	void Title_BG::Render(HDC hdc)
	{
		BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void Title_BG::Release()
	{
	}
}