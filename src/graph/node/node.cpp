#include "node.h"

Node::Node(int val, std::vector<int> adj) {
    value = val;
    for(int i = 0; i < adj.size(); i++) {
        this->adj.push_back(adj.at(i));
    }
}

bool Node::evenVertex() {
    return adj.size()%2 == 0;
}