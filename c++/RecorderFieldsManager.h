#include "IRecordedField.h"
#include "vector"

namespace flightORM {

    class RecorderFieldsManager {
    public:
        std::vector<IBaseField*> m_recorder_fields{};

        template<class T>
        void add(T& el, std::string name);
    };
}
