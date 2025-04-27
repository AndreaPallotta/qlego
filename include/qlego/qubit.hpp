#pragma once
#include <complex>
#include <random>

namespace QuantumLego {
	class Qubit {
	public:
		Qubit();
		void applyGate(const std::complex<double> gateMatrix[2][2]);
		int measure();
		void printState() const;

	private:
		std::complex<double> state[2] = { std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0) };
		std::default_random_engine generator;
		std::uniform_real_distribution<double> distribution;
	};
} // namespace QuantumLego