#include "SqlSerialiseManager.h"

namespace flightORM {

    SqlSerialiseManager::SqlSerialiseManager(std::size_t count, flightORM::RecordedField* field, ...) {
        flightORM::RecordedField* first = field;
        while (count--) {
            recorderedFields.push_back(first);
            ++first;
        }
    }

    SqlSerialiseManager::SqlSerialiseManager(std::vector<RecordedField *> fields) {
        recorderedFields = fields;
    }

    void SqlSerialiseManager::addField(flightORM::RecordedField* field) {
        recorderedFields.emplace_back(field);
    }

    std::vector<std::string> SqlSerialiseManager::getFieldNames() {
        std::vector<std::string> fieldNames{};

        for (auto field : recorderedFields) {
            auto innerFields = field->getFieldNames();
            for (auto innerField : innerFields) {
                fieldNames.push_back(innerField);
            }
        }

        return fieldNames;
    }
}