#ifndef C___CMAKE_SQLDAO_H
#define C___CMAKE_SQLDAO_H

#include <string>

namespace flightORM {

    class SqlDao {
        virtual void make(std::string request);
    };

}

#endif
