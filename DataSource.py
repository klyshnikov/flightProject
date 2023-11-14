from abc import ABC, abstractmethod

class DataSource:
    link = None
    airportICAO = None
    airportIATA = None
    icaoToIataMap = {}
    iataToIcaoMap = {}

    @abstractmethod
    def getLinkOfAirport(airport: str):
        pass

    @abstractmethod
    def setAirport(airport: str):
        pass

    @abstractmethod
    def getLastDepartmentInAirport(airport: str):
        pass
