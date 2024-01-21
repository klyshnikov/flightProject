#include "TableChangeService.h"
#include "../methods/Methods.h"

namespace flightORM {
    void TableChangeService::insert(const flightORM::Table& table, flightORM::Model& model) {
        std::vector<std::string> line = model.sqlSerialiseManager.getFieldNames();

        std::string lineInString = Methods::getFromStringsSqlArrayString(line);

        std::string request = "INSERT INTO " + table.name + " VALUES " + lineInString;
        //sqlDao.make(request);
    }
}