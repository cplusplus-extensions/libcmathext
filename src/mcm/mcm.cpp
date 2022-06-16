#include "mcm.h"
#include "../mcd/mcd.h"

void MCM::createVect(std::vector<int>* vect) {
    if(vect != nullptr) {
        this->vect = new std::vector<int>(vect->size());
        for(int i = 0; i < vect->size(); i++) {
            this->vect->at(i) = vect->at(i);
        }
    } else {
        this->vect = nullptr;
    }
}

MCM::MCM(int a, int b) {
    this->a = a;
    this->b = b;
    createVect(nullptr);
}

MCM::MCM(std::vector<int>* vect) {
    a = -1;
    b = -1;
    createVect(vect);
}

MCM::MCM(const MCM& mcm) {
    a = mcm.a;
    b = mcm.b;
    createVect(mcm.vect);
}

int MCM::mcm() {
    MCD* tempRes = new MCD(a, b);
    return (a*b)/tempRes->gcd();
}

int MCM::mcmVect() {
    if(vect != nullptr) {
        int tempRes = 0;
        std::vector<int>::iterator it = vect->begin();
        while(vect->size() > 1) {
            a = *it;
            b = *(it + 1);
            tempRes = mcm();
            vect->erase(it, it + 2);
            vect->insert(vect->begin(), tempRes);
        }
    }
}