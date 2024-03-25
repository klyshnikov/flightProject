#ifndef CPP_POINT_H
#define CPP_POINT_H

#include <utility>

namespace calculation {

    class Point {
    public:
        double latitude;
        double longitude;

        Point() = default;
        Point(double latitude, double longitude);
        Point(std::pair<double, double>);
        friend bool operator==(const Point&, const Point&);
        Point & operator+= (const Point& other);

    };

}

#endif
