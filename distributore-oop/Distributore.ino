/* 
  Sketch Arduino per il controllo del distributore.
  Creato da Robero De Munari 15/07/2016.
  Released into the public domain.
*/

#include <Servo.h>
#include "Costanti.h"
#include "Motore.h"
#include "Fotocellula.h"
#include "Pulsante.h"
#include "Segnalatore.h"
#include "RicevitoreTrasmettitoreSeriale.h"

struct struct_data
{
  unsigned long gg;
  unsigned short int hh;
  unsigned short int mm;
  unsigned short int ss;
};

// enumerazione relativa ai possibili stati del distributore
enum emun_stati{
  disattivo, attivo, attivoSegnalante
};

/*** Variabili globali ***/

Motore motore(ANGOLO_ROTAZIONE, DURATA_DISTRIBUZIONE, DURATA_CARICAMENTO);
Segnalatore segnalatore(PERIODO_ACCENSIONE, PERIODO_SPEGNIMENTO);
Pulsante pulsante(12, DURATA_DEBOUNCE);
Fotocellula fotocellula(A0, PERCENTUALE_SOGLIA, PERCENTUALE_SOGLIA, NUMERO_CAMPIONAMENTI);
RicevitoreTrasmettitoreSeriale ricevitoreTrasmettitoreSeriale(&Serial);   

emun_stati stato; 	//0: motore attivo e segnalazione attiva; 1: motore attivo e segnalzione disattivata 
			//2: motore disattivo e segnalotore disattivati

emun_stati statoPrecedente;

void setup() 
{ 
  Serial.begin(9600);
  
  fotocellula.inizializzaCalibrazione();
  
  motore.attach(9);
  motore.posiziona(0.0);
  
  stato = attivo;
  statoPrecedente = disattivo;
} 
 
void loop() 
{
  // acquisizione ingressi
  boolean u_pulsante = pulsante.aggiorna();
  boolean u_fotocellula = fotocellula.aggiorna();
  
  enum_messaggi messaggio = ricevitoreTrasmettitoreSeriale.riceve();
  
  Serial.println(stato);
 

  // funzione di transizione del distributore
  switch(stato) 
  {
    case attivoSegnalante:
  	if (u_pulsante)
          stato = disattivo;
    	break;
    case attivo:
    	if (u_fotocellula)
          stato = attivoSegnalante;
  	if (u_pulsante)
          stato = disattivo;
    	break;
    case disattivo:
      	if (messaggio == attiva)
      	  stato = attivo;
      	break;
  }
 
  // funzione di trasformazione del distributore
  if (stato != statoPrecedente)
    switch(stato) 
    {
      case attivoSegnalante:
      {
          segnalatore.attiva();          
          motore.attach(9);
          break;
      }
      case attivo:
      {
          segnalatore.disattiva();
          motore.attach(9);
          break;
      }
      case disattivo:
      {
          segnalatore.disattiva();
          motore.detach();
          break;
      }
    }
  
  statoPrecedente = stato;
  
  // funzione di trasformazione
  fotocellula.calibra();
  motore.aggiorna();
  segnalatore.aggiorna();
  
  delay(10);
}
