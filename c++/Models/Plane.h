#include "Model.h"
#include "../IRecordedField.h"

namespace flightORM {

    struct Plane : public Model {
    public:
        std::vector<IBaseField> m_allRecorderFields = {type};

        flightORM::IRecordedField<std::string> type;

        Plane(std::string type);

        Plane(flightORM::IRecordedField<std::string> type);
    };

}
