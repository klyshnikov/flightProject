#include "base.model/Model.h"
#include "../serialization/sql/SqlSerialiseManager.h"
#include "../serialization/sql/RecordedFieldImpl.h"
#include "vector"

#ifndef POSITION_H
#define POSITION_H

namespace flightORM {

    class Position : public Model {
    public:

        double x;
        double y;
        double hight;

        Position();

        //Position(double x, double y, double hight);

    };

}

#endif
