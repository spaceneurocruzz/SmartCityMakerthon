#include <SoftwareSerial.h>
#include "ESP8266WiFi.h"

#define DEBUG
#define IP "184.106.153.149"

// WiFi parameters to be configured
const char* ssid = "Fablab Dynamic_2.4G_1F";
const char* password = "fabtruck";
  const int trigPin = 4;
  const int echoPin = 5;

int distant=0;
String GET = "GET /update?key=[UYQLNLVFJ84YZ2WW]";
void setup(void)
{ 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }
  if(WiFi.status() == WL_CONNECTED){
    Serial.print("connected");
    delay(500);
    }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  

}
void loop() {
    long duration, inches, cm;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
    Serial.println(WiFi.localIP());

}
  long microsecondsToInches(long microseconds) {
    return microseconds / 74 / 2;
  }
  

  long microsecondsToCentimeters(long microseconds) {
    distant = microseconds / 29 / 2;
    update_sonic(distant);
    return microseconds / 29 / 2;
  }
void update_sonic( int distant)
{
    // 設定 ESP8266 作為 Client 端
    String cmd = "AT+CIPSTART=\"TCP\",\"";
    cmd += IP;
    cmd += "\",80";
    sendDebug(cmd);
    delay(2000);


    cmd = GET + "&field1=" + distant ;
    Serial.print( "AT+CIPSEND=" );
    Serial.println( cmd.length() );

}

void sendDebug(String cmd)
{

    Serial.println(cmd);
} 
