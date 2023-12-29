#include "string"
#include "Plane.h"
#include "Position.h"
#include "Sector.h"
#include "vector"
#include "map"
#include "../SqlRecorderedField.h"
#include "../serialization/sql/SqlSerialiseManager.h"
#include "../types/PrimaryType.h"
#include "../types/PlaneType.h"
#include "../types/PositionType.h"
//#include "../types/IntType.h"

namespace flightORM {

    struct Flight {
    public:
        flightORM::SqlSerialiseManager sqlSerialiseManager;

        std::string id;
        flightORM::Plane plane;
        flightORM::Position position;
        //flightORM::Sector sector;
        double speed;

        Flight();

        Flight(std::string id, flightORM::Plane plane,
               flightORM::Position position, flightORM::Sector sector, double speed);
    };
}

