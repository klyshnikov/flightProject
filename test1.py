from FlightRadar24 import FlightRadar24API

fr_api = FlightRadar24API()
airport = fr_api.get_airport("UUEE")
flight = fr_api.get_flights()[1:100]
for i in flight:
    print(fr_api.get_flight_details(i.id)['status'])

print(det)
