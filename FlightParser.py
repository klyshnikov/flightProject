from bs4 import BeautifulSoup
from abc import ABC, abstractmethod
import requests
from DataSource import DataSource
from FlightawareDataSource import FlightawareDataSource
from Flightradar24apiDataSource import Flightradar24apiDataSource


class FlightParser:
    parser = None

    def setParser(self, parser: DataSource):
        self.parser = parser


    
    
