/* 
  Fotocellula.cpp - Libreria rilevare la luminosità.
	Classe Fotocellula
*/

#include "Arduino.h"
#include "Fotocellula.h"

Fotocellula::Fotocellula(const unsigned short int  fotocellulaPin, const unsigned short int percentualeSoglia, const unsigned int intervalloCampionamento, const unsigned int numeroCampionamenti)
{ 
  p_fotocellulaPin = fotocellulaPin;
  pinMode(p_fotocellulaPin, INPUT);
  p_percentualeSoglia = percentualeSoglia;
  p_intervalloCampionamento = intervalloCampionamento;
  p_numeroCampionamenti = numeroCampionamenti;
}

unsigned short int Fotocellula::calibra()
{ 
  static unsigned long istantePrecedente = 0;
  unsigned short int valoreSensore;
  unsigned int somma = 0;
  static unsigned short int valoreMedioSensore = map(analogRead(p_fotocellulaPin), 0, 1023, 0, 255);
  
	// il vettore delle intensità luminose è aggiornato periodicamente
  if ((millis() - istantePrecedente) > p_intervalloCampionamento)
  {
    istantePrecedente = millis();

    valoreSensore = map(analogRead(p_fotocellulaPin), 0, 1023, 0, 255);

    somma = valoreSensore;    
    for(int i = p_numeroCampionamenti - 1; i > 0; i--)
    {
      s_valoriSensore[i] = s_valoriSensore[i - 1]; 
      somma += s_valoriSensore[i]; 
    }

    s_valoriSensore[0] = valoreSensore;

    valoreMedioSensore = somma / p_numeroCampionamenti;

    s_soglia = valoreMedioSensore * p_percentualeSoglia / 100;
    Serial.print("Soglia: ");Serial.println(s_soglia);
  }  
	
  return valoreMedioSensore * p_percentualeSoglia / 100;
}

unsigned short int Fotocellula::inizializzaCalibrazione()
{
  unsigned int somma = 0;
	// durante il setup il vettore è caricato con i valori delle intensità luminose
  for(int i = 0; i < p_numeroCampionamenti; i++)
  {
    s_valoriSensore[i] = map(analogRead(p_fotocellulaPin), 0, 1023, 0, 255);
    somma += s_valoriSensore[i]; 
  }	

  s_soglia = (somma / p_numeroCampionamenti) * p_percentualeSoglia / 100;	

  return somma / p_numeroCampionamenti;	
}

boolean Fotocellula::aggiorna()
{
  int valoreSensore = analogRead(p_fotocellulaPin);
  valoreSensore = map(valoreSensore, 0, 1023, 0, 255);
//  valoreSensore = constrain(valoreSensore, 0, 255);
  
  boolean segnale = false;

	// se il valore della luminosità rilevata è minore della soglia, ciò è segnalato  
  if (valoreSensore < s_soglia)
    segnale = true;
  
  Serial.print(valoreSensore); Serial.print("-"); Serial.println(segnale);

  return segnale;
}

