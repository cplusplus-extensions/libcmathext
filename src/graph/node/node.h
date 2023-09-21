#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

class Node {
    private:
        int value;
        std::vector<Node>* adj;
        bool visitato; //Useful to visit a Graph
    
    public:
    /**
     * @brief Construct a new Node object
     * 
     * @param val 
     * @param adj 
     */
    Node(int val, std::vector<Node>* adj);

    /**
     * @brief Returns a vector of Nodes adjacent to this one
     * 
     * @return std::vector<Node>* A pointer to a vector containing the adjacent nodes
     */
    std::vector<Node>* adjacent();

    /**
     * @brief Sets the visited value of a Node
     * 
     * @param val Bool parameter; true if the Node is visited, false otherwise
     */
    void setVisitato(bool val);

    /**
     * @brief Checks if this Node has been visited
     * 
     * @return true if this Node has already been visited
     * @return false otherwise
     */
    bool getVisitato();

    /**
     * @brief This method verifies if a vertex has even valency (in other words, this method verifies if a vertex is connected
     * to an even number of other vertices).
     * 
     * @return true 
     * @return false 
     */
    bool evenVertex();

    /**
     * @brief This method sets a Node instance to be adjacent to the calling Node instance.
     * 
     * @param n The new Node instance
     */
    void addAdjacent(Node n);

    /**
     * @brief This method removes an adjacent Node instance. This is useful when removing a Node instance from a Graph instance.
     * 
     * @param n The Node instance to be removed
     */
    void removeAdjacent(Node n);

    void setAdjacent(std::vector<Node>* adj);

    bool operator==(Node& n);

    /* Add any other useful method */
};

#endif
