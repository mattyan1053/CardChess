# include "GameResult.hpp"
# include "Types.hpp"

namespace Result {

	void GameResult::update() {
		if (Input::MouseL.clicked) {
			changeScene(L"Title");
		}
	}

	void GameResult::draw() const {

		const int N = 7;
		auto size = TextureAsset(L"BACK").resize(300, 210).size;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				TextureAsset(L"BACK").resize(300, 210).draw(size.x * x, size.y * y);
			}
		}

		TextureAsset(L"RESULT").resize(600, 200).draw(50, 50);
		FontAsset(L"BIG")((m_data->winner == Game::Turn::P1) ? L"白" : L"黒").drawCenter(230, 380);
		TextureAsset(L"WINNER").resize(700, 200).draw(350, 300);

		FontAsset(L"LARGE")(L"画面クリックでタイトルに戻る").draw(200, 650);
	}

}