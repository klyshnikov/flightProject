#include "string"
#include "IBaseField.h"

namespace flightORM {

    template<class T>
    class IRecordedField : public IBaseField {
    private:
        T m_field = nullptr;
        std::string m_name = nullptr;
    public:
        IRecordedField<T>();

        IRecordedField<T>(std::string name);

        IRecordedField<T>(std::string name, T value);

        void setName(std::string name);

        void setValue(T field);
    };

}
