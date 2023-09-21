#include "node.h"
#include <algorithm>

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

void Node::addAdjacent(Node n) {
    adj->push_back(n);
}

void Node::removeAdjacent(Node n) {
    std::vector<Node>::iterator it = std::find(adj->begin(), adj->end(), n);
    if(it != adj->end()) {
        adj->erase(it);
        adj->shrink_to_fit();
    }
}

void Node::setAdjacent(std::vector<Node>* adj) {
    this->adj = adj;
}

bool Node::operator==(Node& n) {
    return value == n.value && adj == n.adj;
}