/* 
  RicevitoreTrasmettitoreSeriale.h - Classe RicevitoreTrasmettitoreSeriale: implementazione della 
	classe RicevitoreTrasmettitore.
  Creato da Robero De Munari 15/07/2016.
  Released into the public domain.
*/

#ifndef RICEVITORE_TRASMETTITORE_SERIALE_H
#define RICEVITORE_TRASMETTITORE_SERIALE_H

#include <Arduino.h>

/*** Classe  ***/

#include "RicevitoreTrasmettiore.h"
#include <HardwareSerial.h>

class RicevitoreTrasmettitoreSeriale: public RicevitoreTrasmettitore
{
  private:
    HardwareSerial * _HardSerial; // member within class
  public:
    RicevitoreTrasmettitoreSeriale(HardwareSerial *serial); // ctor
    virtual enum_messaggi riceve() const;
    virtual void trasmette(enum_messaggi messaggio) const;
};

#endif
