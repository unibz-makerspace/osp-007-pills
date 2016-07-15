#include "Segnalatore.h"

Segnalatore::Segnalatore(const unsigned long durataSegnaleOn, const unsigned long durataSegnaleOff)
{
  for (int i = 0; i < NUMERO_LED; i++)
  {
    p_ledPins[i] = ledPins[i];
    pinMode(p_ledPins[i], OUTPUT);
  }

  p_durataSegnaleOn = durataSegnaleOn;
  p_durataSegnaleOff = durataSegnaleOff;

  s_statoLed = LOW; 
  s_istantePrecedente = 0;
  s_statoSegnalatore = true;
}

void Segnalatore::aggiorna()
{
  unsigned long istanteAttuale;
  
  // verifica se sia giunto il momento di aggiornare lo stato LED
  if(s_statoSegnalatore)
  {
    istanteAttuale = millis();

    if((s_statoLed == HIGH) && (istanteAttuale - s_istantePrecedente >= p_durataSegnaleOn))
    {
      s_statoLed = LOW;  				// modifica dello stato dei segnale
      s_istantePrecedente = istanteAttuale;		// aggiornamento di statoPrecedente
      
      for (int i = 0; i < NUMERO_LED; i++)		// accensione o spegnimento del LED
          digitalWrite(p_ledPins[i], s_statoLed);
    }
    else if ((s_statoLed == LOW) && (istanteAttuale - s_istantePrecedente >= p_durataSegnaleOff))
    {
      s_statoLed = HIGH;  						// modifica dello stato dei segnale
      s_istantePrecedente = istanteAttuale;		// aggiornamento di statoPrecedente
      for (int i = 0; i < NUMERO_LED; i++)		// accensione o spegnimento del LED
          digitalWrite(p_ledPins[i], s_statoLed);
    }
  }
  else
    for (int i = 0; i < NUMERO_LED; i++)		// accensione o spegnimento del LED
      digitalWrite(p_ledPins[i], LOW);
};

void Segnalatore::attiva()
{	
  s_statoSegnalatore = true;
}

void Segnalatore::disattiva()
{	
  s_statoSegnalatore = false;
}
