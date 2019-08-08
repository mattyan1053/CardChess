# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "SceneManager.hpp"
# include "Board.hpp"
# include "Types.hpp"
# include "ItemList.hpp"

namespace Game {

	const Point b_pos = { 140, 700 };

	struct PlayerData {
		int cost = 0;
		int maxCost = 0;
		ItemList sp; // smart phone
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
		void drawItems() const;

		bool chkBdClk();
		bool chkItmClk();
		void makeFree();
		void movePiece();
		void useItem();
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