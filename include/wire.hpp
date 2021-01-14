//
// EPSI PROJECT, PROJECT NAME : VCHIPS
// BAPTISTE GOULARD CODERC DE LACAM, 2020
// file:interface for simple wire class
//

#pragma once

namespace vchips {
	class wire {
		public:
			wire(bool &st) { state = st;};
			~wire(){};
			bool setState(bool update) { return (state=update);};
			bool getState(){return (state);} // <- need fix to transmit comput chain...
		private:
			bool state;
	};
}
