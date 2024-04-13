// blinks led when you write to serial 'on'
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

void setup()
{
  Serial.begin(115200);
  pinMode(A0, OUTPUT);
}
void loop()
{

  static char receivedString[64];
  static int stringIndex = 0;

  if (Serial.available() > 0)
  {                                    // Sprawdzenie, czy są dostępne nowe dane
    char receivedChar = Serial.read(); // Odczytanie jednego znaku z portu szeregowego

    if (receivedChar != '\n')
    {
      receivedString[stringIndex] = receivedChar;
      stringIndex++;
      if (stringIndex >= sizeof(receivedString))
      {
        stringIndex = sizeof(receivedString) - 1;
      }
    }
    else
    {
      receivedString[stringIndex] = '\0';
      if (strcmp(receivedString, "on") == 0)
      {
        digitalWrite(A0, HIGH);
      }
      else if (strcmp(receivedString, "off") == 0)
      {
        digitalWrite(A0, LOW);
      }
      else
      {
        Serial.println("Invalid");
      }
      stringIndex = 0;
    }
  }
  delayMicroseconds(500);
}