#include "string"
#include "vector"
#include "IBaseField.h"
#include "Models/Model.h"

namespace flightORM {

    template<class T = Model>
    class IRecordedField : public IBaseField {
    private:
        T* m_field = nullptr;
        std::string m_type = nullptr;
    public:
//        class stringiIterator : public std::iterator <std::input_iterator_tag, IBaseField*> {
//        public:
//            bool operator!=(IRecordedField const& other) const;
//            bool operator==(IRecordedField const& other) const;
//            stringIterator& operator++();
//            reference operator*();
//
//            //TODO: logic
//        };

        bool m_isPrimary;

        IRecordedField<T>();

        IRecordedField<T>(T* field);

        IRecordedField<T>(T* field, std::string name);

        void setName(std::string name);

        void setValue(T field);

        std::vector<std::string> getValues();
        std::vector<std::string> getTypes();
    };

}
