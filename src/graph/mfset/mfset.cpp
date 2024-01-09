#include "mfset.h"
#include <algorithm>

template <class T> MFSET<T>::MFSET(std::vector<T>* init) {
    vset = new std::vector<RMFSET<T>>();
    for(T item: *init) {
        auto* newset = new RMFSET<T>(item);
        vset->push_back(newset);
    }
}

template <class T> RMFSET<T>::RMFSET(T repr) {
    this->repr = repr; //Initialize the representative
    items = new std::set<T>();
}

template <class T> T RMFSET<T>::getRepr() const {
    return repr;
}

template <class T> void RMFSET<T>::setRepr(T newrepr) {
    repr = newrepr;
}

template <class T> bool RMFSET<T>::contains(T elem) const {
    return std::find(items->begin(), items->end(), elem) != items->end();
}

template <class T> RMFSET<T>* MFSET<T>::find(T elem) const {
    for(RMFSET<T>* item: *vset) {
        if(item->contains(elem)) {
            return item;
        }
    }
    return nullptr;
}

//Modificare la struttura he contiene questo metodo in una struttura esplicitamente organizzata ad albero
template <class T> RMFSET<T>* MFSET<T>::compressedFind(T elem) {
    for(RMFSET<T>* item: *vset) {

        if(item->contains(elem)) {
            return item;
        }
    }
    return nullptr;
}

template <class T> int RMFSET<T>::size() const {
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
            //Proceeding with the merge
            if(frepr->size() < srepr->size()) {
                //Append the first one to the second one
                srepr->concat(frepr);
            } else {
                //Viceversa, append the second one to the first one
                frepr->concat(srepr);
            }
        }
    } else {
        throw std::invalid_argument("At least one of the two elements was not found.");
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