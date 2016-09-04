/* 
  Fotocellula.h - Classe Fotocellula: rilevamento dell'intensità luminosa.
  Creato da Robero De Munari 15/07/2016.
  Released into the public domain.
*/

#ifndef FOTOCELLULA_H
#define FOTOCELLULA_H

#include <Arduino.h>

static const unsigned int NUMERO_CAMPIONAMENTI_MAX = 20;

class Fotocellula
{
  private:
    // parametri inizializzati all'avvio
    unsigned short int p_fotocellulaPin;
    unsigned short int p_percentualeSoglia;
    unsigned int p_intervalloCampionamento;
    unsigned int p_numeroCampionamenti;

    // variabili di stato
    unsigned short int s_valoriSensore[100];
    unsigned short int s_soglia;
     
  public:
    Fotocellula(const unsigned short int fotocellulaPin, const unsigned short int percentualeSoglia, const unsigned int intervalloCampionamento, const unsigned int numeroCampionamenti); // costruttore
    unsigned short int inizializzaCalibrazione(); // determina l'intensità luninosa iniziale 
    unsigned short int calibra(); // calibra progressivamente la soglia di attivazione, adeguandola al mutare delle condizioni
    boolean aggiorna();	// aggiorna la posizione del segnalatore al passare del tempo
};

#endif

