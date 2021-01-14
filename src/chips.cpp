//
// EPSI PROJECT, PROJECT NAME : VCHIPS
// BAPTISTE GOULARD CODERC DE LACAM, 2020
// file:implementation of mother class chip
//

#include <iostream>
#include <fstream>

#include "chips.hpp"

namespace fs = std::filesystem;

namespace vchips {
	void my_dump(fs::path p) {
		std::ifstream file;
		std::string s;

		file.open(p);
		do {
			file >> s;
			std::cerr << s << std::endl;
		} while (s.empty() == false);
		file.close();
	}

	chips::chips(fs::path &p)
	{
		my_dump(p);
	}

	chips::chips(std::string &s)
	{
		auto p = fs::path(s);
		auto perm = fs::status(s).permissions();

		if (!fs::exists(p))
			throw("error given path doesn't refer to any file.");
		else if (!fs::is_regular_file(p))
			throw("error given path doesn't refer to a file.");
		else if (!((perm & fs::perms::owner_read) != fs::perms::none
			&&  (perm & fs::perms::owner_write) != fs::perms::none))
			throw("error on permission of given file (either read or write)");
		my_dump(p);
	}
}
