//
// EPSI PROJECT, PROJECT NAME : VCHIPS
// BAPTISTE GOULARD CODERC DE LACAM, 2020
// file:simple main lauching the init and calling the play function.
//

#include <iostream>

#include "game_core.hpp"

int main()
{
	auto context = vchips::game_core();
	auto ret = context.g_play();

	return (ret);
}
