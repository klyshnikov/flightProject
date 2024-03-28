#include <string>
#include "PngGenerator.h"

namespace calculation {

    void PngGenerator::generatePng(double latitude, double longitude) {
        std::string expression = "python3 ./png.generator/generatePng.py "
                + std::to_string(latitude) + " " + std::to_string(longitude);
        system(expression.data());
    }
}