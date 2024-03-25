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

        return std::sqrt(distanceOnGround*distanceOnGround + flightFrame.altitude*flightFrame.altitude*0.3048*0.3048);
    }

    double Algorithms::countNoiseInSector(Sector *sector, const FlightFrame &flightFrame) {
        double noise =  getPlaneNoise(flightFrame.planeType_);
        double distance_koeficient = 40*std::log10(countDistanceBetweenPointAndFlight(sector->center, flightFrame));
        return std::max(noise - distance_koeficient, 0.0);
        //return countDistanceBetweenPointAndFlight(sector->center, flightFrame);
    }

    Sector* Algorithms::getNearestSector(Point point, SectorBunch sectorBunch) {
        size_t currentI = 0; size_t currentJ = 0;

        for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
            if (point.longitude <= sectorBunch.sectorTable[0][j].rightUp.longitude &&
                point.longitude >= sectorBunch.sectorTable[0][j].leftDown.longitude) {
                currentJ = j;
            }
        }

        for (int i = 0; i<sectorBunch.sectorTableSize; ++i) {
            if (point.latitude <= sectorBunch.sectorTable[i][0].rightUp.latitude &&
                point.latitude >= sectorBunch.sectorTable[i][0].leftDown.latitude) {
                currentI = i;
            }
        }
        //std::cout << currentI << " " << currentJ << "\n";

        return &sectorBunch.sectorTable[currentI][currentJ];
    }

    std::vector<Sector *> Algorithms::getNearestSectors(FlightFrame flightFrame, SectorBunch sectorBunch) {

        size_t currentI = 0; size_t currentJ = 0;

        for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
            if (flightFrame.point.longitude <= sectorBunch.sectorTable[0][j].rightUp.longitude &&
                flightFrame.point.longitude >= sectorBunch.sectorTable[0][j].leftDown.longitude) {
                auto DEBUG1 = sectorBunch.sectorTable[0][j];
                currentJ = j;
            }
        }

        for (int i = 0; i<sectorBunch.sectorTableSize; ++i) {
            if (flightFrame.point.latitude <= sectorBunch.sectorTable[i][0].rightUp.latitude &&
                flightFrame.point.latitude >= sectorBunch.sectorTable[i][0].leftDown.latitude) {
                currentI = i;
            }
        }

        int minLongitudeIndex = currentJ - (shape_of_nearest_sectors-1)/2;
        size_t maxLongitudeIndex = currentJ + (shape_of_nearest_sectors-1)/2;
        int minLatitudeIndex = currentI - (shape_of_nearest_sectors-1)/2;
        size_t maxLatitudeIndex = currentI + (shape_of_nearest_sectors-1)/2;

        std::vector<Sector*> nearestSectors = {};
        auto DEBUG = sectorBunch.sectorTable[currentI][currentJ];

        for (int i = std::max(minLatitudeIndex, 0); i<=std::min(maxLatitudeIndex, sectorBunch.sectorTableSize-1); ++i) {
            for (int j = std::max(minLongitudeIndex, 0); j<=std::min(maxLongitudeIndex, sectorBunch.sectorTableSize-1); ++j) {
                nearestSectors.push_back(&sectorBunch.sectorTable[i][j]);
            }
        }

        return nearestSectors;

    }

    double Algorithms::getPlaneNoise(std::string planeType) {
        return 170;
    }

    std::string Algorithms::getStringBiggerSize(std::string current, int size) {
        while (current.size() < size) {
            current += " ";
        }

        return current;
    }

    double Algorithms::scaleNoiseLevelToBarChart(double value) {
        return (value/max_noise)*bar_chart_size;
    }

    double Algorithms::scaleNoiseLevelToBarChart(int value) {
        return scaleNoiseLevelToBarChart(double(value));
    }

    int Algorithms::countNoiseLevelByVector(noise_1hour_in_sector value) {
        if (value.empty()) return 0;
        //std::sort(value.begin(), value.end());
        auto max_el =  std::max_element(value.begin(), value.end());
        return std::min(99, int(*max_el));
        //return int(value[(value.size()*9)/10]);
        //return int(std::accumulate(value.begin(), value.end(), 0) / double (value.size()));
    }

    int Algorithms::countNoiseLevel(noise_24hour_in_sector value) {
        int hourNoiseSum = 0;
        for (int hour = 0; hour < 24; ++hour) {
            hourNoiseSum += countNoiseLevelByVector(value[hour]);
        }

        return hourNoiseSum/24;
    }


}