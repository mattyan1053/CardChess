# pragma once
# include <Siv3D.hpp>
# include "SceneManager.hpp"
# include "Global.hpp"

namespace Title {

	class GameTitle : public BaseApp::Scene {

		int posx = 100;
		bool mFlag = false;

	public:

		void update() override;

		void draw() const override;

	};

}