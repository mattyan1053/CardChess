# pragma once
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "Types.hpp"

struct CommonData {
	Game::Turn winner;
};

using BaseApp = SceneManager<String, CommonData>;