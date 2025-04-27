#pragma once
#include <complex>

namespace QuantumLego {
	namespace Gate {
		extern const std::complex<double> IDENTITY[2][2] = {
			{std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0)},
			{std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0)}
		};
		extern const std::complex<double> HADAMARD[2][2] = {
			{std::complex<double>(1.0 / std::sqrt(2), 0.0), std::complex<double>(1.0 / std::sqrt(2), 0.0)},
			{std::complex<double>(1.0 / std::sqrt(2), 0.0), std::complex<double>(-1.0 / std::sqrt(2), 0.0)}
		};
		extern const std::complex<double> PAULI_X[2][2] = {
			{std::complex<double>(0.0, 0.0), std::complex<double>(1.0, 0.0)},
			{std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0)}
		};
		extern const std::complex<double> PAULI_Z[2][2] = {
			{std::complex<double>(1.0, 0.0), std::complex<double>(0.0, 0.0)},
			{std::complex<double>(0.0, 0.0), std::complex<double>(-1.0, 0.0)}
		};
	}
} // namespace QuantumLego