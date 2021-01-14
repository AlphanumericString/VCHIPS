//
// EPSI PROJECT, PROJECT NAME : VCHIPS
// BAPTISTE GOULARD CODERC DE LACAM, 2020
// file:implementation of light class input
//

#include "input.hpp"

namespace vchips {
	input::input(bool &state) {
		wires.insert(0, std::make_shared<wire::wire>(state));
	}
}
