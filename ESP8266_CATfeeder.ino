//-----------------------------------------------------------------------------//
//                         Wifi- operated cat feeder                           //
//                            by Jannis Ret                                    //
//                         Version 1.2 -  22.05.2018                           //
//           for use with Hardware: 3D Printed cat feeder by odwdinc,          //
//          ESP8266, 28BYJ-48 Stepper Motor and ULN2003 Stepper Driver         //
//-----------------------------------------------------------------------------//

// Download the Cat feeder STL-files here: https://www.thingiverse.com/thing:688807/
// Big thanks to odwdinc for sharing this awesome 3D Print!


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
 #include <Stepper2.h>

const char* ssid = "WIFINAME";                   // <------- INSERT YIUR WIFI NAME
const char* password = "PASSWORD";               // <------- INSERT YOUR WIFI PASSWORD

//integers for stepper
const int rpm = 15; // max rpm on 28BYJ-48 is ~15
int pinOut[4] = { D5, D6, D7, D8 };
//define stepper
 Stepper2 myStepper(pinOut);

ESP8266WebServer server(80);

const int led = 13;


void handleRoot() {
String messageroot = "<html><head></head><body style='font-family: sans-serif; font-size: 70px'><b>Welcome to the WIFI-operated cat feeder!</b><br><br>";
  messageroot += "<html><head></head><body style='font-family: sans-serif; font-size: 70px'>Following functions are available:<br><br>";
  messageroot += "<a href='/feed'><b>/feed</b></a> feeds the cat.<br><br>";
  messageroot += "<a href='/unfeed'><b>/unfeed</b></a> turns anticlockwise.<br><br>";
  messageroot += "<a href='/shake'><b>/shake</b></a> shakes the rotor.<br><br>";
  messageroot += "<a href='/+1'><b>/+1</b></a> give him a treat.<br><br>";
  

  server.send(200, "text/html", messageroot);
}

void feed(int dir, int turn, int stepct){ //-------------------------FEED
            myStepper.setDirection(dir);
            myStepper.turn(turn);
            myStepper.step(stepct);
            myStepper.stop();
            
            
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void){
  pinMode(led, OUTPUT);

  //name stepper
  myStepper.setSpeed(rpm);
  
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("connecting to: ");
  Serial.println(ssid);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //--------------------------------------Indicate connection to wifi by blinking the LED blue two times      
          
          digitalWrite(led, 1);
          delay(500);
          digitalWrite(led, 0);
          delay(500);
          digitalWrite(led, 1);
          delay(500);
          digitalWrite(led, 0); 
//-----------------------------------------
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("catfeeder")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/blink", [](){
    server.send(200, "text/plain", "led is blinking");
      digitalWrite(led, 1);
      delay(500);
      digitalWrite(led, 0);
      delay(500);
      digitalWrite(led, 1);
      delay(500);
      digitalWrite(led, 0); 
  });

    server.on("/feed", [](){
          //Perform some shake action
          feed(0,0,300); 
          feed(1,0,300);
          feed(0,0,300);
          feed(1,0,300);          
          feed(0,0,300);
          feed(1,0,300);
          //feed 3 times for a full bowl  
          feed(0,1,1); 
          feed(0,1,1); 
          feed(0,1,1); 
          //Perform some shake action
          feed(0,0,300); 
          feed(1,0,300);
          feed(0,0,300);
          feed(1,0,300);          
          feed(0,0,300);
          feed(1,0,300);
      String messagefeed = "<html><head></head><body style='font-family: sans-serif; font-size: 70px'><b>Yo! The Cat has been feeded!</b><br><br>";
             messagefeed += "<html><head></head><body style='font-family: sans-serif; font-size: 70px'>Following functions are available:<br><br>";
             messagefeed += "<a href='/feed'><b>/feed</b></a> feeds the cat another time.<br><br>";
             messagefeed += "<a href='/feed'><b>/shake</b></a> Shake the rotor.<br><br>";
             messagefeed += "go <a href='http://IPaddressofESP8266'><b>BACK</b></a></body></html>";
    server.send(200, "text/html", messagefeed); 
  });

      server.on("/unfeed", [](){
          feed(1,1,1); 
      String messagefeed = "<html><head></head><body style='font-family: sans-serif; font-size: 70px'><b>Yo! Harald has been feeded!</b><br><br>";
             messagefeed += "<html><head></head><body style='font-family: sans-serif; font-size: 70px'>Following functions are available:<br><br>";
             messagefeed += "<a href='/unfeed'><b>/unfeed</b></a> unfeeds the cat another time.<br><br>";
             messagefeed += "go <a href='http://IPaddressofESP8266'><b>BACK</b></a></body></html>";
    server.send(200, "text/html", messagefeed); 
  });

    server.on("/shake", [](){
          feed(0,0,300); 
          feed(1,0,300);
          feed(0,0,300);
          feed(1,0,300);          
          feed(0,0,300);
          feed(1,0,300);
      String messagefeed = "<html><head></head><body style='font-family: sans-serif; font-size: 70px'><b>Yo! Harald has been feeded!</b><br><br>";
             messagefeed += "<html><head></head><body style='font-family: sans-serif; font-size: 70px'>Following functions are available:<br><br>";
             messagefeed += "<a href='/feed'><b>/feed</b></a> feeds the cat.<br><br>";
             messagefeed += "go <a href='http://IPaddressofESP8266'><b>BACK</b></a></body></html>";
    server.send(200, "text/html", messagefeed); 
  });

      server.on("/+1", [](){
          feed(0,0,500); 
      String messagefeed = "<html><head></head><body style='font-family: sans-serif; font-size: 70px'><b>Yo! Harald got a treat!</b><br><br>";
             messagefeed += "<html><head></head><body style='font-family: sans-serif; font-size: 70px'>Following functions are available:<br><br>";
             messagefeed += "<a href='/+1'><b>/+1</b></a> give another one.<br><br>";
             messagefeed += "<a href='/feed'><b>/feed</b></a> give him a full bowl.<br><br>";
             messagefeed += "go <a href='http://IPaddressofESP8266'><b>BACK</b></a></body></html>";
    server.send(200, "text/html", messagefeed); 
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();

  
}
