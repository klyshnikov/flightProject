from FlightParser import FlightParser
from Flightradar24apiDataSource import Flightradar24apiDataSource
from FlightRadar24 import FlightRadar24API


flightParcer = FlightParser()
flightParcer.setParser(Flightradar24apiDataSource())

#flightParcer.parser.getAllAirCompamies()
d = flightParcer.parser.getInfoOfAllCurrentFlights()
print(d[34])


