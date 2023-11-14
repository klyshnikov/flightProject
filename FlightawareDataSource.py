from DataSource import DataSource
from bs4 import BeautifulSoup
import requests

class FlightawareDataSource(DataSource):
    def getLinkOfAirport(self, airport: str):
        if (len(airport) == 3):
            # IATA code
            airport = DataSource.iataToIcaoMap[airport]
        return "https://ru.flightaware.com/live/airport/" + airport

    def setAirport(self, airport: str):
        if (len(airport) == 3):
            airportICAO = DataSource.iataToIcaoMap[airport]
            airportIATA = airport
        else:
            airportICAO = airport
            airportIATA = DataSource.icaoToIataMap[airport]

    def getTables(self, airport: str, link: str):
        page = requests.get(link)
        bsObject = BeautifulSoup(page.text, "html.parser")
        return bsObject.findAll(class_ = "airportBoardContainer")

    def getFirstRows(self, table: str):
        bsObject = BeautifulSoup(table, "html.parser")
        return bsObject.findAll(class_ = "smallrow1")

    def getLastDepartmentInAirport(self, airport: str):
        link = self.getLinkOfAirport(airport)
        departmentTable = self.getTables(airport, link)[1]
        firstRow = self.getFirstRows(str(departmentTable))[0]
        firstRowInfo = BeautifulSoup(str(firstRow), "html.parser").findAll('a')[0]
        flightLink = str(firstRowInfo)[(str(firstRowInfo).find('"')+1):str(firstRowInfo).rfind('"')]
        flight = firstRowInfo.getText()
        return (flightLink, flight)




