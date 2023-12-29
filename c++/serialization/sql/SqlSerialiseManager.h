#include <cstdarg>
#include "vector"
#include "../../types/Type.h"

namespace flightORM {

    class SqlSerialiseManager {
    private:

        std::vector<Type*> recorderedFields;

    public:
        SqlSerialiseManager() = default;
        SqlSerialiseManager(std::size_t count, flightORM::Type* field, ...);

        void addField(Type* field);
        std::vector<std::string> getFieldNames();
    };
}