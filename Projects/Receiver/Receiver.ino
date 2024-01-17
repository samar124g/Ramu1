
//tested for git
#include <SPI.h>              //Library for using SPI Communication 
#include <mcp2515.h>          //Library for using CAN Communication (https://github.com/autowp/arduino-mcp2515/)
struct can_frame canMsg; 
MCP2515 mcp2515(16); //for esp8266
void setup()
{
  Serial.begin(115200);                //Begins Serial Communication at 9600 baudrate
  SPI.begin();                       //Begins SPI communication
  delay(1000); 
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();                  //Sets CAN at normal mode
}
 
 
void loop()
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data (Poll Read)
  {
    int x = canMsg.data[0];
    int y = canMsg.data[1];
    Serial.print("Humi:");
    Serial.print("Temp:");
    Serial.print(y);
    delay(1000);
  }
}