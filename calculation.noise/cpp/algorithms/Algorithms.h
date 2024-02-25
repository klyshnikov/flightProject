#ifndef CPP_ALGORITHMS_H
#define CPP_ALGORITHMS_H

#include "../models/FlightFrame.h"

namespace calculation {

    class Algorithms {
    public:
        static double countDistanceBetweenPointAndFlight(Point point, const FlightFrame& flightFrame);
    };

}

#endif
