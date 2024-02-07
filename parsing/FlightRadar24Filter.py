from FlightRadar24 import FlightRadar24API, Flight


class FlightRadar24Filter:
    def get_flight_data_by_flight_array(self, flights: list[Flight], fr_object: FlightRadar24API):
        filtered_data: list[Flight] = []
        for flight in flights:
            primary_data: dict = fr_object.get_flight_details(flight)

            if primary_data['status']['live'] == False or primary_data['status']['text'].split()[0] == "Landed":
                continue

            filtered_data.append(flight)

        return filtered_data
