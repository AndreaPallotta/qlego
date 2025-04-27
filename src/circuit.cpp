#include "qlego/circuit.hpp"

namespace QuantumLego {

	Circuit::Circuit(int numQubits) {
		qubits.reserve(numQubits);
		for (int i = 0; i < numQubits; ++i) {
			qubits.emplace_back();
		}
    }

    Qubit& Circuit::getQubit(int index) {
		if (index < 0 || index >= qubits.size()) {
			throw std::out_of_range("Qubit index out of range");
		}

		return qubits[index];
    }

    void Circuit::applyGate(int qubitIndex, const std::complex<double> gateMatrix[2][2]) {
		if (qubitIndex < 0 || qubitIndex >= qubits.size()) {
			throw std::out_of_range("Qubit index out of range");
		}
		qubits[qubitIndex].applyGate(gateMatrix);
	}

    std::vector<int> Circuit::measureAll() {
		std::vector<int> results;
		for (Qubit& qubit : this->qubits) {
			results.push_back(qubit.measure());
		}
		return results;
    }

    void Circuit::printCircuitState() const {
		for (const Qubit& qubit : this->qubits) {
			qubit.printState();
		}
    }

} // namespace QuantumLego