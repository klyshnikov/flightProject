#ifndef CPP_SECTORBUNCH_H
#define CPP_SECTORBUNCH_H

#include <cstdio>
#include <vector>
#include "Sector.h"

namespace calculation {

    class SectorBunch {
    public:
        Sector** sectorTable;
        size_t sectorTableSize;

        SectorBunch(Point center, double length, double width, int sectorTableSize);
    };

}

#endif
