# include "GameResult.hpp"
# include "Types.hpp"

namespace Result {

	void GameResult::update() {
		if (Input::MouseL.clicked) {
			changeScene(L"Title");
		}
	}

	void GameResult::draw() const {
		FontAsset(L"LARGE")(L"Result ", (m_data->winner == Game::Turn::P1) ? L"”’" : L"•", L"‚ÌŸ‚¿I").drawCenter(Window::Center());
	}

}