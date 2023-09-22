#ifndef MFSET_H
#define MFSET_H

#include <iostream>
#include <vector>
#include <set>

/**
 * @brief This class is an implementation of the MFSET structure which can contain any type that can be ordered through a total order relation.
 * 
 * @tparam T The type of data contained by this structure
 */
template <class T> class RMFSET {
    private:
        T repr;
        std::set<T>* items;
    
    public:
        /**
         * @brief Construct a new RMFSET object
         * 
         * @param repr The element soon to be representative of this class's instance
         */
        RMFSET(T repr);

        RMFSET(RMFSET& rmfset) = delete;
        RMFSET(RMFSET&& rmfset) = delete;

        /**
         * @brief This method allows the user to get the representative of this instance of the class.
         * 
         * @return T The representative of htis instance of the class
         */
        T getRepr();

        /**
         * @brief This method sets the new representative for the calling instance of this class.
         * 
         * @param newrepr The new representative for the calling instance of this class
         */
        void setRepr(T newrepr);

        /**
         * @brief This method checks if the calling instance of this class contains the specified element.
         * 
         * @param elem The given element
         * @return true If the given element is contained in this instance of this class
         * @return false otherwise
         */
        bool contains(T elem);

        /**
         * @brief This method returns the number of elements currently stored in this instance of the class.
         * 
         * @return int The number of elements currently stored in this instance of the class
         */
        int size();

        /**
         * @brief This method allows the merge of two instances of this class.
         * 
         * @param it1 
         */
        void merge(RMFSET<T>* it1);

        /**
         * @brief Destroy the RMFSET object
         * 
         */
        ~RMFSET();
};

template <class T> class MFSET {
    private:
        std::vector<RMFSET<T>*>* vset;

    public:
        /**
         * @brief Construct a new MFSET object.
         * 
         * @param init The vector of objects to be used for initialization 
         */
        MFSET(std::vector<T>* init);

        MFSET(MFSET& mfset) = delete;
        MFSET(MFSET&& mfset) = delete;

        /**
         * @brief This method finds the representative of the instance of the RMFSET class containing the given element and returns a 
         * pointer to the instance it represents (if such a result is found), otherwise it returns nullptr.
         * 
         * @param elem The given element
         * @return RMFSET<T>* A pointer to the instance it represents (if such a result is found), otherwise nullptr.
         */
        RMFSET<T>* find(T elem);

        /**
         * @brief This method merges the instances of the RMFSET class containing the two given elements (if they are different), otherwise 
         * it dos not do anything.
         * 
         * @param first The first of the two given elements
         * @param second The second of the two given elments
         */
        void merge(T first, T second);
        
        /**
         * @brief Destroy the MFSET object
         * 
         */
        ~MFSET();
};

#endif
