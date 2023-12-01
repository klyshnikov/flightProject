from Parsing.FlightawareParcer import FlightawareParser

flightawareParaser = FlightawareParser()
lastDepartmentSVO = flightawareParaser.getLastDepartmentInAirport("SVO")
with open("../log.txt", 'a+') as file:
    file.write(lastDepartmentSVO[0] + " " + lastDepartmentSVO[1])

