#include <iostream>
#include "arguments.parser/ArgumentsParser.h"

using namespace calculation;
int main(int argc, char** argv) {

//    char* zero = "123";
//    char* path = "/home/misha/PycharmProjects/SheremetyegoParce";
//    char* a0 = "sector";
//    char* a2 = "32";
//    char* a3 = "32";
//    char** A = new char*[6] {zero, path, a0, a2, a3};

    ArgumentsParser argumentsParser;
    if (!argumentsParser.parseArguments(argc, argv)) {
        std::cout << "Wrong arguments\n";
    }

    /*
     * while(parser.canParse())
     *      Flight flight = parser.parse()            +
     *      var sectors = Algorithms::getSectors()    +
     *      for (sector in sectors)
     *          Algorithms::countNoise()
     *
     *      for (sector in sectors)
     *          Algorithms::countPesentil()
     *
     * */
}

//void test1() {
//    tm time{};
//    Point me = Point(55.710535, 37.738240);
//    FlightFrame hse = FlightFrame("-", 55.705406, 37.765780, 300, 1000, time, "-");
//    SectorBunch bunch = SectorBunch(me, 1, 1, 5);
//    for (int i = 0; i<5; ++i) {
//        for (int j = 0; j<5; ++j) {
//            std::cout << bunch.sectorTable[i][j].center.latitude << " " << bunch.sectorTable[i][j].center.longitude << "\n";
//        }
//    }
//    std::cout << Algorithms::countDistanceBetweenPointAndFlight(me, hse);
//
//    FlightFrame ff = FlightFrame("-", 57.70, 35.8, 1000, 300, time, "-");
//    auto ss = Algorithms::getNearestSectors(ff, bunch);
//    std::cout << "OK";
//}
