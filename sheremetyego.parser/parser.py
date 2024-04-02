import sys
from RealTimeParser import RealTimeParser

arguments = sys.argv

parser = RealTimeParser()
parser.logSheremetyegoFlights(int(arguments[1]), float(arguments[2]), float(arguments[3]))
