# pragma once
# include <Siv3D.hpp>
# include "SceneManager.hpp"
# include "Global.hpp"

namespace Result {

	class GameResult : public BaseApp::Scene {

	public:

		void update() override;

		void draw() const override;

	};

}