#include "Flight.h"
#include "../IRecordedField.h"
#include "../RecorderFieldsManager.h"

namespace flightORM {

    std::vector<IBaseField> Flight::objects() {
         return m_allRecorderFields;
     }

    Flight::Flight(std::string id, flightORM::Plane plane, flightORM::Position position,
                   flightORM::Sector sector, double speed) : id(id), plane(plane),
                   position(position), sector(sector), speed(speed) {
        recorderFieldsManager.add<std::string>(id, "id");
        recorderFieldsManager.add<flightORM::Plane>(plane, "plane");
        recorderFieldsManager.add<flightORM::Position>(position, "position");
        recorderFieldsManager.add<flightORM::Sector>(sector, "sector");
        recorderFieldsManager.add<double>(speed, "speed");
    }
}