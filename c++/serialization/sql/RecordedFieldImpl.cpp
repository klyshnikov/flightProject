

#include "RecordedField.h"

namespace flightORM {
    template <typename T>
    RecordedField<T>::RecordedField(T* obj) {
        value = obj;
    }

    template <typename T>
    T RecordedField<T>::getValue() {
        return *((T*)value);
    }
}