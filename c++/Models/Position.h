#include "Model.h"
#include "../IBaseField.h"
#include "../IRecordedField.h"
#include "vector"

namespace flightORM {

    class Position {
    public:
        RecorderFieldsManager recorderFieldsManager;

        double x;
        double y;
        double hight;

        Position() = default;

        Position(double x, double y, double hight);

    };

}
