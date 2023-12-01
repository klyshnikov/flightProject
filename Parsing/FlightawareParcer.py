from Parsing.DataSource import DataSource
from bs4 import BeautifulSoup
import requests

class FlightawareParser(DataSource):
    def getLinkOfAirport(self, airport: str):
        if (len(airport) == 3):
            # IATA code
            airport = DataSource.iataToIcaoMap[airport]
        return "https://ru.flightaware.com/live/airport/" + airport

    def getTables(self, airport: str, link: str):
        page = requests.get(link)
        bsObject = BeautifulSoup(page.text, "html.parser")
        return bsObject.findAll(class_ = "airportBoardContainer")

    def getDepartmentTable(self, tables):
        return tables[0]

    def getFirstRow(self, table: str):
        bsObject = BeautifulSoup(table, "html.parser")
        return bsObject.findAll(class_ = "smallrow1")[0]

    def getLastDepartmentInAirport(self, airport: str):
        link = self.getLinkOfAirport(airport)
        departmentTable = self.getDepartmentTable(self.getTables(airport, link))
        firstRow = self.getFirstRow(str(departmentTable))
        firstRowInfo = BeautifulSoup(str(firstRow), "html.parser").findAll('a')[0]
        flightLink = str(firstRowInfo)[(str(firstRowInfo).find('"')+1):str(firstRowInfo).rfind('"')]
        flight = firstRowInfo.getText()
        return (flightLink, flight)




