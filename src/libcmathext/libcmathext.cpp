#ifdef __GNUC__
#if __GNUC__ < 13
#define _USE_MATH_DEFINES
#endif
#endif

#include "libcmathext.h"

/**
 * @brief Questa libreria è intesa come raccolta di funzioni e trucchi matematici per risolvere problemi (o parti di problemi) che, normalmente,
 * risulterebbero computazionalmente complessi.
 * @remark Per alcune funzioni, è presente anche una variante "non sicura", cioè che non compie controlli su condizioni di overflow.
 * Queste sono state incluse perché possono risultare utili nel campo della programmazione competitiva (es.: ICPC, Google HashCode, etc.).
 */

/**
 * @brief 
 * 
 * @param target 
 * @return unsigned long long int 
 */
unsigned long long int longestCollatz(unsigned long long int target) {
    unsigned long long int num = target/2, value;
    auto* paio = new std::pair<unsigned long long int, unsigned long long int>();

    paio->first = 0;
    paio->second = 0;

    while(num < target) {
        value = countChain(num);
        if(value > paio->second) {
            paio->first = num;
            paio->second = value;
        }
        num++;
    }

    unsigned long long int res = paio->first;

    delete paio;

    return res;
}

/**
 * @brief 
 * 
 * @param value 
 * @return unsigned long long int 
 */
unsigned long long int countChain(unsigned long long int value) {
    if(value != 1) {
        if(value%2 == 0) {
            value = 1 + countChain(value/2);
        } else {
            value = 2 + countChain((3*value + 1)/2);
        }
    }
    
    return value;
}

/**
 * @brief Questa funzione permette di calcolare il fattoriale di un numero intero positivo o nullo.
 * 
 * @exception std::invalid_argument Eccezione lanciata quando il almeno uno dei valori forniti in input è negativo.
 * @param value Il valore di cui calcolare il fattoriale.
 * @return unsigned long long int Il risultato del calcolo del fattoriale
 * @throws std::invalid_argument Se il valore in input è troppo grande per poter ritornare il risultato
 * corretto
 */
unsigned long long int factorial(unsigned long long int value) {
    unsigned long long int res = 1LL;
    if (value != 0 && value != 1) {
        for (unsigned long long int i = 1LL; i <= value; i++) {
            if(res*i > ULONG_LONG_MAX) {
                throw std::invalid_argument("value is too big.");
            }
            res *= i;
        }
    }
    return res;
}