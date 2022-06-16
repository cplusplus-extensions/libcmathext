#include "prime.h"

PrimeNum::PrimeNum(int val = 0, unsigned long long int num = 0) {
    this->val = val;
    this->num = num;
}

/**
 * @brief Questa funzione calcola il più grande fattore primo del numero dato. Credits: hk (ProjectEuler)
 * 
 * @param n 
 * @return long long int
 */
long long int PrimeNum::maxPrimeFactors(long long int n) { 
    //Initialize the maximum prime factor variable with the lowest one.
    long long int maxPrime = -1; 

    if(n%2 == 0) {
        n /= 2;
        maxPrime = 2;
        while(n%2 == 0) {
            n >> 1; //Equivalent to n /= 2
        }
    } else {
        maxPrime = 1;
    }
    
    //n must be odd at this point, thus skip the even numbers and iterate only for odd integers.

    int i = 3, maxFactor = sqrt(n);
    while(n > 1 && i <= maxFactor) {
        if(n%i == 0) {
            n /= i;
            maxPrime = i;
            while(n%i == 0) {
                n /= i;
            }
            maxFactor = sqrt(n);
        }
        i += 2;
    }

    if(n == 1) {
        return maxPrime;
    }
    return n;
}

/**
 * @brief Questa funzione stampa il più grande numero primo inferiore al valore limite indicato in input. ATTENZIONE: per valori interi molto grandi
 * in valore assoluto, utilizzare printPrimeULL().
 * @param limit 
 * @return int 
 */
int PrimeNum::printPrime(int limit) {
    int counter = 1, candidate = 1;

    do {
        candidate += 2;
        if(isPrime(candidate)) {
            counter++;
        }
    } while(counter < limit);

    std::cout << candidate;
}

/**
 * @brief Questa funzione restituisce "true" se il valore dato in input corrisponde ad un numero primo, altrimenti restituisce "false". ATTENZIONE: per valori interi
 * molto grandi in valore assoluto, utilizzare isPrimeULL().
 * 
 * @param value 
 * @return bool
 */
bool PrimeNum::isPrime(int value) {
    //Base dell'induzione
    if(value == 1) {
        return false;
    }
    if(value < 4) {
        return true; //2 e 3 sono primi
    }
    if(value%2 == 0) {
        return false;
    }
    if(value < 9) {
        return true; //4, 6 ed 8 sono già stati esclusi
    }
    if(value%3 == 0) {
        return false;
    }

    //Passo induttivo
    int r = floor(sqrt(value)), f = 5;
    while(f <= r) {
        if(value%f == 0) {
            return false; //Step out of the function
        }
        if(value%(f + 2) == 0) {
            return false;
        }
        f += 6;
    }

    return true;
}

/**
 * @brief Questa funzione calcola il numero primo più grande inferiore al valore dato in input, permettendo di lavorare anche con valori molto grandi in valore assoluto.
 * 
 * @param limit 
 * @return unsigned long long int 
 */
unsigned long long int PrimeNum::printPrimeULL(unsigned long long int limit) {
    unsigned long long int counter = 1, candidate = 1;

    do {
        candidate += 2;
        if(isPrimeULL(candidate)) {
            counter++;
        }
    } while(counter < limit);

    std::cout << candidate;
}

/**
 * @brief Questa funzione restituisce "true" se il valore dato in input corrisponde ad un numero primo, altrimenti restituisce "false". A differenza di isPrime(),
 * tuttavia, permette di lavorare anche con valori molto grandi in valore assoluto.
 * 
 * @param value 
 * @return bool
 */
bool PrimeNum::isPrimeULL(unsigned long long int value) {
    //Base dell'induzione
    if(value == 1) {
        return false;
    }
    if(value < 4) {
        return true; //2 e 3 sono primi
    }
    if(value%2 == 0) {
        return false;
    }
    if(value < 9) {
        return true; //4, 6 ed 8 sono già stati esclusi
    }
    if(value%3 == 0) {
        return false;
    }

    //Passo induttivo
    int r = floor(sqrt(value)), f = 5;
    while(f <= r) {
        if(value%f == 0) {
            return false; //Step out of the function
        }
        if(value%(f + 2) == 0) {
            return false;
        }
        f += 6;
    }

    return true;
}