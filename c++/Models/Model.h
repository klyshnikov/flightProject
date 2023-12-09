#include "iostream"
#include "vector"
#include "../IBaseField.h"

namespace flightORM {

    struct Model {
    public:
        std::vector<IBaseField> m_allRecorderFields{};
    };

}
