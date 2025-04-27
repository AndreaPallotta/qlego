# QuantumLego

qlego is a simple quantum simulation library that allows you to apply quantum gates to qubits and simulate basic measurements.

## Features
- Supports basic quantum gates like Hadamard, Pauli-X, Pauli-Z, and Identity.
- Simulates a single qubit.
- Allows applying gates and performing measurements.

## Building the Project

### Prerequisites
You will need the following to build the project:
- **CMake** (version 3.10 or higher)
- A C++17 compatible compiler (such as GCC, Clang, or MSVC)

### Steps to Build the Static Library

1. Clone or download the project files to your local machine.

2. Create a new build directory in the root of your project:
    ```sh
    mkdir build
    cd build
    ```

3. Run CMake to generate the build files:
    ```sh
    cmake ..
    ```

4. Build the static library (.lib) by running:
    ```sh
    cmake --build . --config Debug
    ```

5. The output .lib file will be located in the root directory of your project.

### File Structure

- **main.cpp**: The main application code that sets up the quantum simulator and applies quantum gates.
- **qlego.lib**: The generated static library containing the quantum simulation functionality.
- **CMakeLists.txt**: The build configuration file used by CMake to build the static library.

## Usage

Once the .lib file is built, you can link it into your own C++ projects to use the qlego library