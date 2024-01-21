
#ifndef C___CMAKE_TABLECHANGESERVICE_H
#define C___CMAKE_TABLECHANGESERVICE_H

#include "../models/base.model/Model.h"
#include "../models/table/Table.h"

namespace flightORM {

    class TableChangeService {
    public:
        void insert(const Table& table, Model& model);
    };

}

#endif
