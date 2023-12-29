#include "PrimaryType.h"

namespace flightORM {
    template<typename T>
    PrimaryType<T>::PrimaryType(T* value) {
        val = value;
    }

    template<typename T>
    T PrimaryType<T>::getValue() {
        return *(T*)val;
    }

    template<typename T>
    std::string PrimaryType<T>::toString() {
        return std::to_string(val);
    }
}