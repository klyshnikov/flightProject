#include "SvgGenerator.h"
#include "PngGenerator.h"

namespace calculation {

    void SvgGenerator::generateSvgImage(const SectorBunch& sectorBunch, std::string fileName) {
        createSvgImage(fileName);
        addBackground(fileName, sectorBunch);

        for (int i = 0; i<sectorBunch.sectorTableSize; ++i) {
            for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
                int noise = Algorithms::countNoiseLevel(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises);
                addNoiseInImage(noise, fileName, i, j);
            }
        }

        endSvgFile(fileName);
    }

    ColorArgument SvgGenerator::getColor(int noise) {
        int redScale = std::min(255.0, (double(noise)/max_noise)*500);
        //double transparencyScale = (redScale/255.0)*0.5;
        return ColorArgument(redScale, 255-redScale, 0, 0.3);
    }

    void SvgGenerator::createSvgImage(std::string fileName) {
        std::ofstream out;
        out.open(path_+fileName);
        if (out.is_open()) {
            out << R"(<svg width="2048" height="2048" xlink="https://www.w3.org/2000/svg">)";
            out << "\n";
        }
        out.close();
    }

    void SvgGenerator::addNoiseInImage(int noise, std::string fileName, int i, int j) {
        ColorArgument colorArgument = getColor(noise);
        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            out << "\t" << R"(<rect x=")" << j*32 << R"(" y=")" << i*32 << R"(" width=")" << 32 << R"(" height=")" << 32 << R"(" fill="rgba()"
            << colorArgument.r_ << ","
            << colorArgument.g_ << ","
            << colorArgument.b_ << ","
            << colorArgument.transparency_
            << ")\" /> \n";
        }
        out.close();
    }

    void SvgGenerator::endSvgFile(std::string fileName) {
        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            out << "</svg> \n";
        }
        out.close();
    }

    void SvgGenerator::addBackground(std::string fileName, const SectorBunch& sectorBunch) {
        PngGenerator::generatePng(sectorBunch.center_.latitude, sectorBunch.center_.longitude);

        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            out << R"(<image href="map.png" x="0" y="0" height="2048" width="2048" />)";
        }
        out.close();
    }


}