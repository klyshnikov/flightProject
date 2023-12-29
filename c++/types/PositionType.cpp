#include "PositionType.h"

namespace flightORM {
    PositionType::PositionType(flightORM::Position *position) :
    PositionType(
            &position->x,
            &position->y,
            &position->hight ) {}

    PositionType::PositionType(double* x, double* y, double* hight) {
        types = {new PrimaryType<double>(x), new PrimaryType<double>(y), new PrimaryType<double>(hight)};
    }
}