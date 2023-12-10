#include "Position.h"

namespace flightORM {

    Position::Position(double x, double y, double hight) : x(x), y(y), hight(hight) {
        recorderFieldsManager.add<double>(x, "x");
        recorderFieldsManager.add<double>(y, "y");
        recorderFieldsManager.add<double>(hight, "hight");
    }
}