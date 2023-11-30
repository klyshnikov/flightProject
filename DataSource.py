from abc import ABC, abstractmethod

class DataSource:
    link = None
    airportICAO = None
    airportIATA = None
    icaoToIataMap = {"UUEE": "SVO"}
    iataToIcaoMap = {"SVO": "UUEE"}
    airCompanies = []

    def setAirport(self, airport: str):
        if (len(airport) == 3):
            airportICAO = DataSource.iataToIcaoMap[airport]
            airportIATA = airport
        else:
            airportICAO = airport
            airportIATA = DataSource.icaoToIataMap[airport]


    @abstractmethod
    def getLinkOfAirport(self, airport: str):
        pass

    @abstractmethod
    def getLastDepartmentInAirport(self, airport: str):
        pass

    @abstractmethod
    def logAllFlights(self):
        pass
