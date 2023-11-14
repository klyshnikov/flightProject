from bs4 import BeautifulSoup
from abc import ABC, abstractmethod
import requests
from DataSource import DataSource
from FlightawareDataSource import FlightawareDataSource


class FlightParser:
    @staticmethod
    def getLastDepartmentInAirport(dataSource: DataSource, airport: str):
        return dataSource.getLastDepartmentInAirport(airport)

    @staticmethod
    def getLastArrivalInAirport(dataSource: DataSource, airport: str):
        return dataSource.getLastArrivalInAirport(airport)
