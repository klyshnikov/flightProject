cmake_minimum_required(VERSION 3.27)
project(c___cmake)

set(CMAKE_CXX_STANDARD 17)

add_executable(c___cmake test.cpp
        models/Flight.cpp
        models/Flight.h
        models/Plane.cpp
        models/Plane.h
        models/Position.cpp
        models/Position.h
        models/Sector.cpp
        models/Sector.h
        models/base.model/Model.cpp
        models/base.model/Model.h
        serialization/sql/RecordedField.cpp
        serialization/sql/RecordedField.h
        serialization/sql/RecordedFieldImpl.cpp
        serialization/sql/RecordedFieldImpl.h
        serialization/sql/SqlSerialiseManager.cpp
        serialization/sql/SqlSerialiseManager.h
        serialization/sql/SqlSerializator.cpp
        serialization/sql/SqlSerializator.h
        service/TableChangeService.cpp
        service/TableChangeService.h
        methods/Methods.cpp
        methods/Methods.h
        models/table/Table.cpp
        models/table/Table.h
        dao/SqlDao.cpp
        dao/SqlDao.h
        dao/SqlDaoImpl.cpp
        dao/SqlDaoImpl.h
)
