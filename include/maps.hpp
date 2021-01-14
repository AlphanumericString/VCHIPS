//
// EPSI PROJECT, PROJECT NAME : VCHIPS
// BAPTISTE GOULARD CODERC DE LACAM, 2020
// file:interface for map class
//

#pragma once

#include <vector>
#include "chips.hpp"

namespace vchips {
	class maps {
	public:
		maps(){};
		~maps(){};
	private:
		std::vector<vchips::chips> comp_list;

	};

}
