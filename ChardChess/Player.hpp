# pragma once
# include "GameManager.hpp"

namespace Game {

	class Player : public GameScene::Scene {	
	public:

		void init() override;

		void update() override;

		void draw() const override;

		bool checkTurnEnd();

	};

}