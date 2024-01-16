#include "iostream"
#include "../serialization/sql/SqlSerialiseManager.h"
#include "../serialization/sql/RecordedFieldImpl.h"
#include "base.model/Model.h"

#ifndef PLANE_H
#define PLANE_H

namespace flightORM {

    struct Plane : public Model {
    public:

        std::string type;

        Plane();

        //Plane(std::string type);

    };

}
#endif
