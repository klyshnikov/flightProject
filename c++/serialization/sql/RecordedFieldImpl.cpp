

#include "RecordedFieldImpl.h"
#include "../../models/base.model/Model.h"

namespace flightORM {
    //class Model;

    template <typename T>
    RecordedFieldImpl<T>::RecordedFieldImpl(T* obj) {
        value = obj;
    }

    template <typename T>
    T RecordedFieldImpl<T>::getValue() {
        return *((T*)value);
    }

    template <typename T>
    std::vector<std::string> RecordedFieldImpl<T>::getFieldNames() {
        if (std::is_base_of_v<Model, T>) {
            return Model(value).sqlSerialiseManager.getFieldNames();
        } else {
            return {std::string(*value)};
        }
    }
}