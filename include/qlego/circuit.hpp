#pragma once
#include <vector>
#include "qlego/qubit.hpp"

namespace QuantumLego {
	class Circuit {
	public:
		Circuit(int numQubites);
		Qubit& getQubit(int index);
		void applyGate(int qubitIndex, const std::complex<double> gateMatrix[2][2]);
		std::vector<int> measureAll();
		void printCircuitState() const;

	private:
		std::vector<Qubit> qubits;
	};
} // namespace QuantumLego