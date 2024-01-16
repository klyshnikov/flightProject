#include "Position.h"

namespace flightORM {
    Position::Position() {
        auto recorded_x = new RecordedFieldImpl<double>(&x);
        auto recorded_y = new RecordedFieldImpl<double>(&y);
        auto recorded_hight = new RecordedFieldImpl<double>(&hight);
        sqlSerialiseManager = SqlSerialiseManager(3, recorded_x, recorded_y, recorded_hight);
    }
}