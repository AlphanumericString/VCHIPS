//
// EPSI PROJECT, PROJECT NAME : VCHIPS
// BAPTISTE GOULARD CODERC DE LACAM, 2020
// file:mother interface for all chips class.
//

#pragma once

#include <string>
#include <filesystem>
#include <memory>
#include <vector>
#include "wire.hpp"

namespace vchips {
	class chips {
	public:
		chips() {};
		chips(std::string &s);
		chips(std::filesystem::path &p);
		~chips(){};

		// maybe wire instead of int ? dunno...
			// simple return false as a place holder for compilation
		virtual bool compute_for(int node);
	protected:
		std::vector<std::shared_ptr<vchips::wire>> wires;

	};
}
