from Parsing.Flightradar24apiParser import Flightradar24apiParser

flightRadarParcer = Flightradar24apiParser()

#flightParcer.parser.getAllAirCompamies()
data = flightRadarParcer.getInfoOfAllCurrentFlights()

with open("../log.txt", 'a+') as file:
    for el in data:
        file.write(el)


