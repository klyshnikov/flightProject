#include "iostream"

namespace flightORM {

    template <typename T>
    class RecordedField {
    private:
        void* value;
    public:
        RecordedField(T* obj);

        T getValue();

    };

}