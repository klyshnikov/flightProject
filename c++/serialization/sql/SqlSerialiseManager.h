#include <cstdarg>
#include "vector"
#include "RecordedFieldImpl.h"

#ifndef SQL_SERIALISE_MANAGER_H
#define SQL_SERIALISE_MANAGER_H

namespace flightORM {

    class SqlSerialiseManager {
    private:

        std::vector<RecordedField*> recorderedFields;

    public:
        SqlSerialiseManager() = default;
        SqlSerialiseManager(std::size_t count, flightORM::RecordedField* field, ...);
        SqlSerialiseManager(std::vector<RecordedField*> fields);

        void addField(RecordedField* field);
        std::vector<std::string> getFieldNames();
    };

}

#endif