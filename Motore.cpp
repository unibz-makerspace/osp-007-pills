#include "Motore.h"

Motore::Motore(const float ampiezzaSettoreRotazione, const unsigned long intervalloDistribuzione, const unsigned long intervalloCaricamento)
{
  p_ampiezzaSettoreRotazione = ampiezzaSettoreRotazione;
  p_intervalloDistribuzione = intervalloDistribuzione;
  p_intervalloCaricamento = intervalloCaricamento;
}

void Motore::posiziona(float posizione)
{
    s_posizione = posizione;
    write(round(s_posizione));			// posiziona il motore
    s_istantePrecedente = millis();		// memorizza la posizine del motore
}

void Motore::aggiorna()
{
  if((millis() - s_istantePrecedente) > p_intervalloDistribuzione) // se è trascorso il tempo previsto dall'istante dell'ultimo 		posizionamento, allora modifica la posizione
  {
    if (s_posizione > 179.0) 
        s_posizione = 0.0; 	// riposizionamento all'inizio al termine di un ciclo di rotazione di 180 gradi
    else
    	s_posizione = s_posizione + p_ampiezzaSettoreRotazione; // riposizionamento
    
    write(round(s_posizione));

    s_istantePrecedente = millis();															
  }
}
