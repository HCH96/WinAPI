#pragma once
#include "yaScene.h"

namespace ya
{
	class Cuphead;
	class Stage_BG;
	class PlayeScene : public Scene
	{
	public:
		PlayeScene();
		~PlayeScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Cuphead* mCuphead;
		Stage_BG* mStageBG;
	};
}
