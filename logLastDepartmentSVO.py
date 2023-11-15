from FlightawareDataSource import FlightawareDataSource
from FlightParser import FlightParser
from bs4 import BeautifulSoup
import requests
import os

with open("log.txt", 'a+') as file:
    lastDepartmentSVO = FlightParser.getLastDepartmentInAirport(FlightawareDataSource(), "SVO")
    file.write(lastDepartmentSVO[0] + " " + lastDepartmentSVO[1])
