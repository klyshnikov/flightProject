cmake_minimum_required(VERSION 3.17)

set(TFNV tfnv)# Terminal Flight Noise Viewer

project(${TFNV})

set(CMAKE_CXX_STANDARD 17)

add_executable(${TFNV} main.cpp
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
        console/ConsolePrinter.h
        image.generator/SvgGenerator.cpp
        image.generator/SvgGenerator.h
        image.generator/ColorArgument.cpp
        image.generator/ColorArgument.h
        image.generator/PngGenerator.cpp
        image.generator/PngGenerator.h)
