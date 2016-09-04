/* 
  Motore.h - Classe Motore: controllo del servomotore.
  Creato da Robero De Munari 15/07/2016.
  Released into the public domain.
*/

#ifndef MOTORE_H
#define MOTORE_H

#include <Arduino.h>
#include <Servo.h>
#include <math.h>

class Motore: public Servo
{
  private:
    // parametri
    unsigned long p_intervalloDistribuzione;	// intervallo di spostamento per la distribuzione
    unsigned long p_intervalloCaricamento;	// intervallo di spostamento per il caricamento
    float p_ampiezzaSettoreRotazione;		// ampiezza del settore di rotazione

    // variabili di stato
    float s_posizione;	// positione attuale del servo
    unsigned long s_istantePrecedente;	// ultimo aggiornamento della posizone

  public: 
    Motore(const float ampiezzaSettoreRotazione, const unsigned long intervalloDistribuzione, const unsigned long intervalloCaricamento);	// costruttore
    void posiziona(float posizione);	// posiziona - inizialmente - il motore
    void aggiorna();	// aggiorna la posizione del motore al passare del tempo
};

#endif
