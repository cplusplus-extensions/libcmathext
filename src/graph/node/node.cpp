#include "node.h"

Node::Node(int val, std::vector<Node>* adj) {
    value = val;
    for(int i = 0; i < adj->size(); i++) {
        this->adj->push_back(adj->at(i));
    }
    visitato = false;
}

bool Node::evenVertex() {
    return adj->size()%2 == 0;
}

std::vector<Node>* Node::adjacent() {
    return adj;
}

void Node::setVisitato(bool val) {
    visitato = val;
}

bool Node::getVisitato() {
    return visitato;
}