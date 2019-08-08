# include "GameTitle.hpp"

namespace Title {

	void GameTitle::update() {
		if (FontAsset(L"TITLE")(L"2P ƒ‚[ƒh").region().movedBy(530, 500).leftClicked) {
			changeScene(L"Game");
		}
		if (FontAsset(L"TITLE")(L"‚d‚˜‚‰‚”").region().movedBy(550, 600).leftClicked) {
			System::Exit();
		}

		if (mFlag) posx -= 3;
		else posx += 3;

		if (posx > 350) mFlag = true;
		if (posx < 50) mFlag = false;

	}

	void GameTitle::draw() const{
		const int N = 7;
		auto size = TextureAsset(L"BACK").resize(300, 210).size;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				TextureAsset(L"BACK").resize(300, 210).draw(size.x * x, size.y * y);
			}
		}
		TextureAsset(L"TITLE").resize(1000, 250).draw(150, 50);

		FontAsset(L"TITLE")(L"‚QP ƒ‚[ƒh").draw(530, 500, Palette::Blue);
		Line(530, 540, 700, 540).draw(Palette::Blue);
		FontAsset(L"TITLE")(L"‚d‚˜‚‰‚”").draw(550, 600, Palette::Blue);
		Line(545, 640, 685, 640).draw(Palette::Blue);

		FontAsset(L"TITLE")(L"CCS Chiba university Computer researching Society.").draw(posx, 700, Palette::Yellow);

	}

}