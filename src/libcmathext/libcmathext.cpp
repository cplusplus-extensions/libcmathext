#define _USE_MATH_DEFINES

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
    std::pair<unsigned long long int, unsigned long long int>* paio = new std::pair<unsigned long long int, unsigned long long int>();

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
    
    return paio->first;
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