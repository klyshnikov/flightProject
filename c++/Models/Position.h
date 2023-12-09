#include "Model.h"
#include "../IBaseField.h"
#include "../IRecordedField.h"
#include "vector"

namespace flightORM {

    class Position {
    public:
        std::vector<IBaseField> m_allRecorderFields = {x, y, hight};

        flightORM::IRecordedField<double> x;
        flightORM::IRecordedField<double> y;
        flightORM::IRecordedField<double> hight;

        Position(double x, double y, double hight);

        Position( flightORM::IRecordedField<double> x,
                 flightORM::IRecordedField<double> y,
                 flightORM::IRecordedField<double> hight );
    };

}
