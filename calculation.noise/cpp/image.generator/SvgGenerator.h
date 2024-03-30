#ifndef TFNV_SVGGENERATOR_H
#define TFNV_SVGGENERATOR_H

#include <iostream>
#include <fstream>

#include "../models/SectorBunch.h"
#include "ColorArgument.h"
#include "../algorithms/Algorithms.h"

namespace calculation {

    class SvgGenerator {
    public:
        std::string path_ = "pictures/";

        void generateSvgImage(const SectorBunch& sectorBunch, std::string fileName);
        ColorArgument getColor(int noise);

        void createSvgImage(std::string fileName);
        void addNoiseInImage(int noise, std::string fileName, int i, int j);
        void endSvgFile(std::string fileName);
        void addBackground(std::string fileName, const SectorBunch& sectorBunch);
    };

}

#endif
