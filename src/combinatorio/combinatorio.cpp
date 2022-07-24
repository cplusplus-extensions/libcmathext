#include "combinatorio.h"
#include <cmath>
#include <algorithm>

#if __cplusplus >= 201103L
#include <numeric>
#endif

#if __cplusplus >= 201703L
/**
 * @brief Questa funzione permette di calcolare il numero di permutazioni con ripetizione di una sequenza di elementi (anche ripetuti).
 * 
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * @param n La lunghezza della sequenza di elementi di cui calcolare il numero di permutazioni.
 * @param v Un vettore contenente le specifiche delle ripetizioni degli elementi.
 * @return unsigned long long int Il numero di permutazioni con ripetizione della sequenza di elementi. Questa funzione ritorna -1 in caso di overflow aritmetico o nel caso in cui la somma degli elementi del secondo argomento sia diversa dal primo elemento.
 */
unsigned long long int permWithRepetition(unsigned long long int n, const std::vector<unsigned long long int>& v) {
    unsigned long long int acc = std::accumulate(v.begin(), v.end(), 0);
    if(acc != n) {
        throw std::invalid_argument("The sum of the elements of the second argument must be equal to the first argument.");
        return -1;
    }
    
    unsigned long long int res = 1;
    try {
        std::for_each(v.begin(), v.end(), [&res](unsigned long long int i) {
            res *= factorial(i);
        });
    } catch(std::overflow_error& e) {
        throw std::overflow_error("The result of the calculation is too big.");
        return -1;
    }
    return factorial(n)/res;
}

#else
#if __cplusplus >= 201103L //<numeric> was introduced in C++11, so we check the C++ version.
/**
 * @brief Questa funzione permette di calcolare il numero di permutazioni con ripetizione di una sequenza di elementi (anche ripetuti).
 * 
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * @param n La lunghezza della sequenza di elementi di cui calcolare il numero di permutazioni.
 * @param v Un vettore contenente le specifiche delle ripetizioni degli elementi.
 * @return unsigned long long int Il numero di permutazioni con ripetizione della sequenza di elementi. Questa funzione ritorna -1 in caso di overflow aritmetico o nel caso in cui la somma degli elementi del secondo argomento sia diversa dal primo elemento.
 */
unsigned long long int permWithRepetition(unsigned long long int n, const std::vector<unsigned long long int>& v) {
    unsigned long long int acc = std::accumulate(v.begin(), v.end(), 0);
    if(acc != n) {
        throw std::invalid_argument("The sum of the elements of the second argument must be equal to the first argument.");
        return -1;
    }
    
    unsigned long long int res = 1;
    try {
        for(unsigned long long int i: v) {
            res *= factorial(i);
        }
    } catch(std::overflow_error& e) {
        throw std::overflow_error("The result of the calculation is too big.");
        return -1;
    }
    return factorial(n)/res;
}
#endif

#endif

/**
 * @brief Questa funzione permette di calcolare il coefficiente binomiale di due valori forniti in input. Questa funzione ritorna -1 in caso di overflow aritmetico o nel caso in cui il primo valore in input sia inferiore al secondo.
 * 
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * @exception std::invalid_argument Eccezione lanciata quando il primo valore in input è inferiore al secondo.
 * @param n Il primo indice del coefficiente binomiale.
 * @param k Il secondo indice del coefficiente binomiale.
 * @return unsigned long long int Il risultato del calcolo del coefficiente binomiale.
 */
unsigned long long int binomial(unsigned long long int n, unsigned long long int k) {
    if(n < k) {
        throw std::invalid_argument("The first input value cannot be smaller than the second one.");
        return -1;
    }
    unsigned long long int res = 0;
    try {
        res = factorial(n)/(factorial(k)*factorial(n - k));
    } catch(std::overflow_error& e) {
        throw std::overflow_error("The result of the calculation is too big.");
        return -1;
    }
    return res;
}

/**
 * @brief Questa funzione permette di computare il risultato del binomio di Newton. Questa funzione ritorna -1 in caso di overflow aritmetico.
 * 
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * @param a Il primo valore del binomio di Newton.
 * @param b Il secondo valore del binomio di Newton.
 * @param exp L'esponente del binomio di Newton.
 * @return unsigned long long int Il valore calcolato tramite la formula del binomio di Newton.
 */
unsigned long long int newton(unsigned long long int a, unsigned long long int b, unsigned long long int exp) {
    unsigned long long int res = 0;
    try {
        for(int i = 0; i < exp; i++) {
            res += binomial(exp, i)*std::pow(a, exp - i)*std::pow(b, i);
        }
    } catch(std::overflow_error& e) {
        throw std::overflow_error("The result of the calculation is too big.");
    }
    return res;
}