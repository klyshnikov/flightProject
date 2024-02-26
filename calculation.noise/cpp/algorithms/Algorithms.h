#ifndef CPP_ALGORITHMS_H
#define CPP_ALGORITHMS_H

#include <vector>
#include "../models/FlightFrame.h"
#include "../models/Sector.h"
#include "../models/SectorBunch.h"

namespace calculation {

    class Algorithms {
    public:
        static double countDistanceBetweenPointAndFlight(Point point, const FlightFrame& flightFrame);
        static Sector* getCurrentSector(FlightFrame flightFrame, SectorBunch sectorBunch);
        static std::vector<Sector*> getNearestSectors(Sector* sector);
        static double countNoiseInSector(Sector* sector, const FlightFrame& flightFrame);
    };

}

#endif
