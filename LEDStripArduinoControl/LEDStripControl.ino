// Initialize the LED Strip
bool InitLEDStrip()
{
  // Define the LED Chips
  FastLED.addLeds<WS2812B, LEDStripData, GRB>(LEDData, 0, LEDChipPerMeter * LEDStripMeter);
}

#pragma region LED Color Show

#pragma region LED PingPong
// Switch of
void PingPongSingleLED(CRGB::HTMLColorCode InputColor)
{
  // Forward
  for (int i = 0; i < sizeof(LEDData); i++)
  {
    if (i == 0)
    {
      // Switch On the First LED
      LEDData[i] = InputColor;

      // Switch Off the Last LED
      LEDData[sizeof(LEDData) - 1] = InputColor;
    }
    else 
    {
      // Switch On the Current LED
      LEDData[i] = InputColor;

      // Switch Off the Last LED
      LEDData[i - 1] = InputColor;
    }

    // Delay for Visualisation
    delay(100);
  }

  // Backward
  for (int i = sizeof(LEDData) - 1; i >= 0; i--)
  {
    if (i == 0)
    {
      // Switch On the First LED
      LEDData[i] = InputColor;

      // Switch Off the Last LED
      LEDData[sizeof(LEDData) - 1] = InputColor;
    }
    else 
    {
      // Switch On the Current LED
      LEDData[i] = InputColor;

      // Switch Off the Last LED
      LEDData[i - 1] = InputColor;
    }

    // Delay for Visualisation
    delay(100);
  }
}
#pragma endregion

#pragma endregion