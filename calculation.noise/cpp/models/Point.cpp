
#include "Point.h"

namespace calculation {

    Point::Point(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

    Point& Point::operator+=(const Point &other) {
        latitude += other.latitude;
        longitude += other.longitude;
        return *this;
    }

}