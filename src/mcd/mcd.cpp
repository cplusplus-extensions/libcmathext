#include "mcd.h"
#include <numeric>
#include <algorithm>

MCD::MCD(std::vector<int>* vect = nullptr) {
    if(vect != nullptr) {
        this->vect = new std::vector<int>(vect->size());
        for(int i = 0; i < this->vect->size(); i++) {
            this->vect->at(i) = vect->at(i);
        }
    } else {
        this->vect = nullptr;
    }
}

MCD::MCD(long long int a, long long int b) {
    this->a = a;
    this->b = b;
    vect = nullptr;
}

MCD::MCD(const MCD& mcd) {
    this->a = mcd.a;
    this->b = mcd.b;
    if(mcd.vect == nullptr) {
        vect = nullptr;
    } else {
        vect = new std::vector<int>(mcd.vect->size());
        for(int i = 0; i < vect->size(); i++) {
            vect->at(i) = mcd.vect->at(i);
        }
    }
}

MCD::~MCD() {
    delete[] vect;
}

/**
 * @brief Questa funzione implementa l'estensione dell'algoritmo di Euclide per il calcolo del Massimo Comun Divisore nel caso in cui si abbiano
 * due o più valori, acquisendo, in input, un vettore contenente tali valori. Utilizza la funzione gcd() (appartenente al namespace std, ma disponibile
 * solamente se si possiede almeno la versione C++17 della STL).
 * 
 * @return int 
 */
unsigned long long int MCD::gcd() noexcept {
    unsigned long long int i, GCD = 1;

    std::sort(vect->begin(), vect->end());
    for(i = 0; i < vect->size() - 1; i++) {
        GCD = std::gcd(vect->at(i), vect->at(i + 1));
    }

    return GCD;
}

/**
 * @brief Questa funzione implementa l'estensione dell'Algoritmo di Euclide per calcolare il Massimo Comun Divisore tra due o più valori. Al contrario
 * di MCD::gcd(), non utilizza std::gcd, pertanto può essere utilizzata su tutte le versioni del linguaggio.
 * 
 * @return unsigned long long int 
 */
unsigned long long int MCD::mcd2() noexcept {
    unsigned long long int i, GCD = 1;

    std::sort(vect->begin(), vect->end());
    for(i = 0; i < vect->size() - 1; i++) {
        a = vect->at(i);
        b = vect->at(i + 1);
        GCD = mcd();
    }

    return GCD;
}

/**
 * @brief Versione iterativa algoritmo di Euclide per il calcolo del MCD tra due numeri. Questa versione richiede in input due valori (a e b)
 * che vengono continuamente aggiornati seguendo il procedimento stabilito dall'algoritmo di Euclide, che, a causa del calcolo del resto, non
 * è consigliato per valori molto grandi.
 * 
 * @return int 
 */
unsigned long long int MCD::mcd() noexcept {
    int res = 0;

    if(b != 0) {
        while(a%b != 0) { //Attenzione alle divisioni per zero!
            res = a%b;

            a = b;
            b = res;
        }
    } else {
        res = a;
    }

    return res;
}