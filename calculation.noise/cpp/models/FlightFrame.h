
#ifndef CPP_FLIGHTFRAME_H
#define CPP_FLIGHTFRAME_H

#include <ctime>
#include <string>
#include "Point.h"

namespace calculation {

    class FlightFrame {
    public:
        std::string id;
        Point point;
        double altitude;
        int speed;
        tm time;
        std::string planeType;

        FlightFrame() = default;

        FlightFrame(std::string id, double latitude, double longitude, double altitude, int speed,
                    tm time, std::string planeType);
    };

}

#endif
