#include <vector>
#include "iostream"
#include "sql.types/SqlInt.h"

int main() {
    // Пример
    /*
     sqliteManager = ISqliteManager();
     Table flightsTable = sqliteManager.createTable();
     Table nowFlightTable = sqliteManager.createTable();
     Flight flight;

     for (auto el : file) {
        flight = Flight(el.params());
        sqliteManager.Insert(flightTable, flight);

        if (flight.isOnAir()) {
            sqliteManager.Insert(nowFlightTable, flight);
        }
     }

     По итогу 2 записанные таблицы

     * */

    int a = 5;
    auto obj1 = new flightORM::SqlInt(3);
    auto obj2 = new flightORM::SqlInt(3);
    auto obj3 = new flightORM::SqlInt(3);
    std::vector<flightORM::SqlType*> v = {obj1, obj2, obj3};
    std::cout << v[1]->getValue();
}