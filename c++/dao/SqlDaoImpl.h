
#ifndef C___CMAKE_SQLDAOIMPL_H
#define C___CMAKE_SQLDAOIMPL_H

#include "SqlDao.h"

namespace flightORM {

    class SqlDaoImpl : public SqlDao {
    public:
        void make(std::string) override;
    };

}

#endif
