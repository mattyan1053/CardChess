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
		int turn = 0;
		Turn now = P1;
		Turn next = P2;
		PlayerData data[Turn::PlayerNum];
		Mode mode = Free;
		SelectedItem sItem = NonSelected;
		Turn *winner;
		Point sSqr;
		Board b;
		Array<String> logStr;
		std::function<void(String)> changeBaseScene;

		CommonData() : b(b_pos) {}

		void drawBoard() const;
		void drawItems() const;
		void drawInfo() const;
		void drawSelectedInfo() const;
		void drawLog() const;

		bool chkBdClk();
		bool chkItmClk();
		void makeFree();
		void movePiece();
		void useItem();
		void PlayerDataReset(Turn t);
		void movableCntReset(Turn t);

		bool chkFin();
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