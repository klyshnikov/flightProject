#include "IRecordedField.h"

namespace flightORM {
    template <class T>
    std::vector<std::string> IRecordedField<T>::getValues() {
        std::vector<std::string> values{};
        if (m_isPrimary) {
            values.emplace_back(std::to_string(&m_field));
            return values;
        }

        std::vector<std::string> innerValues;
        for (auto field : m_field->m_allRecorderFields) {
            innerValues = field.getColumns();
            for (auto el : innerValues) {
                values.emplace_back(el);
            }
        }

        return values;
    }
}