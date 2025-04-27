#include "qlego/qubit.hpp"
#include <iostream>

namespace QuantumLego {
	Qubit::Qubit() {
		this->generator = std::default_random_engine(std::random_device{}());
		this->distribution = std::uniform_real_distribution<double>(0.0, 1.0);
	}

	void Qubit::applyGate(const std::complex<double> gateMatrix[2][2]) {
		std::complex<double> newState[2];

		for (int i = 0; i < 2; ++i) {
			newState[i] = 0;
			for (int j = 0; j < 2; ++j) {
				newState[i] += gateMatrix[i][j] * this->state[j];
			}
		}

		this->state[0] = newState[0];
		this->state[1] = newState[1];

		double norm = std::abs(this->state[0]) * std::abs(this->state[0]) + std::abs(this->state[1]) * std::abs(this->state[1]);
		if (norm > 0) {
			this->state[0] /= std::sqrt(norm);
			this->state[1] /= std::sqrt(norm);
		}
	}

	int Qubit::measure() {
		double prob0 = std::norm(this->state[0]);
		double prob1 = std::norm(this->state[1]);

		double randomValue = this->distribution(generator);
		if (randomValue < prob0) {
			this->state[0] = std::complex<double>(1.0, 0.0);
			this->state[1] = std::complex<double>(0.0, 0.0);
			return 0; // Measure |0>
		}
		else {
			this->state[0] = std::complex<double>(0.0, 0.0);
			this->state[1] = std::complex<double>(1.0, 0.0);
			return 1; // Measure |1>
		}
	}

	void Qubit::printState() const {
		std::cout << "Qubit state: |0>: " << this->state[0] << ", |1>: " << this->state[1] << std::endl;
	}
} // namespace QuantumLego