cmake_minimum_required(VERSION 3.27)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp main.cpp
        variables/Variables.h
        models/FlightFrame.cpp
        models/FlightFrame.h
        algorithms/Algorithms.cpp
        algorithms/Algorithms.h
        models/Point.cpp
        models/Point.h
        models/Sector.cpp
        models/Sector.h
        models/SectorBunch.cpp
        models/SectorBunch.h
        models/SectorNoise.cpp
        models/SectorNoise.h
        text.parser/FlightsLogParser.cpp
        text.parser/FlightsLogParser.h
        arguments.parser/ArgumentsParser.cpp
        arguments.parser/ArgumentsParser.h
        console/ConsolePrinter.cpp
        console/ConsolePrinter.h)
