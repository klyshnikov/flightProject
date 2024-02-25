#include "SectorBunch.h"

namespace calculation {

    SectorBunch::SectorBunch(Point center, double length, double width, int sectorTableSize) {
        this->sectorTableSize = sectorTableSize;
        sectorTable = new Sector*[sectorTableSize];
        for (int i = 0; i<sectorTableSize; ++i) {
            sectorTable[i] = new Sector[sectorTableSize]();
        }

        Sector current = Sector(center, {center.latitude - width/2, center.longitude - length/2},
                                {center.latitude + width/2, center.longitude + length/2});

        current.move(width * (sectorTableSize-1)/2, (-1) * length * (sectorTableSize-1)/2);

        for (int i = 0; i < sectorTableSize; ++i) {
            for (int j = 0; j < sectorTableSize; ++j) {
                sectorTable[i][j] = current;
                current.move(0, length);
            }
            current.move((-1) * width, (-1) * sectorTableSize * length);
        }

    }
}