#include "FlightsLogParser.h"

namespace calculation {
    FlightsLogParser::FlightsLogParser(std::string fileName) {
        file = std::ifstream(fileName);
    }

    bool FlightsLogParser::parseLine(FlightFrame &flightFrame) {
        std::string line;
        if (std::getline(file, line)) {
            flightFrame = string2FlightFrame(line);
            return true;
        }
        return false;
    }

    FlightFrame FlightsLogParser::string2FlightFrame(std::string line) {
        std::string callsign;
        std::string strDate;
        std::string strTimetime;
        double latitude;
        double longitude;
        int altitude;
        int speed;

    }

    std::map<std::string, std::string> FlightsLogParser::getCallsignPlanetypeMap(std::string callsignInfoFileName) {
        std::map<std::string, std::string> callsignPlanetypeMap;
        std::string line;
        std::ifstream callsignInfoFile(callsignInfoFileName);

        while (std::getline(callsignInfoFile, line)) {
            std::string callsign;
            std::string planetype;

            std::stringstream sstream(line);
            sstream >> callsign >> planetype;

            callsignPlanetypeMap[callsign] = planetype;
        }

        return callsignPlanetypeMap;
    }


}