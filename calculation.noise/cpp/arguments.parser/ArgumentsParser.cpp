#include "ArgumentsParser.h"
#include "../image.generator/SvgGenerator.h"

namespace calculation {
    bool ArgumentsParser::parseArguments(int argv, char **args) {
        //if (argv < 5) return -1;

        char* command = args[2];

        if (std::string(command) == "table") {
            if (argv<4) {
                printSectorTableToConsole(args[1]);
                return true;
            }
            printSectorTableToConsole(args[1], std::stoi(args[3]));
            return true;
        } else if (std::string(command) == "sector") {
            if (std::string(args[3]).find('.') != std::string::npos && std::string(args[4]).find('.') != std::string::npos) {
                printSectorNoiseToConsole(args[1], std::stod(args[3]), std::stod(args[4]));
                return true;
            }
            printSectorNoiseToConsole(args[1], std::stoi(args[3]), std::stoi(args[4]));
            return true;
        } else if (std::string(command) == "map") {
            generateMap(args[1], args[3]);
            return true;
        }

        return false;
    }

    void ArgumentsParser::printSectorTableToConsole(char *path) {
        std::string flightLog_FileName = std::string(path) + "/sheremetyevo_history";
        std::string callSign_PlaneType_FileName = std::string(path) + "/callsign_info";
        FlightsLogParser parser = FlightsLogParser(flightLog_FileName, callSign_PlaneType_FileName);
        SectorBunch sectorBunch = parser.generateSectorBunch();
        ConsolePrinter consolePrinter;

        for (int i = 0; i < sectorBunch.sectorTableSize; ++i) {
            for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
                consolePrinter.printNoiseBy24Vectors(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises);
            }
            std::cout << "\n";
        }
    }

    void ArgumentsParser::printSectorTableToConsole(char* path, int hour) {

        std::string flightLog_FileName = std::string(path) + "/sheremetyevo_history";
        std::string callSign_PlaneType_FileName = std::string(path) + "/callsign_info";
        FlightsLogParser parser = FlightsLogParser(flightLog_FileName, callSign_PlaneType_FileName);
        SectorBunch sectorBunch = parser.generateSectorBunch();
        ConsolePrinter consolePrinter;

        for (int i = 0; i < sectorBunch.sectorTableSize; ++i) {
            for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
                consolePrinter.printNoiseByVector(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[hour]);
            }
            std::cout << "\n";
        }
    }

    void ArgumentsParser::printSectorNoiseToConsole(char* path, int x, int y) {

        std::string flightLog_FileName = std::string(path) + "/sheremetyevo_history";
        std::string callSign_PlaneType_FileName = std::string(path) + "/callsign_info";
        FlightsLogParser parser = FlightsLogParser(flightLog_FileName, callSign_PlaneType_FileName);
        SectorBunch sectorBunch = parser.generateSectorBunch();
        ConsolePrinter consolePrinter;

        consolePrinter.printSectorNoiseByVector(sectorBunch.sectorTable[x][y].sectorNoise.hourNoises);

        std::cout << "\n";
    }

    void ArgumentsParser::printSectorNoiseToConsole(char *path, double latitude, double longitude) {
        std::string flightLog_FileName = std::string(path) + "/sheremetyevo_history";
        std::string callSign_PlaneType_FileName = std::string(path) + "/callsign_info";
        FlightsLogParser parser = FlightsLogParser(flightLog_FileName, callSign_PlaneType_FileName);
        SectorBunch sectorBunch = parser.generateSectorBunch();
        ConsolePrinter consolePrinter;

        consolePrinter.printSectorNoiseByVector(Algorithms::getNearestSector({latitude, longitude}, sectorBunch)->sectorNoise.hourNoises);

        std::cout << "\n";
    }

    void ArgumentsParser::generateMap(char *path, char *fileName) {
        std::string flightLog_FileName = std::string(path) + "/sheremetyevo_history";
        std::string callSign_PlaneType_FileName = std::string(path) + "/callsign_info";
        FlightsLogParser parser = FlightsLogParser(flightLog_FileName, callSign_PlaneType_FileName);
        SectorBunch sectorBunch = parser.generateSectorBunch();
        SvgGenerator svgGenerator;

        svgGenerator.generateSvgImage(sectorBunch, std::string(fileName));
    }
}