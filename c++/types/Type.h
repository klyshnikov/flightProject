#include "iostream"
#include "vector"

namespace flightORM {

    class Type {
    protected:
        void* val;
        std::vector<Type> types;
    public:
        Type() = default;
        Type(void* value);

        bool isPrimary();
        virtual std::string toString();
    };
}
