#include "PlaneType.h"
#include "PrimaryType.h"

namespace flightORM {


    PlaneType::PlaneType(std::string* planeType) {
        types = {new PrimaryType<std::string>(planeType)};
    }

    PlaneType::PlaneType(flightORM::Plane *plane) : PlaneType(&plane->type) {}
}