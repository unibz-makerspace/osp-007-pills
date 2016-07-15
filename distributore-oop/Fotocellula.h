/*** Classe Fotocellula ***/

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
    Fotocellula(const unsigned short int fotocellulaPin, const unsigned short int percentualeSoglia, const unsigned int intervalloCampionamento, const unsigned int numeroCampionamenti);
    unsigned short int inizializzaCalibrazione();
    unsigned short int calibra();   
    boolean aggiorna();		// aggiorna la posizione del segnalatore al passare del tempo
};

