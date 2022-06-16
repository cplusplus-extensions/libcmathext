#define _USE_MATH_DEFINES

#include "fibonacci.h"
#include <cmath>
#include <stdexcept>

/**
 * @brief Questa funzione calcola la somma di tutti i numeri pari di Fibonacci che non superino il valore dato in input.
 * @warning Questa funzione lancia un'eccezione nel caso in cui si verifichi un overflow aritmetico.
 * @exception std::overflow_error Eccezione lanciata quando si verifica un overflow aritmetico.
 * 
 * @param target 
 * @return int 
 */
int Fibonacci::sumEvenFib(int target) {
    unsigned int sum = 0, temp, nuovo = 1, old = 1;
    
    try {
        temp = nuovo + old;
        while(nuovo <= target) {
            sum += temp;
            nuovo = old + temp;
            old = temp + nuovo;
            temp = nuovo + old;
        }
    } catch(std::overflow_error& e) {
        throw new std::overflow_error("Arithmetic overflow occurred.");
    }
    

    return sum;
}

/**
 * @brief Questa funzione calcola l'index-esimo valore della successione di Fibonacci
 * (se il valore fornito in input è strettamente positivo), altrimenti ritorna 0.
 * @warning Questa funzione lancia un'eccezione nel caso in cui si verifichi un overflow aritmetico o il
 * valore fornito in input è negativo o nullo.
 * @exception std::overflow_error Eccezione lanciata quando si verifica un overflow aritmetico.
 * @exception std::invalid_argument Eccezione lanciata quando il valore fornito in input è negativo o nullo.
 * @remark Questa funzione è particolarmente consigliata nel caso della programmazione dinamica.
 * 
 * @param index
 * @return int 
 */
int Fibonacci::binet(int index) {
    if(index > 0) {
        try {
            const double phi = (1 + sqrt(5))/2.0;
            return (pow(phi, index) - pow(1 - phi, index))/sqrt(5);
        } catch(std::overflow_error& e) {
            throw new std::overflow_error("Arithmetic overflow occurred.");
        }
    } else {
        throw new std::invalid_argument("Input value cannot be negative or zero.");
    }
}