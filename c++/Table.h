#include "Models/Model.h"
#include "vector"

namespace flightORM {

    class Table {
    private:
        Model m_modelType;
        std::vector<std::string> m_types;
    };

}
