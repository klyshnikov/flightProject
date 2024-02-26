#ifndef CPP_SECTOR_H
#define CPP_SECTOR_H

#include "Point.h"
#include "SectorNoise.h"

namespace calculation {

    class Sector {
    public:
        Point center;
        Point leftDown;
        Point rightUp;
        SectorNoise sectorNoise;

        Sector();
        Sector(Point center, Point leftDown, Point rightUp);

        void move(double latitude, double longitude);

    };

}

#endif
