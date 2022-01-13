'''import phonenumbers

number="+919182703837"

from phonenumbers import geocoder
num=phonenumbers.parse(number,"CH")
yourlocation=geocoder.description_for_number(num,"en")
print(geocoder.description_for_number(num,"en"))
key="6c88f3edf15448a582a99183d722b39c"
from phonenumbers import carrier
service=phonenumbers.parse(number,"RO")
print(carrier.name_for_number(service,"en"))
from opencage.geocoder import OpenCageGeocode
geocoder =OpenCageGeocode(key)
query=str(yourlocation)
results=geocoder.geocode(query)
#print(results)

lat=results[0]['geometry']['lat']
lng=results[0]['geometry']['lng']
print(lat,lng)
import folium
mymap=folium.Map(location=[lat,lng],zoom_start=9)
folium.Marker([lat,lng],popup=yourlocation).add_to((mymap))
mymap.save("mymap.html")'''
import pywhatkit
pywhatkit.sendwhatmsg('+919391156195','hii',1,48)