/*** Classe Segnalatore ***/

#include <Arduino.h>

// enumerazione relativa ai pin del distributore
enum enum_ledPins{
	ledPin0 = 2, ledPin1 = 4, ledPin2 = 7, ledPin3 = 13
};

static const unsigned short int NUMERO_LED = 4;

static const enum_ledPins ledPins[] = { ledPin0, ledPin1, ledPin2, ledPin3 };

class Segnalatore
{
  private:
    // parametri inizializzati all'avvio
    unsigned short int p_ledPins[NUMERO_LED];   // numero del pin dei 4 LED
    unsigned long p_durataSegnaleOn;    	// millisecondi di durata del segnale attivo
    unsigned long p_durataSegnaleOff;   	// milliseconds di durata del segnale non attivo

    // variabili di stato
    unsigned short int s_statoLed;             	// stato del LED
    unsigned long s_istantePrecedente;  	// istante del precedente aggiornamento
    boolean s_statoSegnalatore;

  public:
    Segnalatore(const unsigned long durataSegnaleOn, const unsigned long durataSegnaleOff); // costruttore
    void attiva();
    void disattiva();
    void aggiorna();				// aggiorna la posizione del segnalatore al passare del tempo
};
