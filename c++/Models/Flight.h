#include "string"
#include "Plane.h"
#include "Position.h"
#include "Sector.h"
#include "vector"
#include "../IBaseField.h"
#include "../IRecordedField.h"
#include "map"

namespace flightORM {

    struct Flight{
    private:
        std::vector<IBaseField> m_allRecorderFields = {id, plane, position, sector, speed};
    public:
        flightORM::IRecordedField<std::string> id;
        flightORM::IRecordedField<flightORM::Plane> plane;
        flightORM::IRecordedField<flightORM::Position> position;
        flightORM::IRecordedField<flightORM::Sector> sector;
        flightORM::IRecordedField<double> speed;

        std::vector<IBaseField> objects();

        Flight();
    };

}

