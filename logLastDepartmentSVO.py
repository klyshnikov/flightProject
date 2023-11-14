from FlightawareDataSource import FlightawareDataSource
from FlightParser import FlightParser
from bs4 import BeautifulSoup
import requests
import os

with open("log.txt", 'a+') as file:
    fds = FlightawareDataSource()
    fp = FlightParser()
    a = fp.getLastDepartmentInAirport(fds, "SVO")
    file.write(a[0] + " " + a[1])
