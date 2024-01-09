#ifdef __GNUC__
#if __GNUC__ < 13
#define _USE_MATH_DEFINES
#endif
#endif

#include "fibonacci.h"
#include <cmath>
#include <stdexcept>

/**
 * @brief Questa funzione calcola la somma di tutti i numeri pari di Fibonacci che non superino il valore dato in input.
 * @warning Questa funzione lancia un'eccezione nel caso in cui si verifichi un overflow aritmetico.
 * @exception std::overflow_error Eccezione lanciata quando si verifica un overflow aritmetico.
 * @exception std::invalid_argument Eccezione lanciata quando il valore fornito in input è negativo o nullo.
 * 
 * @param target 
 * @return int 
 */
int Fibonacci::sumEvenFib(int target) {
    int sum = 1;
    if(target <= 0) {
        throw std::invalid_argument("Target value less than or equal to zero is not allowed.");
    } else {
        int nuovo = 1, old;
        while(sum+nuovo<=target){
            old=nuovo;
            nuovo=sum;
            sum=nuovo+old;
        }
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
 * @return double L'i-esimo numero della serie di Fibonacci
 */
double Fibonacci::binet() {
    if(index > 0) {
        const double phi = (1 + sqrt(5))/2.0;
        return (pow(phi, index) - pow(1 - phi, index))/sqrt(5);
    } else {
        throw std::invalid_argument("Input value cannot be negative or zero.");
    }
}