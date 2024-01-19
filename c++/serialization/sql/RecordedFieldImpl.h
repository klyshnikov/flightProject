#include "iostream"
#include "RecordedField.h"

#ifndef RECORDED_FIELD_IMPL_H
#define RECORDED_FIELD_IMPL_H

namespace flightORM {

    template <typename T>
    class RecordedFieldImpl : public RecordedField {
    private:
        T* value;
    public:
        explicit RecordedFieldImpl(T* obj);
        T getValue();
        std::vector<std::string> getFieldNames() override;
    };

}

#endif