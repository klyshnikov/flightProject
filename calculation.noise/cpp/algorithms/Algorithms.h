#ifndef CPP_ALGORITHMS_H
#define CPP_ALGORITHMS_H

#include <vector>
#include "algorithm"
#include "../models/FlightFrame.h"
#include "../models/Sector.h"
#include "../models/SectorBunch.h"
#include "../numeric"
#include "../variables/Variables.h"

namespace calculation {

    class Algorithms {
    public:
        static double countDistanceBetweenPointAndFlight(Point point, const FlightFrame& flightFrame);
        static std::vector<Sector*> getNearestSectors(FlightFrame flightFrame, SectorBunch sectorBunch);
        static double getPlaneNoise(std::string planeType);
        static double countNoiseInSector(Sector* sector, const FlightFrame& flightFrame);
        static std::string getStringBiggerSize(std::string current, int size);
        static double scaleNoiseLevelToBarChart(double value);
        static double scaleNoiseLevelToBarChart(int value);

        static int countNoiseLevelByVector(std::vector<double>);
    };

}

#endif
