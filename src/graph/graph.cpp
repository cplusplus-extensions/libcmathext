#include "graph.h"
#include <algorithm>
#include <map>
#include <queue>

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

/**
 * @brief This function computes the Erdos number for each node in the graph, given a starting node. It also populates a fathers' map 
 * which can be used to compute other results.
 * @attention Using this function, every Node instance of this graph that is not visited will be paired with a value of -1 in the final 
 * result.
 * 
 * @param start The starting node
 * @param p The fathers' map
 * @return std::map<int>* A pointer to a map of integers containing the Erdos number for each of the nodes in the graph
 */
std::map<Node, int>* Graph::erdos(Node* start, std::map<Node, Node>* p) {
    std::map<Node, int>* map = new std::map<Node, int>();
    std::queue<Node>* queue = new std::queue<Node>();
    int count = 1, def = -1;
    map->insert(*(new std::pair<Node, int>(*start, 0)));
    queue->push(*start);
    while(!queue->empty()) {
        Node s = queue->front();
        queue->pop();
        for(Node n: *s.adjacent()) {
            if(!n.getVisitato()) {
                map->insert(*(new std::pair<Node, int>(n, count)));
                p->insert(*(new std::pair<Node, Node>(n, s)));
                n.setVisitato(true);
                queue->push(n);
            }
        }
        count = count + 1;
    }

    std::for_each(vect->begin(), vect->end(), [&, map](Node n) -> bool {
        if(!n.getVisitato()) {
            map->insert(*(new std::pair<Node, int>(n, def)));
        }
    });
    delete queue;
    return map;
}

/**
 * @brief This method adds a Node instance to the Graph and attaches it to the given Node instance.
 * 
 * @param p The given Node instance
 * @param value The value from which to build the new Node instance
 */
void Graph::insertNode(Node* p, int value) {
    Node* n = new Node(value, new std::vector<Node>());
    vect->push_back(*n);
    p->addAdjacent(*n);
}

/**
 * @brief This method removes the given Node instance from the calling Graph instance.
 * 
 * @param n The given Node instance
 * @return Node The removd Node instance
 */
Node Graph::removeNode(Node n) {
    Node prev(0, nullptr);
    for(Node s: *vect) {
        std::vector<Node>::iterator it;
        if(s == n) {
            it = std::find(vect->begin(), vect->end(), s);
            if(it != vect->end()) {
                vect->erase(it);
                vect->shrink_to_fit();
            }
        } else {
            std::vector<Node>* ad = s.adjacent();
            it = std::find(ad->begin(), ad->end(), s);
            if(it != ad->end()) {
                ad->erase(it);
                ad->shrink_to_fit();
                s.setAdjacent(ad);
            }
        }
    }
}

/**
 * @brief This method returns the size of the calling Graph instance, i.e. the number of Node instances it contains.
 * 
 * @return int The size of the calling Graph instance
 */
int Graph::size() {
    return vect->size();
}