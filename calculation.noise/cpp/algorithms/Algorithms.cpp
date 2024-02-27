#include "Algorithms.h"
#include "../variables/Variables.cpp"
#include <cmath>

namespace calculation {

    double Algorithms::countDistanceBetweenPointAndFlight(Point point, const FlightFrame& flightFrame) {
        double flightPointLatRad = (flightFrame.point.latitude * M_PI)/180.0;
        double flightPointLonRad = (flightFrame.point.longitude * M_PI)/180.0;
        double pointLatRad = (point.latitude * M_PI)/180.0;
        double pointLonRad = (point.longitude* M_PI)/180.0;
        double longitudeDelta = flightPointLonRad - pointLonRad;
        double intermedValue1 = std::sin((flightPointLatRad - pointLatRad)/2.0) * std::sin((flightPointLatRad - pointLatRad)/2.0);
        double intermedValue2 = std::cos(flightPointLatRad) * std::cos(pointLatRad) * std::sin(longitudeDelta/2.0) * std::sin(longitudeDelta/2.0);
        double delta = 2.0*std::asin(std::sqrt(intermedValue1+intermedValue2));
        double distanceOnGround = delta * 6372795.0;

        return std::sqrt(distanceOnGround*distanceOnGround + flightFrame.altitude*flightFrame.altitude);
    }

    double Algorithms::countNoiseInSector(Sector *sector, const FlightFrame &flightFrame) {
        return 0;
    }

    std::vector<Sector *> Algorithms::getNearestSectors(FlightFrame flightFrame, SectorBunch sectorBunch) {

        size_t currentI = 0; size_t currentJ = 0;

        for (int i = 0; i<sectorBunch.sectorTableSize; ++i) {
            if (flightFrame.point.longitude <= sectorBunch.sectorTable[0][i].rightUp.longitude &&
                flightFrame.point.longitude >= sectorBunch.sectorTable[0][i].leftDown.longitude) {
                currentI = i;
            }
        }

        for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
            if (flightFrame.point.latitude <= sectorBunch.sectorTable[j][0].rightUp.latitude &&
                flightFrame.point.latitude >= sectorBunch.sectorTable[j][0].leftDown.latitude) {
                currentJ = j;
            }
        }

        int minLongitudeIndex = currentJ - (shape_of_nearest_sectors-1)/2;
        size_t maxLongitudeIndex = currentJ + (shape_of_nearest_sectors-1)/2;
        int minLatitudeIndex = currentI - (shape_of_nearest_sectors-1)/2;
        size_t maxLatitudeIndex = currentI + (shape_of_nearest_sectors-1)/2;

        std::vector<Sector*> nearestSectors = {};

        for (int i = std::max(minLatitudeIndex, 0); i<=std::min(maxLatitudeIndex, sectorBunch.sectorTableSize-1); ++i) {
            for (int j = std::max(minLongitudeIndex, 0); j<=std::min(maxLongitudeIndex, sectorBunch.sectorTableSize-1); ++j) {
                nearestSectors.push_back(&sectorBunch.sectorTable[i][j]);
            }
        }

        return nearestSectors;

    }

    double Algorithms::getPlanePower(std::string planeType) {
        return 0;
    }

}