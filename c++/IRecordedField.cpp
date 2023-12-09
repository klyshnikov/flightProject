#include "IRecordedField.h"

namespace flightORM {
    template <class T>
    std::vector<std::string> IRecordedField<T>::getColumns() {
        std::vector<std::string> colums{};
        if (m_isPrimary) {
            colums.emplace_back(std::to_string(&m_field));
            return colums;
        }
        
        std::vector<std::string> innerColumns;
        for (auto field : m_field->m_allRecorderFields) {
            innerColumns = field.getColumns();
            for (auto el : innerColumns) {
                colums.emplace_back(el);
            }
        }

        return colums;
    }
}