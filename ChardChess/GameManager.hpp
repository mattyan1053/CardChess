# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "SceneManager.hpp"
# include "Board.hpp"
# include "Types.hpp"

namespace Game {

	const Point b_pos = { 340, 700 };

	struct PlayerData {
		int cost = 0;
		int maxCost = 0;
	};

	struct CommonData {
		int turn = 1;
		Turn now = P1;
		Turn next = P2;
		PlayerData data[Turn::PlayerNum];
		Turn winner;
		Mode mode = Free;
		SelectedItem sItem = NonSelected;
		Point sSqr;
		Board b;
		std::function<void(String)> changeBaseScene;

		CommonData() : b(b_pos) {}

		void drawBoard() const;

		void CommonData::makeFree();
		void PlayerDataReset(Turn t);
		void movableCntReset(Turn t);
	};

	using GameScene = SceneManager<Turn, CommonData>;

	class GameManager : public BaseApp::Scene {
	public:

		GameScene manager;

		void init() override;

		void update() override;

		void draw() const override;

	};

}