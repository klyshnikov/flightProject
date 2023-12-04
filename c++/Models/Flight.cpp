#include "Flight.h"

namespace flightORM {
     Flight::Flight() {

     }

    std::vector<BaseField> Flight::objects() {
         return allRecorderFields;
     }
}