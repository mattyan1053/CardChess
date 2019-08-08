# pragma once
# include "GameManager.hpp"
# include "Button.hpp"

namespace Game {

	class Player : public GameScene::Scene {	
	public:

		Button b;

		void init() override;

		void update() override;

		void draw() const override;

	};

}