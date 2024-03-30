#include "SvgGenerator.h"
#include "PngGenerator.h"

namespace calculation {

    void SvgGenerator::generateSvgImage(const SectorBunch& sectorBunch, std::string fileName) {
        createSvgImage(fileName);
        addBackground(fileName, sectorBunch);

        for (int i = 0; i<sectorBunch.sectorTableSize; ++i) {
            for (int j = 0; j<sectorBunch.sectorTableSize; ++j) {
                addNoiseInImage(sectorBunch, fileName, i, j);
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
            out << R"__(<?xml version="1.0" standalone="no"?>)__" << "\n"
                << R"__(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)__" << "\n"
                << R"__(<svg version="1.1" width="2048" height="2048" onload="init(evt)" viewBox="0 0 2048 2048" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">)__" << "\n";
        }
        out.close();
    }

   void SvgGenerator::addNoiseInImage(const SectorBunch& sectorBunch, std::string fileName, int i, int j) {
        ColorArgument colorArgument = getColor(Algorithms::countNoiseLevel(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises));
        std::ofstream out;
        out.open(path_+fileName, std::ios::app);
        if (out.is_open()) {
            out << "\t" << R"(<rect x=")" << j*32 << R"(" y=")" << i*32 << R"(" width=")" << 32 << R"(" height=")" << 32 << R"(" fill="rgba()"
            << colorArgument.r_ << ","
            << colorArgument.g_ << ","
            << colorArgument.b_ << ","
            << colorArgument.transparency_
            << ")\"> \n" << getGistogram(sectorBunch, i, j) << R"(</rect>)";
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

    std::string SvgGenerator::getGistogram(const SectorBunch& sectorBunch, int i, int j) {
        std::vector<int> currentSectorDataToShow(24);
        std::vector<int> currentSectorData24Values(24);
        std::string result = "";
        result += "<title>\n";
        for (int i = 0; i < 24; ++i) {
            if (!sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[i].empty()) {
                currentSectorDataToShow[i] = (Algorithms::countNoiseLevelByVector(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[i])/double(max_noise))*bar_chart_size;
                currentSectorData24Values[i] = Algorithms::countNoiseLevelByVector(sectorBunch.sectorTable[i][j].sectorNoise.hourNoises[i]);
            } else {
                currentSectorDataToShow[i] = 0;
                currentSectorData24Values[i] = 0;
            }
        }

        for (int row = bar_chart_size; row >= 1; --row) {
            for (int h = 0; h < 24; ++h) {
                if (currentSectorDataToShow[h] >= row) {
                    result += Algorithms::getStringBiggerSize("#", 3);
                } else {
                    result += Algorithms::getStringBiggerSize(" ", 3);;
                }
            }
            result += "\n";
        }

        for (auto v : currentSectorData24Values) {
            result += Algorithms::getStringBiggerSize(std::to_string(v), 3);
        }
        result += "</title>";
        return result;
    }

}