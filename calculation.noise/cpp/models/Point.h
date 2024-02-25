#ifndef CPP_POINT_H
#define CPP_POINT_H

namespace calculation {

    class Point {
    public:
        double latitude;
        double longitude;

        Point(double latitude, double longitude);
        Point & operator+= (const Point& other);

    };

}

#endif
