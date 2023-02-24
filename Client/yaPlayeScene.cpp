#include "yaPlayeScene.h"
#include "yaCuphead.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaStageBG.h"

namespace ya
{
	PlayeScene::PlayeScene()
	{
	}

	PlayeScene::~PlayeScene()
	{
	}

	void PlayeScene::Initialize()
	{
		mStageBG = new Stage_BG();
		AddGameObeject(mStageBG, eLayerType::BG);
		
		mCuphead = new Cuphead();
		AddGameObeject(mCuphead, eLayerType::Player);

		Scene::Initialize();
	}

	void PlayeScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}

		Scene::Update();
	}

	void PlayeScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void PlayeScene::Release()
	{
		Scene::Release();
	}
	void PlayeScene::OnEnter()
	{
	}
	void PlayeScene::OnExit()
	{
	}
}
