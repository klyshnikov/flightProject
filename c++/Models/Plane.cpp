
#include "Plane.h"

namespace flightORM {

    Plane::Plane(std::string type) : type(type) {
        recorderFieldsManager.add<std::string>(type, "type");
    }
}