'''
Program parse Sheremetyevo arrivals and return data of the last arrival
'''

from bs4 import BeautifulSoup
import requests

url = "https://ru.flightaware.com/live/airport/UUEE"
page = requests.get(url)
soup = BeautifulSoup(page.text, "html.parser")

tmp = (soup.findAll(class_ = "airportBoardContainer"))[1]
#smallrow1
soup2 = BeautifulSoup(str(tmp), "html.parser")
tmp2 = (soup2.findAll(class_ = "smallrow1"))[0]
#print(tmp2)
soup3 = BeautifulSoup(str(tmp2), "html.parser")
tmp3 = soup3.findAll('a')
print(tmp3[0])
print(tmp3[0].getText())

from bs4 import BeautifulSoup
import requests
