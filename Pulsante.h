/*** Classe Pulsante ***/

#include <Arduino.h>

class Pulsante
{
  private:
    // parametri inizializzati all'avvio
    unsigned short int p_pulsantePin; 		// numero del pin
    unsigned long p_debounceRitardo;            // ritardo di debouncing

    // variabili di stato
    boolean s_statoPulsante;		        // stato del pulsante
    boolean s_ultimoStatoPulsante;             	// stato precedente del pulsante
    unsigned long s_istanteDebouncePrecedente;  // istante del precedente aggiornamento
    
  public:
    Pulsante(const unsigned short int pulsantePin, const unsigned short int debounceRitardo);
    boolean aggiorna();				// aggiorna la posizione del segnalatore al passare del tempo
};
