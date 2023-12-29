#include "iostream"
#include "Type.h"
#include "../models/Plane.h"

namespace flightORM {

    class PlaneType : public Type {
    public:
        PlaneType(Plane* plane);
        PlaneType(std::string* planeType);
    };

}