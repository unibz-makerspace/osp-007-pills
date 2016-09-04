/* 
  RicevitoreTrasmettitore.h - Classe astratta RicevitoreTrasmettitore: interfaccia per la comunicazione.
  Creato da Robero De Munari 15/07/2016.
  Released into the public domain.
*/

#ifndef RICEVITORE_TRASMETTITORE_H
#define RICEVITORE_TRASMETTITORE_H

#include <Arduino.h>

// enumerazione relativa ai possibili messaggi
enum enum_messaggi{
    continua, attiva, disattiva
};

class RicevitoreTrasmettitore
{
  public:
    virtual enum_messaggi riceve() const = 0; // pure virtual => abstract class
    virtual void trasmette(enum_messaggi messaggio) const=0; // pure virtual => abstract class
};

#endif

