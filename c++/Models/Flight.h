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

namespace flightORM {

    struct Flight : public Model {
    public:
        std::vector<IBaseField> m_allRecorderFields = {id, plane, position, sector, speed};

        flightORM::IRecordedField<std::string> id;
        flightORM::IRecordedField<flightORM::Plane> plane;
        flightORM::IRecordedField<flightORM::Position> position;
        flightORM::IRecordedField<flightORM::Sector> sector;
        flightORM::IRecordedField<double> speed;

        std::vector<IBaseField> objects();

        Flight();

        Flight(std::string id, flightORM::Plane plane,
               flightORM::Position position, flightORM::Sector sector, double speed);

        Flight( flightORM::IRecordedField<std::string> id,
               flightORM::IRecordedField<flightORM::Plane> plane,
               flightORM::IRecordedField<flightORM::Position> position,
               flightORM::IRecordedField<flightORM::Sector> sector,
               flightORM::IRecordedField<double> speed );
    };
}

