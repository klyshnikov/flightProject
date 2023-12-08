#include "string"
#include "IBaseField.h"

namespace flightORM {

    template<class T>
    class IRecordedField : public IBaseField {
    private:
        T m_field = nullptr;
        std::string m_name = nullptr;
        std::string m_type;
    public:
        class stringiIterator : public std::iterator <std::input_iterator_tag, IBaseField*> {
        public:
            bool operator!=(IRecordedField const& other) const;
            bool operator==(IRecordedField const& other) const;
            stringiIterator& operator++();
            reference operator*();

            //TODO: logic
        };

        bool m_isPrimary;

        IRecordedField<T>();

        IRecordedField<T>(std::string name);

        IRecordedField<T>(std::string name, T value);

        void setName(std::string name);

        void setValue(T field);
    };

}
