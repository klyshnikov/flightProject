#include "string"
#include "Plane.h"
#include "Position.h"
#include "vector"
#include "map"

#include "../serialization/sql/SqlSerialiseManager.h"
#include "../serialization/sql/RecordedFieldImpl.h"
//#include "../types/IntType.h"

#ifndef FLIGHT_H
#define FLIGHT_H

namespace flightORM {

    struct Flight {
    public:
        flightORM::SqlSerialiseManager sqlSerialiseManager;

        std::string id;
        flightORM::Plane plane;
        flightORM::Position position;
        //flightORM::Sector sector;
        double speed{};

        Flight();

        //Flight(std::string id, flightORM::Plane plane, flightORM::Position position, double speed);
    };
}

#endif

