from DataSource import DataSource
from bs4 import BeautifulSoup
import requests

class FlightawareDataSource(DataSource):
    def getLinkOfAirport(airport: str):
        if (len(airport) == 3):
            # IATA code
            airport = iataToIcaoMap[airport]
        return "https://ru.flightaware.com/live/airport/" + airport

    def setAirport(airport: str):
        if (len(airport) == 3):
            airportICAO = iataToIcaoMap[airport]
            airportIATA = airport
        else:
            airportICAO = airport
            airportIATA = icaoToIataMap[airport]

    def getTables(airport: str):
        page = requests.get(link)
        bsObject = BeautifulSoup(page.text, "html.parser")
        return bsObject.findAll(class_ = "airportBoardContainer")

    def getFirstRows(table: str):
        bsObject = BeautifulSoup(table, "html.parser")
        firstRow = bsObject.findAll(class_ = "smallrow1")

    def getLastDepartmentInAirport(airport: str):
        departmentTable = getDepartmentsTables(airport)[1]
        firstRow = getFirstRow(departmentTable)[0]
        firstRowInfo = BeautifulSoup(firstRow, "html.parser").findAll('a')[0]
        flightLink = firstRowInfo[firstRowInfo.find('"'):firstRowInfo.rfind('"')]
        flight = firstRowInfo.getText()
        return (flightLink, flight)




