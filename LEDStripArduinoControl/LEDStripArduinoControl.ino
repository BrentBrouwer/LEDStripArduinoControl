#include <FastLED.h>
#include <Ethernet.h>
#include <SPI.h>
#include <string.h>

// Pin Definitions
#define SDCard 4              // Pin 4 can not be used as IO because it is used for the SD card on the Ethernet Shield
#define LEDStripData 5

// LED Strip Properties
#define LEDChipPerMeter 30
#define LEDStripMeter 2
CRGB LEDData[LEDChipPerMeter * LEDStripMeter];

// TCP/IP Properties
byte ArduinoMacAddress[] = { 0xA8, 0x61, 0x0A, 0xAE, 0xDF, 0x25 };
IPAddress ArduinoIPAddress(192, 168, 51, 10);
IPAddress ArduinoSubnet(255, 255, 0, 0);
IPAddress ArduinoDNS(192, 168, 1, 1);
IPAddress ArduinoGateway(192, 168, 1, 1);
const int ArduinoPortNr = 14302;

void setup() 
{
  if (InitSerial() && CheckHardware())
  {
    Serial.println("Enter Loop");
  }
}

void loop() 
{
  PingPongSingleLED(CRGB::Red);

  // Prevent High CPU-Usage
  delay(5);
}
