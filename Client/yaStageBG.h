#pragma once
#include "yaScene.h"

namespace ya {

	class Image;
	class Stage_BG : public GameObject
	{
	public:
		Stage_BG();
		~Stage_BG();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* mImage;
	};
}
