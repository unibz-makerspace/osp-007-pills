/*** Classe RicevitoreTrasmettitoreSeriale ***/

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
