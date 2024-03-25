#include "ConsolePrinter.h"

#include "../algorithms/Algorithms.h"

namespace calculation {

    void ConsolePrinter::printNoiseByVector(noise_1hour_in_sector values) {
        if (!values.empty()) {
            auto count = Algorithms::countNoiseLevelByVector(values);
            std::cout << getColoredInt(count, 2);
            //getColoredInt(Algorithms::getStringBiggerSize(std::to_string(Algorithms::countNoiseLevelByVector(values)), 2), Algorithms::countNoiseLevelByVector(values));
            std::cout << " ";
        } else {
            std::cout << getColoredInt(0    , 2) << " ";
            //std::cout << "\x1B[31mTexting\033[0m";
        }
    }

    void ConsolePrinter::printNoiseBy24Vectors(noise_24hour_in_sector values) {
        auto count = Algorithms::countNoiseLevel(values);
        std::cout << getColoredInt(count, 2);
        //getColoredInt(Algorithms::getStringBiggerSize(std::to_string(Algorithms::countNoiseLevelByVector(values)), 2), Algorithms::countNoiseLevelByVector(values));
        std::cout << " ";
    }

    void ConsolePrinter::printSectorNoiseByVector(std::vector<double>* currentSectorData) {
        std::vector<int> currentSectorDataToShow(24);
        std::vector<int> currentSectorData24Values(24);
        for (int i = 0; i < 24; ++i) {
            if (!currentSectorData[i].empty()) {
                currentSectorDataToShow[i] = (double(std::accumulate(currentSectorData[i].begin(), currentSectorData[i].end(), 0) / double(currentSectorData[i].size()))/max_noise)*bar_chart_size;
                currentSectorData24Values[i] = std::accumulate(currentSectorData[i].begin(), currentSectorData[i].end(), 0) / double(currentSectorData[i].size());
            } else {
                currentSectorDataToShow[i] = 0;
                currentSectorData24Values[i] = 0;
            }
        }

        for (int row = bar_chart_size; row >= 1; --row) {
            for (int h = 0; h < 24; ++h) {
                if (currentSectorDataToShow[h] >= row) {
                    std::cout << Algorithms::getStringBiggerSize("#", 3);
                } else {
                    std::cout << Algorithms::getStringBiggerSize(" ", 3);;
                }
            }
            std::cout << "\n";
        }

        for (auto v : currentSectorData24Values) {
            std::cout << Algorithms::getStringBiggerSize(std::to_string(v), 3);
        }
    }

    std::string ConsolePrinter::getColoredInt(int value, int maxSize) {
        std::vector<std::string> starts = {"\x1B[33m","\x1B[31m"};
        if (value == 0) {
            return "\x1B[32m" + Algorithms::getStringBiggerSize(std::to_string(value), maxSize) + "\033[0m";
        }
        return starts[2*value/max_noise] + Algorithms::getStringBiggerSize(std::to_string(value), maxSize) + "\033[0m";
    }
}