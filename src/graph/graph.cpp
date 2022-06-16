#include "graph.h"
#include <algorithm>

/**
 * @brief This function finds how many vertices have an odd degree in the given graph.
 * 
 * @return int 
 */
int Graph::oddVertNum() {
    int oddCounter = 0;

    std::for_each(vect->begin(), vect->end(), [&oddCounter](Node n) {
        if(!n.evenVertex()) {
            ++oddCounter;
        }
    });

    return oddCounter;
}

/**
 * @brief This function finds if the given graph is a Eulerian graph. To do so, it uses the fact that a Eulerian graph
 * must have exactly no vertices with an odd degree (that is, no vertices in the given graph can have an odd degree
 * for the graph to be Eulerian).
 * 
 * @param graph 
 * @return bool 
 */
bool Graph::eulerianGraph() {
    return oddVertNum() == 0;
}

/**
 * @brief This function finds if the given graph is a Eulerian path. To do so, it uses the fact that a Eulerian path
 * can have at most two vertices with an odd degree.
 * 
 * @param graph 
 * @return bool 
 */
bool Graph::eulerianPath() {
    return oddVertNum() <= 2;
}