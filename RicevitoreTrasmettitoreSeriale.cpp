#include "RicevitoreTrasmettitoreSeriale.h"

RicevitoreTrasmettitoreSeriale::RicevitoreTrasmettitoreSeriale(HardwareSerial *serial){
   _HardSerial = serial;
}
 
enum_messaggi RicevitoreTrasmettitoreSeriale::riceve() const
{
  static boolean payload;
  enum_messaggi messaggio = continua;
  
  if(Serial.available())
  {
    char carattere = Serial.read();

    if(payload && isDigit(carattere))
    {
      unsigned short int codiceAscii = carattere - '0';

      switch(codiceAscii)
      {
        case 0:
        {
          messaggio = disattiva;
          break;
        }
        case 1:
        {
          messaggio = attiva;
          break;
        }
      }
    }

    if(carattere == 'H')
      payload = true;
    else
      payload = false;
  }
  
  return messaggio;
}

void RicevitoreTrasmettitoreSeriale::trasmette(enum_messaggi messaggio) const {}
