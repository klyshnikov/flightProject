#include "Model.h"
#include "../IRecordedField.h"
#include "../RecorderFieldsManager.h"


namespace flightORM {

    struct Plane : public Model {
    public:
        RecorderFieldsManager recorderFieldsManager;

        std::string type;

        Plane() = default;

        Plane(std::string type);

    };

}
