#include "sum.h"
#include <algorithm>
#include <stdexcept>

Sum::Sum(int val, int val1 = 0, int val2 = 0) {
    valueA = val;
    valueB = val1;
    target = val2;
}

/**
 * @brief Questa funzione prende in input un valore intero positivo e restituisce la somma di tutti i valori interi
 * positivi dispari compresi tra 1 e quel valore (altrimenti, se il valore in input è nullo, restituisce zero).
 * @warning La funzione lancia un'eccezione se il valore in input è negativo o pari a zero, o se si verifica una
 * condizione di overflow aritmetico.
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * @exception std::invalid_argument Eccezione lanciata quando il valore fornito in input alla funzione è negativo o nullo.
 * 
 * @param value 
 * @return int 
 */
int Sum::oddIntSum(int value) {
    if(value >= 0) {
        try {
            return value*value;
        } catch(std::overflow_error& e) {
            throw new std::overflow_error("Arithmetic overflow occurred.");
        }
    } else {
        throw new std::invalid_argument("Input value cannot be negative or zero.");
    }
}

/**
 * @brief Questa funzione prende in input un valore intero positivo e ritorna la somma di tutti i valori interi positivi pari
 * compresi tra 1 e quel valore. ATTENZIONE: se il valore in input è negativo o pari a zero, la funzione ritorna 0. Tuttavia,
 * non compie alcun controllo sul verificarsi di una condizione di overflow. Si consiglia, pertanto, di utilizzare la funzione
 * evenIntSum_s().
 * @warning Questa funzione lancia un'eccezione quando si verifica una condizione di overflow aritmetico o quando il valore fornito
 * in input è negativo o pari a zero.
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * @exception std::invalid_argument Eccezione lanciata quando il valore fornito in input alla funzione è negativo o pari a zero.
 * 
 * @param value 
 * @return int 
 */
int Sum::evenIntSum(int value) {
    if(value > 0) {
        try {
            return value*(value + 1);
        } catch(std::overflow_error& e) {
            throw new std::overflow_error("Arithmetic overflow occurred.");
        }
    } else {
        throw new std::invalid_argument("Input value cannot be negative or zero.");
    }
}

/**
 * @brief Funzione wrapper per calcolare la somma dei valori multipli di valueA o valueB (i due valori in input) ed inferiori
 * al valore obiettivo (target). Poiché utilizzata per chiamare un'altra funzione (sumDivisibleBy()), queste devono essere entrambe
 * riportate nel codice del programma.
 * @warning Questa funzione lancia un'eccezione quando si verifica una condizione di overflow aritmetico.
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * 
 * @param valueA 
 * @param valueB 
 * @param target 
 * @return int 
 */
int Sum::sumMultiples(int valueA, int valueB, int target) {
    try {
        return sumDivisibleBy(valueA, target) + sumDivisibleBy(valueB, target) - sumDivisibleBy(valueA*valueB, target);
    } catch(std::overflow_error& e) {
        throw new std::overflow_error("Arithmetic overflow occurred.");
    }
}

/**
 * @brief Questa funzione è utilizzata per calcolare la somma di tutti i valori pari positivi e multipli del valore dato in
 * input, utilizzando la formula (opportunamente modificata) della somma di Gauss.
 * 
 * @param N 
 * @param target 
 * @return int 
 */
int Sum::sumDivisibleBy(int N, int target) {
    int p = target/N;
    return N*(p*(p + 1))/2;
}

/**
 * @brief Questa funzione calcola la somma delle cifre di valori molto grandi (per questo motivo, in input non può essere inserito un dato di tipo int o sua variante,
 * ma deve essere inserito un dato di tipo "std::string").
 * 
 * @param str 
 * @return unsigned long long int 
 */
unsigned long long int digitSum(std::string str) {
    std::string::iterator it;

    std::reverse(str.begin(), str.end());
    it = str.begin();

    unsigned long long int sum = 0;
    while(*it == '0' || *it == '.') {
        it++;
    }
    
    while(it != str.end()) {
        sum += *it - '0';
        it++;
    }

    return sum;
}