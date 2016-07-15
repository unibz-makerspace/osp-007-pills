/*** Classe astratta RicevitoreTrasmettitore ***/

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
