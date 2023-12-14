// Check for Physical Hardware on the Arduino
bool CheckHardware()
{
  // No Hardware Connected, stay in the Loop
  bool InitShield = true;
  while (Ethernet.hardwareStatus() == EthernetNoHardware) 
  {
    if (InitShield) 
    {
      Serial.println("No EthernetShield Found");
      InitShield = false;
    }

    // Prevent High CPU Usage
    delay(100);
  }

  if (!InitShield) 
  {
    Serial.println("EthernetShield Found");
  }

  // Check if the Ethernet Cable is Connected
  bool InitCable = true;
  while (Ethernet.linkStatus() == LinkOFF) 
  {
    if (InitCable) 
    {
      Serial.println("Ethernet Cable not connected.");
      InitCable = false;
    }

    // Prevent High CPU Usage
    delay(100);
  }

  if (!InitCable) 
  {
    Serial.println("Ethernet Cable Connected");
  }

  // Return Value
  if (InitShield && InitCable) 
  {
    return true;
  } 
  else 
  {
    return false;
  }
}


bool InitSerial()
{
  // Open the Serial Port
  Serial.begin(9600);

  // Wait for the Serial Port to Open
  while (!Serial)
  {
    // Prevent High CPU Usage
    delay(100);
  }
}

/*
// Set Up the TCP Connection
void TCPSocketInit() 
{
  //Ethernet.init(10);
  Ethernet.begin(ArduinoMacAddress, ArduinoIPAddress);  //, ArduinoDNS, ArduinoGateway, ArduinoSubnet);

  // Initialize the Serial Port
  Serial.begin(9600);

  while (!Serial) 
  {
    // Wait for the Serial Port to Open
    delay(10);
  }

  if (CheckHardWare()) 
  {
    // Start Listening for Clients
    Serial.print("\nSocket Address: ");
    Serial.println(Ethernet.localIP());
    SocketServer.begin();
  }
}
*/