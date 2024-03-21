#include "FlightsLogParser.h"

#include <filesystem>
#include <iostream>

namespace calculation {
    FlightsLogParser::FlightsLogParser(std::string fileName, std::string callsignInfoFileName) {
///        std::filesystem::current_path("/home/misha/PycharmProjects/SheremetyegoParce");
        file = std::ifstream( fileName);
        callsignPlanetypeMap = getCallsignPlanetypeMap(callsignInfoFileName);
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
        std::string strTime;
        double latitude;
        double longitude;
        int altitude;
        int speed;

        std::stringstream sstream(line);
        sstream >> callsign >> strDate >> strTime >> latitude >> longitude >> altitude >> speed;

        tm time = {.tm_hour = std::stoi(std::string(strTime, 0, 2))};

        return FlightFrame(callsign, latitude, longitude, altitude, speed, time, callsignPlanetypeMap[callsign]);

    }

    std::map<std::string, std::string> FlightsLogParser::getCallsignPlanetypeMap(std::string callsignInfoFileName) {
        std::map<std::string, std::string> currentMap;
        std::string line;
        std::ifstream callsignInfoFile(callsignInfoFileName);

        while (std::getline(callsignInfoFile, line)) {
            std::string callsign;
            std::string planetype;

            std::stringstream sstream(line);
            sstream >> callsign >> planetype;

            currentMap[callsign] = planetype;
        }

        return currentMap;
    }

    SectorBunch FlightsLogParser::generateSectorBunch() {
        FlightFrame flightFrame;
        SectorBunch sectorBunch = SectorBunch(Point(sheremetyegoCords), 0.01014, 0.005605, 64);

        while (parseLine(flightFrame)) {
            // ready flightFrame
            auto sectors = Algorithms::getNearestSectors(flightFrame, sectorBunch);
            for (auto sector : sectors) {
                double noise = Algorithms::countNoiseInSector(sector, flightFrame);
                sector->sectorNoise.hourNoises[flightFrame.time.tm_hour].push_back(noise);
            }
        }

        return sectorBunch;
    }
}