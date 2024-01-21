

#ifndef RECORDED_FIELD_H
#define RECORDED_FIELD_H
#include "vector"
#include "string"
namespace flightORM {

    class RecordedField {
    public:
        virtual std::vector<std::string> getFieldNames();
    };

}

#endif
