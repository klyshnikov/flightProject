
#include "FlightFrame.h"

namespace calculation {

    FlightFrame::FlightFrame(std::string id, double latitude, double longitude, double altitude, int speed, tm time,std::string planeType):
        id(id), point(Point(latitude, longitude)), altitude(altitude), speed(speed), time(time), planeType(planeType) {}
}