#include "string"

namespace flightORM {

    template <class T>
    class IRecordedField {
    private:
        T field = nullptr;
        std::string name = nullptr;
    public:
        IRecordedField<T>();
        IRecordedField<T>(std::string name);
        IRecordedField<T>(std::string name, T value);

        void setName (std::string name);
    };

}
