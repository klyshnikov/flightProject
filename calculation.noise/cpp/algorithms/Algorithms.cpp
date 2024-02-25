#include "Algorithms.h"
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
        int currentI = 0; int currentJ = 0;

        for (int i = 0; i<sectorBunch.sectorTableSize; ++i) {
            if (flightFrame.point.longitude <= sectorBunch.sectorTable[0][i].rightUp.longitude &&
                flightFrame.point.longitude >= sectorBunch.sectorTable[0][i].leftDown.longitude) {
                currentI = i;
                break;
            }
        }

        for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
            if (flightFrame.point.latitude <= sectorBunch.sectorTable[j][0].rightUp.latitude &&
                    flightFrame.point.latitude <= sectorBunch.sectorTable[j][0].leftDown.latitude) {
                currentJ = j;
            }
        }


    }

}