from parsing.DataSource import DataSource
from bs4 import BeautifulSoup
import requests
from FlightRadar24 import FlightRadar24API

class Flightradar24apiParser(DataSource):

    frObject = FlightRadar24API()

    def flightIsOnAir(self, status: dict):
        return (status['live'] == True and status['text'].startswith('Estimated'))

    def getAllAirCompamies(self):
        link = "https://www.flightradar24.com/data/airlines"
        user_agent = ('Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:50.0) '
                      'Gecko/20100101 Firefox/50.0')
        allAirCompanies = []
        page = requests.get(link, headers ={'User-Agent':user_agent})
        bsObject = BeautifulSoup(page.text, "html.parser")
        tbody = bsObject.findAll('tbody')
        bsObject = BeautifulSoup(str(tbody), "html.parser")
        trs = bsObject.findAll('tr', class_ = "")
        bsObject = BeautifulSoup(str(trs), "html.parser")
        text_right_list = bsObject.findAll(class_ = "text-right")
        for text_right in text_right_list:
            textRightContent = text_right.getText()
            if ('aircraft' not in textRightContent):
                names = textRightContent.replace(" ", "").split('/')
                allAirCompanies.append(names[0])
                if (len(names) > 1):
                    allAirCompanies.append(names[1])
        return allAirCompanies

    def getAllCurrentFlights(self):
        airCompanies = self.getAllAirCompamies()
        allCurrentFlights = []
        print(f"all air compnies count = {len(airCompanies)}")
        #for company in airCompanies:
        #    allCurrentFlights.extend(self.frObject.get_flights(airline = company))
        allCurrentFlights.extend(self.frObject.get_flights(airline = "AFL"))
        print(f"afl flights count = {len(allCurrentFlights)}")
        return allCurrentFlights

    def getInfoOfAllCurrentFlights(self):
        allCurrentFlights = self.getAllCurrentFlights()
        infoOfAllCurrentFlights = []
        size = 0
        flightsIter = 0
        while (size < len(allCurrentFlights)):
            first = allCurrentFlights[flightsIter].id
            second_id = allCurrentFlights[flightsIter]
            second = self.frObject.get_flight_details(second_id)
            infoOfAllCurrentFlights.append( {first: second})
            size += 1
            flightsIter += 1
            if (flightsIter>1):
                print(f"len current flights info = {len(infoOfAllCurrentFlights)}")
                break
        return infoOfAllCurrentFlights


    def getLastDepartmentInAirport(self, airport: str):
        frObject = FlightRadar24API()
        details = frObject.get_airport_details(airport)
        for i in details['airport']['pluginData']['schedule']['departures']['data']:
            if (i['flight']['identification']['id'] != None):
                print(i)
        #print(svo['airport']['pluginData']['schedule']['departures']['data'][2])







        

    




        
