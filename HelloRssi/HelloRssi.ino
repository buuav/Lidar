#include <XBee.h>

const int rssiPin = A0;

XBee xbee = XBee();

Rx64Response rx64 = Rx64Response();
Rx16Response rx16 = Rx16Response();



void setup()
{
    Serial.begin(9600);
    
    xbee.setSerial(Serial);
    pinMode(rssiPin, INPUT);
 }

void loop()
{
    Serial.println("Waiting");
    xbee.readPacket(100);
    if (xbee.getResponse().isAvailable())
    {
        Serial.println("Got Message");
        if (xbee.getResponse().getApiId() == RX_64_RESPONSE)
        {
            xbee.getResponse().getRx64Response(rx64);
            Serial.print( rx64.getRssi() );
            
        }
        else if(xbee.getResponse().getApiId() == RX_16_RESPONSE){
            xbee.getResponse().getRx16Response(rx16);
            Serial.println( rx16.getRssi() );
            
            Serial.println(pulseIn(rssiPin, HIGH, 25000));
        }
        else{
          Serial.print(xbee.getResponse().getApiId());
        }
    } else if (xbee.getResponse().isError()){
       Serial.print("error"); 
    }
    delay(500);
}
