#include "vector"
#include "string"

#ifndef RECORDED_FIELD_H
#define RECORDED_FIELD_H

namespace flightORM {

    class RecordedField {
    public:
        virtual std::vector<std::string> getFieldNames();
    };

}

#endif
