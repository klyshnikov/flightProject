#include "string"
#include "Plane.h"
#include "Position.h"
#include "Sector.h"
#include "vector"
#include "IRecordedField.h"
#include "map"

namespace flightORM {

    struct Flight {
    public:
        flightORM::IRecordedField<std::string> id;
        flightORM::Plane plane;
        flightORM::Position position;
        flightORM::Sector sector;
        double speed;

        

        Flight();
    };

}

