#include "qlego/simulator.hpp"

namespace QuantumLego {

	Simulator::Simulator(int numQubits) : circuit(numQubits) {};

	Circuit& Simulator::getCircuit() {
		return this->circuit;
	}

	std::vector<int> Simulator::runMeasurement() {
		return this->circuit.measureAll();
	}

} // namespace QuantumLego
