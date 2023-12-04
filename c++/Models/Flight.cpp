#include "Flight.h"

namespace flightORM {
     Flight::Flight() {

     }

    std::vector<IBaseField> Flight::objects() {
         return m_allRecorderFields;
     }
}