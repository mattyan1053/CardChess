# include "GameTitle.hpp"

namespace Title {

	void GameTitle::update() {
		if (Input::MouseL.clicked) {
			changeScene(L"Game");
		}
	}

	void GameTitle::draw() const{
		FontAsset(L"LARGE")(L"TITLE").drawCenter(Window::Center());
	}

}