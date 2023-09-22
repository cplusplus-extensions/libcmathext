#ifndef MFSET_H
#define MFSET_H

#include <iostream>
#include <vector>
#include <set>

/**
 * @brief Utility class used to implements the components for the MFSET class.
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
         * @return T The representative of this instance of the class
         */
        T getRepr() const;

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
        bool contains(T elem) const;

        /**
         * @brief This method returns the number of elements currently stored in this instance of the class.
         * 
         * @return int The number of elements currently stored in this instance of the class
         */
        int size() const;

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

/**
 * @brief This class is an implementation of the MFSET structure which can contain any type that can be ordered through a total order relation. 
 * Its mathematical complexity varies depending on the implementation of the underlying structure. For example, the complexity of this structure 
 * is generally O(n) when the underlying set is implemented using lists, but it is proven that its value drops to O(log n) when the underlying 
 * set is implemented using balanced trees without using the rank heuristic. It is also proven that its complexity drops even more to 
 * O(n + m*alpha(n, m)), where alpha(n, m) is the inverse Ackermann function, when using the rank heuristic on balanced trees. 
 * Given two elements in this structure, this heuristic:
 * 1) finds the representative of the component containing each of the two elements;
 * 2) if they are the same, nothing is done;
 * 3) otherwise, this heuristic determines which is the tree with the shortest height between the two and appends its root to the other tree,
 * making it a direct child of the other tree's root.
 * Upon usage, this heuristic might cause the height of the tree to increase by 1.
 * 
 * @tparam T The type of data contained by this structure
 */
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
        RMFSET<T>* find(T elem) const;

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
