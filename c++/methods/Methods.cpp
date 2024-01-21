
#include "Methods.h"

namespace flightORM {
    std::string Methods::getFromStringsSqlArrayString(const std::vector<std::string> &line)  {
        std::string sqlArray = "(";
        for (const auto& el : line) {
            sqlArray += el;
            sqlArray += ", ";
        }
        sqlArray.resize(sqlArray.size()-2);
        sqlArray += ")";
        return sqlArray;
    }
}