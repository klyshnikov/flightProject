#include "Type.h"

namespace flightORM {
    Type::Type(void *value) {
        val = value;
    }

    bool Type::isPrimary() {
        return types.empty();
    }

    std::string Type::toString() {
        return "";
    }
}