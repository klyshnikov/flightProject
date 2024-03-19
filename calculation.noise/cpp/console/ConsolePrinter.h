#ifndef CPP_CONSOLEPRINTER_H
#define CPP_CONSOLEPRINTER_H


#include <string>
#include <vector>
#include "../variables/Variables.h"

namespace calculation {
    class ConsolePrinter {
    public:
        void printNoiseByVector(std::vector<double>);
        void printSectorNoiseByVector(std::vector<double>*);
        std::string getColoredInt(int, int);
    };

}

#endif
