#include "dht.h"  
#include <MQ2.h>
#include <SPI.h>
#include <Ethernet.h>
#include "ThingSpeak.h"
#define dht_apin 8 // Analog Pin sensor is connected to
const int trigPin = A2;
const int echoPin = A1;
int pin = A3;

 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient client;

unsigned long myChannelNumber = 627829;
const char * myWriteAPIKey = "OCJ0Z253X903UDPP" ;

int lpg, co, smoke;
long duration;
int distance;
dht DHT;
MQ2 mq2(pin);
int hum,temp;
IPAddress ip(192, 168, 137, 1);
void setup() 
{
//    Ethernet.init(10);  
    Serial.begin(9600); // Starts the serial communication

      if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
     Ethernet.begin(mac, ip);
     //Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(250);
  Serial.println("connecting...");
    ThingSpeak.begin(client);  
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  delay(250);//Delay to let system boot
  mq2.begin();
  delay(500);//Wait before accessing Sensor
  pinMode(2, INPUT);


}

void loop()
{
    float* values= mq2.read(true); //set it false if you don't want to print the values in the Serial
    DHT.read11(dht_apin);
    hum=DHT.humidity;
    temp=DHT.temperature;
    lpg = mq2.readLPG();
    co = mq2.readCO();
    smoke = mq2.readSmoke();
    delay(1000);//Wait 5 seconds before accessing sensor again.
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.print("Current humidity = ");
    Serial.print(hum);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(temp); 
    Serial.println("C  ");
    delay(20000);
     if (digitalRead(2) == 1)
     {
       Serial.println("Tilted");
     }
       ThingSpeak.setField(1, lpg);
  ThingSpeak.setField(2, co);
  ThingSpeak.setField(3, smoke);
  ThingSpeak.setField(4, distance);
  ThingSpeak.setField(5,hum);
  ThingSpeak.setField(6, temp);

 ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
 delay(2000);
}
    
