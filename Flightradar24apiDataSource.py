from DataSource import DataSource
from bs4 import BeautifulSoup
import requests
from FlightRadar24 import FlightRadar24API

class Flightradar24apiDataSource(DataSource):

    def flightIsOnAir(status: map):
        return (status['live'] == True and status['text'].startswith('Estimated'))

    def logAllFlights():
        frObject = FlightRadar24API()
        allFlights = fr_api.get_flights()
        flightDetails = None
        for flight in allFlights:
            flightDetails = frObject.get_flight_details(flight.id)
            status = flightDetails['status']
            if (flightIsOnAir(status)):
                
