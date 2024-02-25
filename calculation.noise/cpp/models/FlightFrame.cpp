//
// Created by misha on 25.02.24.
//

#include "FlightFrame.h"

namespace calculation {

    FlightFrame::FlightFrame(std::string id, double latitude, double longitude,double altitude, tm *time, std::string planeType):
        id(id), point(Point(latitude, longitude)), altitude(altitude), time(time), planeType(planeType) {}
}