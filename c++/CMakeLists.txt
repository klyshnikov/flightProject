cmake_minimum_required(VERSION 3.27)
project(c___cmake)

set(CMAKE_CXX_STANDARD 17)

add_executable(c___cmake main.cpp
        models/Flight.cpp
        models/Plane.cpp
        models/Position.cpp
        models/Sector.cpp
        models/base.model/Model.cpp
        serialization/sql/RecordedField.cpp
        serialization/sql/RecordedFieldImpl.cpp
        serialization/sql/SqlSerialiseManager.cpp
        serialization/sql/SqlSerializator.cpp
        service/TableChangeService.cpp
        service/TableChangeService.h
)
