#include "sum.h"
#include <algorithm>
#include <stdexcept>
#include <cmath>

Sum::Sum(int val, int val1, int val2) {
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
        return value*value;
    } else {
        throw std::invalid_argument("Input value cannot be negative or zero.");
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
        return value*(value + 1);
    } else {
        throw std::invalid_argument("Input value cannot be negative or zero.");
    }
}

/**
 * @brief Funzione wrapper per calcolare la somma dei valori multipli di valueA o valueB (i due valori in input) ed inferiori
 * al valore obiettivo (target). Poiché utilizzata per chiamare un'altra funzione (sumDivisibleBy()), queste devono essere entrambe
 * riportate nel codice del programma.
 * @warning Questa funzione lancia un'eccezione quando si verifica una condizione di overflow aritmetico.
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 *
 * @return int La somma dei valori multipli (fino a target) di uno dei primi due parametri in input.
 */
int Sum::sumMultiples() {
    try {
        return sumDivisibleBy(valueA, target) + sumDivisibleBy(valueB, target) - sumDivisibleBy(valueA*valueB, target);
    } catch(std::overflow_error& e) {
        throw std::overflow_error("Arithmetic overflow occurred.");
    }
}

/**
 * @brief Questa funzione è utilizzata per calcolare la somma di tutti i valori pari positivi e multipli del valore dato in
 * input, utilizzando la formula (opportunamente modificata) della somma di Gauss.
 * 
 * @param N 
 * @param target 
 * @return int La somma di tutti i valori pari positivi e multipli del valore dato in input.
 */
int Sum::sumDivisibleBy(int N, int target) {
    int p = target/N;
    return N*(p*(p + 1))/2;
}

/**
 * @brief Questa funzione calcola la somma delle cifre di valori molto grandi (per questo motivo, in input non può essere
 * inserito un dato di tipo int o sua variante, ma deve essere inserito un dato di tipo "std::string").
 * 
 * @param str 
 * @return unsigned long long int 
 */
unsigned long long int Sum::digitSum(std::string str) {
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

/**
 * @brief Questa funzione calcola il risultato della serie geometrica di ragione "reason" ed esponente "exp" se la serie
 * geometrica infinita da cui essa deriva è convergente.
 * 
 * @exception std::overflow_error Eccezione lanciata quando si verifica una condizione di overflow aritmetico.
 * @exception std::invalid_argument Se la serie geometrica data dalla ragione fornita in input &egrave; irregolare o divergente.
 * @param reason La ragione della serie geometrica
 * @param exp L'esponente della serie geometrica
 * @return long double Il risultato del calcolo della serie geometrica
 */
long double Sum::geomProgression(double reason, unsigned long long int exp) {
    try {
        if(reason > -1 && reason < 1) {
            //La serie geometrica converge
            return (1.0 - std::pow(reason, exp + 1))/(1.0 - reason);
        } else {
            if(reason <= -1) {
                //La ragione è minore o uguale a -1, quindi la serie è irregolare
                throw std::invalid_argument("Any geometric series with the given reason is irregular.");
            } else {
                //La ragione è maggiore o uguale a 1, quindi la serie diverge positivamente
                throw std::invalid_argument("Any gometric series with the given reason is positively divergent.");
            }
        }
    } catch(std::overflow_error& e) {
        throw std::overflow_error("Arithmetic overflow occurred.");
    }
}