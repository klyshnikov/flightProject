from abc import ABC, abstractmethod

class DataSource:
    link = None
    airportICAO = None
    airportIATA = None
    icaoToIataMap = {"UUEE": "SVO"}
    iataToIcaoMap = {"SVO": "UUEE"}

    @abstractmethod
    def getLinkOfAirport(self, airport: str):
        pass

    @abstractmethod
    def setAirport(self, airport: str):
        pass

    @abstractmethod
    def getLastDepartmentInAirport(self, airport: str):
        pass
