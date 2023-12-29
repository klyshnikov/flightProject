#include "iostream"
#include "Type.h"

namespace flightORM {

    template <typename T>
    class PrimaryType : public Type {
    public:
        PrimaryType(T* value);

        T getValue();

        std::string toString() override;
    };

}
