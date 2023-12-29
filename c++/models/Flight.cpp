#include "Flight.h"

namespace flightORM {

    Flight::Flight() {
        //sqlSerialiseManager = flightORM::SqlSerialiseManager(5, id, )
        auto recorded_id = new PrimaryType<std::string>(&id);
        auto recorded_plane = new PlaneType(&plane);
        auto recorded_position = new PositionType(&position);
        auto recorded_speed = new PrimaryType<double>(&speed);
        sqlSerialiseManager = SqlSerialiseManager(4,recorded_id, recorded_plane, recorded_position, recorded_speed);
    }
}