
#include <SoftwareSerial.h>


SoftwareSerial mySerial_1(11,12); // RX,TX
#include <TinyGPS++.h>
int gps1 = 0;
String Lat, Lon;
TinyGPSPlus gps;
int sms_status=0;
void setup()
{
    Serial.begin(9600);
     mySerial_1.begin(9600);
      
}



void loop()
{
  
   while (mySerial_1.available() > 0)
  {
    gps.encode(mySerial_1.read());
    if (gps.location.isUpdated())
    {
      gps1 = 1;
      Lat = String(gps.location.lat(), 6);
      Lon = String(gps.location.lng(), 6);
    }
    else gps1=0;
  }

              Serial.print("\r");
              delay(1000);                  
              Serial.print("AT+CMGF=1\r");    
              delay(1000);
              Serial.print("AT+CMGS=\"+917847072811\"\r");    
              delay(1000);
              if(gps1==1){Serial.print("click for live location :"  "https://www.latlong.net/c/?"+String("lat")+String(Lat)+ String("&long")+String(Lon) ); }
              else{
              Serial.print("click for live location :" "https://www.latlong.net/c/?lat=20.176302&long=85.705821");  } 
              delay(1000);  
               Serial.write(0x1A);

               delay(60000);

              Serial.print("\r");
              delay(1000);                  
              Serial.print("AT+CMGF=1\r");    
              delay(1000);
              Serial.print("AT+CMGS=\"+917847072811\"\r");    
              delay(1000);
              if(gps1==1){Serial.print("click for live location :"  "https://www.latlong.net/c/?"+String("lat")+String(Lat)+ String("&long")+String(Lon) ); }
              else{
              Serial.print("click for live location :" "https://www.latlong.net/c/?lat=20.175321&long=85.705674");  } 
              delay(1000);  
               Serial.write(0x1A);
               delay(60000);

}
