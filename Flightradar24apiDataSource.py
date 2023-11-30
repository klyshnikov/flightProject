from DataSource import DataSource
from bs4 import BeautifulSoup
import requests
from FlightRadar24 import FlightRadar24API

class Flightradar24apiDataSource(DataSource):

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
        DataSource.airCompanies = allAirCompanies

    def getAllCurrentFlights(self):
        self.getAllAirCompamies()
        allCurrentFlights = []
        for company in DataSource.airCompanies:
            allCurrentFlights.extend(self.frObject.get_flights(airline = company))
        return allCurrentFlights

    def getInfoOfAllCurrentFlights(self):
        infoOfAllCurrentFlights = self.getAllCurrentFlights()
        for i in range(len(infoOfAllCurrentFlights)):
            infoOfAllCurrentFlights[i] = {infoOfAllCurrentFlights[i].id : self.frObject.get_flight_details(infoOfAllCurrentFlights[i].id)}
        return infoOfAllCurrentFlights


    def getLastDepartmentInAirport(self, airport: str):
        frObject = FlightRadar24API()
        svo = frObject.get_airport_details(airport)
        for i in svo['airport']['pluginData']['schedule']['departures']['data']:
            if (i['flight']['identification']['id'] != None):
                print(i)
        #print(svo['airport']['pluginData']['schedule']['departures']['data'][2])







        

    




        
