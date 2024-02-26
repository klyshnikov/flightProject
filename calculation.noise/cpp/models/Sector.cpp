#include "Sector.h"

namespace calculation {

    void Sector::move(double latitude, double longitude) {
        center += Point(latitude, longitude);
        leftDown += Point(latitude, longitude);
        rightUp += Point(latitude, longitude);
    }

    Sector::Sector(Point center, Point leftDown, Point rightUp):
            center(center), leftDown(leftDown), rightUp(rightUp) {sectorNoise = SectorNoise();}

    Sector::Sector() :
        center(0, 0), leftDown(0, 0), rightUp(0, 0) {}
}