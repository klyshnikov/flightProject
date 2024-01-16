
#include "Plane.h"

namespace flightORM {

    Plane::Plane() {
        auto recorded_type = new RecordedFieldImpl<std::string>(&type);
        sqlSerialiseManager = SqlSerialiseManager(1, recorded_type);
    }
}