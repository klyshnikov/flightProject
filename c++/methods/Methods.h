
#ifndef C___CMAKE_METHODS_H
#define C___CMAKE_METHODS_H

#include <string>
#include <vector>

namespace flightORM {

    class Methods {
    public:
        static std::string getFromStringsSqlArrayString(const std::vector<std::string> &line);
    };

}

#endif
