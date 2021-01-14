//
// EPSI PROJECT, PROJECT NAME : vchips
// BAPTISTE GOULARD CODERC DE LACAM, 2020
// file:game_core class implementation
//

#include <iostream> // for debug should be removed at prod
#include <string>

#include "game_core.hpp"

namespace vchips {

	void load_map(std::filesystem::path &p)
	{
		return;
	}

	void load_chip(std::filesystem::path &p)
	{
		return;
	}

	void game_core::init_back_side() {
		std::filesystem::path p;
		std::filesystem::path ext;

		this->pre_path = std::filesystem::current_path();
		std::filesystem::current_path(getenv("HOME"));
		p = std::filesystem::path(".vchips");
		if (!std::filesystem::exists(p)) {
			if (!std::filesystem::create_directory(p.filename()))
				throw("tmp throw, should create dir if not existing");
			std::cout << "creatng vchips directory at " << p << "." << std::endl;
		}
		for (auto &it : std::filesystem::directory_iterator(p)) {
			if ((ext = it.path().extension()) == "vcm") {
				load_map(p);
			} else if (ext == "vcc") {
				load_chip(p);
			} else
				std::cout << "ignored file " << it << " format not recognized" << std::endl;
		}
		return;
		//
		// * ==> optional (ambitious
		//
		// read player info
			// read list of existings maps & chips
			// *read player name (if not cn just designate with username)
			// *if none -> create/prompt user
		// end constructor
	}

	void game_core::init_front_side()
	{
		// problem :
		// Really dont want this file to turn into a hot garbage of mess and
		//   implementing sfml in this file will certainly be the last straw...
		// possibility of sub-classes is very seriously envisioned and should be discussed with tutor.
		mode = sf::VideoMode(1000, 1000);
	}

	game_core::game_core()
	{
		std::cout << "constructor start" << std::endl;
		//
		//splited file+info init from graphical init;
		//    maybe translate at fome point into 2 full separate sub classes?
		//
		init_back_side(); // user file(?s)/vars init
		init_front_side(); // graphical files/vars init
		std::cout << "constructor end" << std::endl;
	}

	int game_core::g_play()
	{
		sf::Event event;

		mw.create(mode, "SFML window");
		mw.setVerticalSyncEnabled(true);
		mw.setFramerateLimit(60);
		while (mw.isOpen()) {
			mw.clear();
			mw.display();
			while (mw.pollEvent(event))
				if (event.type == sf::Event::Closed)
					mw.close();
		}
		return (EXIT_SUCCESS);
	}
}
