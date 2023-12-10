#include "string"
#include "Plane.h"
#include "Position.h"
#include "Sector.h"
#include "vector"
#include "../IBaseField.h"
#include "../IRecordedField.h"
#include "map"
#include "../DataBaseManagers/IDataBaseManager.h"
#include "Model.h"
#include "../RecorderFieldsManager.h"

namespace flightORM {

    struct Flight : public Model {
    public:
        RecorderFieldsManager recorderFieldsManager;

        std::string id;
        flightORM::Plane plane;
        flightORM::Position position;
        flightORM::Sector sector;
        double speed;

        std::vector<IBaseField> objects();

        Flight() = default;

        Flight(std::string id, flightORM::Plane plane,
               flightORM::Position position, flightORM::Sector sector, double speed);
    };
}

