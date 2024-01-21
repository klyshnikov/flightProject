#include "Flight.h"

namespace flightORM {

    Flight::Flight(std::string id, Plane plane, Position position, double speed) :
    id(id), plane(plane), position(position), speed(speed) {
        //sqlSerialiseManager = flightORM::SqlSerialiseManager(5, id, )
        auto recorded_id = new RecordedFieldImpl<std::string>(&id);
        auto recorded_plane = new RecordedFieldImpl<Plane>(&plane);
        auto recorded_position = new RecordedFieldImpl<Position>(&position);
        auto recorded_speed = new RecordedFieldImpl<double>(&speed);
        sqlSerialiseManager = SqlSerialiseManager(4,recorded_id, recorded_plane, recorded_position, recorded_speed);
    }
}