
#include "Point.h"

namespace calculation {

    Point::Point(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

    Point::Point(std::pair<double, double> coords) : latitude(coords.first), longitude(coords.second) {}

    Point& Point::operator+=(const Point &other) {
        latitude += other.latitude;
        longitude += other.longitude;
        return *this;
    }

    bool operator==(const Point &point_1, const Point &point_2) {
        return (point_1.latitude == point_2.latitude) && (point_1.longitude == point_2.longitude);
    }

}