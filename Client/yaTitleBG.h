#pragma once
#include "yaScene.h"

namespace ya {

	class Image;
	class Title_BG : public GameObject
	{
	public:
		Title_BG();
		~Title_BG();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* mImage;
	};
}


