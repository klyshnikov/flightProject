#include "string"
#include "Plane.h"
#include "Position.h"

namespace flightORM {

    struct Flight {
    public:
        std::string id;
        flightORM::Plane plane;
        flightORM::Position position;
    };

}

