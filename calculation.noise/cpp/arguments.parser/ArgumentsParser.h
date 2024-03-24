#ifndef CPP_ARGUMENTSPARSER_H
#define CPP_ARGUMENTSPARSER_H

#include "iostream"
#include "../algorithms/Algorithms.h"
#include "../models/Point.h"
#include "../models/FlightFrame.h"
#include "../models/SectorBunch.h"
#include "../text.parser/FlightsLogParser.h"
#include "../console/ConsolePrinter.h"
#include "../numeric"

namespace calculation {

    class ArgumentsParser {
    public:
        bool parseArguments(int argv, char** args);

        static void printSectorTableToConsole(char* path);
        static void printSectorTableToConsole(char* path, int hour);
        //static void printSectorTableToConsole(char* path, int hourStart, int hourEnd);
        //static void printSectorTableToConsole(char* path, double hourStart, double hourEnd);

        static void printSectorNoiseToConsole(char* path, int x, int y);
        static void printSectorNoiseToConsole(char* path, double latitude, double longitude);
    };

}

#endif
