/* 
  Pulsante.cpp - Implementazione della classe Pulsante.
  Creato da Robero De Munari 15/07/2016.
  Released into the public domain.
*/

#include "Pulsante.h"

Pulsante::Pulsante(const unsigned short int pulsantePin, const unsigned short int debounceRitardo)
{
  p_pulsantePin = pulsantePin;
  p_debounceRitardo = debounceRitardo;
  pinMode(p_pulsantePin, INPUT);
  
  s_istanteDebouncePrecedente = 0;
  s_ultimoStatoPulsante = LOW;
}

boolean Pulsante::aggiorna()
{
  // acquisisce in segnale
  boolean segnale = digitalRead(p_pulsantePin);
  
  // verifica se il segnale è cambiato
  if (segnale != s_ultimoStatoPulsante) 
  {
    // reset il timer del debouncing
    s_istanteDebouncePrecedente = millis();
  }

  // qualsiasi sia il segnale letto, se è rimasto lo stesso per una durata
  // maggiore del ritardo, allora allo starto è assegnato il valore del segnale
  if ((millis() - s_istanteDebouncePrecedente) > p_debounceRitardo)
  {
    // se lo stato è cambiato, lo aggiorna
    if (segnale != s_statoPulsante)
      s_statoPulsante = segnale;
  }
  
  // salva l'ultimo segnale acquisito per confrontarlo con quello che sarà acquisito al prossimo ciclo
  s_ultimoStatoPulsante = segnale;

  return s_statoPulsante; 
}
