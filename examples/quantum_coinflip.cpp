#include <iostream>
#include "qlego/gate.hpp"
#include "qlego/simulator.hpp"
#include <vector>
#include <utility>
#include <string>

int main() {
    // Define the gate types in an array for easy iteration
    std::vector<std::pair<std::string, const std::complex<double>(&)[2][2]>> gates = {
        {"Hadamard", QuantumLego::Gate::HADAMARD},
        {"Pauli-X", QuantumLego::Gate::PAULI_X},
        {"Pauli-Z", QuantumLego::Gate::PAULI_Z},
        {"Identity", QuantumLego::Gate::IDENTITY}
    };

    for (const auto& gate : gates) {
        for (int i = 0; i < 3; ++i) {
            QuantumLego::Simulator simulator(1);
            auto& circuit = simulator.getCircuit();

            std::cout << "Test " << i + 1 << " with " << gate.first << " gate:\n";
            std::cout << "Initial state:\n";
            circuit.printCircuitState();

            std::cout << "\nApplying " << gate.first << " gate...\n";
            circuit.applyGate(0, gate.second);

            std::cout << "State after " << gate.first << " gate:\n";
            circuit.printCircuitState();

            std::cout << "\nRunning measurement...\n";
            std::vector<int> measurementResult = simulator.runMeasurement();

            if (measurementResult[0] == 0) {
                std::cout << "Result: Heads\n";
            }
            else {
                std::cout << "Result: Tails\n";
            }

            std::cout << "------------------------------------------\n";
        }
    }

    return 0;
}
