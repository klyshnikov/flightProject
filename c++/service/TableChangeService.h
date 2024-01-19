

#ifndef C___CMAKE_TABLECHANGESERVICE_H
#define C___CMAKE_TABLECHANGESERVICE_H

#include "../models/base.model/Model.h"

namespace flightORM {

    class TableChangeService {
    public:
        void insert(/*Table table, */ Model* model) {
            std::vector<std::string> line = model->sqlSerialiseManager.getFieldNames();
            std::string request = "INSERT INTO " + std::string() + "VALUES";
            //sqlDao.make(request);
        }
    };

}

#endif
