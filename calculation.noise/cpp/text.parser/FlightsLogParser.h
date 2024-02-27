#ifndef CPP_FLIGHTSLOGPARSER_H
#define CPP_FLIGHTSLOGPARSER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "../models/FlightFrame.h"

namespace calculation {

    class FlightsLogParser {
    public:
        std::ifstream file;
        std::map<std::string, std::string> callsignPlanetypeMap;

        FlightsLogParser(std::string fileName, std::string callsignInfoFileName);

        bool parseLine(FlightFrame& flight);

        std::map<std::string, std::string> getCallsignPlanetypeMap(std::string callsignInfoFileName);

        FlightFrame string2FlightFrame(std::string line);


    };

}

#endif
