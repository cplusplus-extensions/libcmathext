#include "gauss.h"
#include <stdexcept>

/**
 * @brief Questa funzione prende in input un valore intero positivo e restituisce la somma di tutti i valori interi positivi
 * compresi tra 1 e quel valore (incluso). Questa implementazione è più vantaggiosa rispetto al calcolo classico della somma di
 * questi valori positivi, in quanto non richiede che vengano eseguite più di tre operazioni.
 * @warning questa funzione può lanciare un'eccezione in caso di overflow aritmetico o qualora sia fornito in input un valore negativo.
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * @exception std::invalid_argument Eccezione lanciata quando il valore fornito in input è negativo.
 * 
 * @param value 
 * @return long long int 
 */
long long int Gauss::gaussSum(long long int value) {
    if(value >= 0) {
        try {
            return value*(value + 1)/2;
        } catch(std::overflow_error& e) {
            throw new std::overflow_error("Arithmetic overflow occurred.");
        }
    } else {
        throw new std::invalid_argument("Input value cannot be negative.");
    }
}