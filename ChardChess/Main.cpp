# include <Siv3D.hpp>
# include "SceneManager.hpp"
# include "GameTitle.hpp"
# include "GameManager.hpp"
# include "ResourceLoader.hpp"

void Main() {

	// ウィンドウ設定
	Window::SetTitle(L"そうか！キングを取れば！");
	Window::Resize(windowSize);
	Window::Centering();

	// リソースのロード
	LoadResources();

	// シーン管理
	BaseApp manager;
	manager.add<Title::GameTitle>(L"Title");
	manager.add<Game::GameManager>(L"Game");

	while (System::Update()) {
		manager.updateAndDraw();
	}

}