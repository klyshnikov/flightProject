#include "Type.h"
#include "PrimaryType.h"
#include "../models/Position.h"

namespace flightORM {

    class PositionType : public Type {
        PositionType(Position* position);
        PositionType(double* x, double* y, double* hight);
    };

}
