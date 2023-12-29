#include "SqlSerialiseManager.h"

namespace flightORM {

    SqlSerialiseManager::SqlSerialiseManager(std::size_t count, flightORM::Type* field, ...) {
        flightORM::Type* first = field;
        while (count--) {
            recorderedFields.push_back(first);
            ++first;
        }
    }

    void SqlSerialiseManager::addField(flightORM::Type* field) {
        recorderedFields.emplace_back(field);
    }

    std::vector<std::string> SqlSerialiseManager::getFieldNames() {
        std::vector<std::string> fieldNames{};

        for (auto field : recorderedFields) {
            if (field->isPrimary()) {
                fieldNames.emplace_back(field->toString());
            } else {
                for (auto innerField : field->types) {

                }
            }
        }

        return fieldNames;
    }
}