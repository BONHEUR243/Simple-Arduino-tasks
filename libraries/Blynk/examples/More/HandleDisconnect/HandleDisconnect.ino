/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how to keep WiFi connection on ESP8266.

 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"
//#define BLYNK_AUTH_TOKEN            "YourAuthToken"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";


int lastConnectionAttempt = millis();
int connectionDelay = 5000; // try to reconnect every 5 seconds

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  // check WiFi connection:
  if (WiFi.status() != WL_CONNECTED)
  {
    // (optional) "offline" part of code

    // check delay:
    if (millis() - lastConnectionAttempt >= connectionDelay)
    {
      lastConnectionAttempt = millis();

      // attempt to connect to Wifi network:
      if (pass && strlen(pass))
      {
        WiFi.begin((char*)ssid, (char*)pass);
      }
      else
      {
        WiFi.begin((char*)ssid);
      }
    }
  }
  else
  {
    Blynk.run();
  }
}
