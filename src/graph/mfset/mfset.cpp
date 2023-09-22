#include "mfset.h"
#include <algorithm>
#include <utility>

template <class T> MFSET<T>::MFSET(std::vector<T>* init) {
    vset = new std::vector<RMFSET<T>>();
    for(T item: *init) {
        RMFSET<T>* newset = new RMFSET<T>(item);
        vset->push_back(newset);
    }
}

template <class T> RMFSET<T>::RMFSET(T repr) {
    this->repr = repr; //Initialize the representative
    items = new std::set<T>();
}

template <class T> T RMFSET<T>::getRepr() {
    return repr;
}

template <class T> void RMFSET<T>::setRepr(T newrepr) {
    repr = newrepr;
}

template <class T> bool RMFSET<T>::contains(T elem) {
    return std::find(items->begin(), items->end(), elem) != items->end();
}

template <class T> RMFSET<T>* MFSET<T>::find(T elem) {
    for(RMFSET<T>* item: *vset) {
        if(item->contains(elem)) {
            return item;
        }
    }
    return nullptr;
}

template <class T> int RMFSET<T>::size() {
    return items->size();
}

template <class T> void RMFSET<T>::merge(RMFSET<T>* it1) {
    items->merge(it1->items);
    it1->setRepr(repr);
}

template <class T> void MFSET<T>::merge(T first, T second) {
    RMFSET<T>* frepr = find(first), *srepr = find(second);
    if(frepr != nullptr && srepr != nullptr) {
        if(frepr != srepr) {
            //Procedo al merge
            if(frepr->size() < srepr->size()) {
                //Concateno il primo al secondo
                srepr->concat(frepr);
            } else {
                //Concateno il secondo al primo
                frepr->concat(srepr);
            }
        }
    } else {
        std::cerr << "Almeno un elemento non e' stato trovato." << std::endl;
    }
}

template <class T> RMFSET<T>::~RMFSET() {
    delete items;
}

template <class T> MFSET<T>::~MFSET() {
    for(RMFSET<T>* item: *vset) {
        delete item;
    }
    delete vset;
}