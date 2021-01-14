//
// EPSI PROJECT, PROJECT NAME : VCHIPS
// BAPTISTE GOULARD CODERC DE LACAM, 2020
// file:interface for core of the game_core
//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <filesystem>
#include "maps.hpp"

namespace vchips {
	class game_core {
	public:
		game_core();
		~game_core() {};
		int g_play();
		void init_back_side();
		void init_front_side();
	private:
		// user file vars
		// tmp int -> switch to composants/chips
		std::vector<vchips::chips> uchips;
		std::vector<vchips::maps> umaps;
		std::filesystem::path pre_path;

		// graphical vars
		sf::RenderWindow mw;
		sf::VideoMode mode;
		const char *w_title = "VChips";
		//void event_processing(sf::Event &);
	};
}
