#pragma once
#include "qlego/circuit.hpp"

namespace QuantumLego {
	class Simulator {
	public:
		Simulator(int numQubits = 1);
		Circuit& getCircuit();
		std::vector<int> runMeasurement();

	private:
		Circuit circuit;
	};
} // namespace QuantumLego