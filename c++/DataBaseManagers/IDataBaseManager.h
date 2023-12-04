#include "../Table.h"
#include "../IRecordedField.h"
#include "../Models/Model.h"
#include "vector"

namespace flightORM {
    class IDataBaseManager {
        Table createTable();
        virtual void Insert(Table* table, Model* model_obj);
        virtual void Select(Table* table, const std::vector<std::string>& columns);

        // TODO : methods
    };
}

