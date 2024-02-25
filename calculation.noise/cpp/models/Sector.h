#ifndef CPP_SECTOR_H
#define CPP_SECTOR_H

#include "Point.h"

namespace calculation {

    class Sector {
    public:
        Point center;
        Point leftDown;
        Point rightUp;

        Sector();
        Sector(Point center, Point leftDown, Point rightUp);

        void move(double latitude, double longitude);
    };

}

#endif
