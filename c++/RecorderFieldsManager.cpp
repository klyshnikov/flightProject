#include "RecorderFieldsManager.h"

namespace flightORM {
    template <class T>
    void RecorderFieldsManager::add(T& el, std::string name) {
        m_recorder_fields.emplace_back(&IRecordedField<T>(&el, name));
    }
}