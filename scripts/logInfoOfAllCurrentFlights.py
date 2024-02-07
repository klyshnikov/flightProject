# some_file.py
import sys
import json
# caution: path[0] is reserved for script path (or '' in REPL)
sys.path.insert(1, '../')


from parsing.Flightradar24apiParser import Flightradar24apiParser

flightRadarParcer = Flightradar24apiParser()

#flightParcer.parser.getAllAirCompamies()
data = flightRadarParcer.getInfoOfAllCurrentFlights()

with open("log.json", 'a+') as file:
    for el in data:
        file.write(json.dumps(el))
        break


