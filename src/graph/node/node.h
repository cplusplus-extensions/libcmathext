#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

class Node {
    private:
        int value;
        std::vector<int> adj;
    
    public:
    /**
     * @brief Construct a new Node object
     * 
     * @param val 
     * @param adj 
     */
    Node(int val, std::vector<int> adj);

    /**
     * @brief This method verifies if a vertex has even valency (in other words, this method verifies if a vertex is connected
     * to an even number of other vertices).
     * 
     * @return true 
     * @return false 
     */
    bool evenVertex();

    /* Add any other useful method */
};

#endif
