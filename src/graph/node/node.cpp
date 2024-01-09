#include "node.h"
#include <algorithm>

Node::Node() {
    value = 0;
    adj = new std::vector<Node>();
    visitato = false;
}

Node::Node(int val, std::vector<Node>* adj) {
    value = val;
    this->adj = new std::vector<Node>();
    for(const auto & i : *adj) {
        this->adj->push_back(i);
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

bool Node::getVisitato()const {
    return visitato;
}

void Node::addAdjacent(Node n) {
    adj->push_back(n);
}

void Node::removeAdjacent(Node n) {
    auto it = std::find(adj->begin(), adj->end(), n);
    if(it != adj->end()) {
        adj->erase(it);
        adj->shrink_to_fit();
    }
}

void Node::setAdjacent(std::vector<Node>* adj1) {
    this->adj = adj1;
}

bool Node::operator==(const Node& n)const {
    return value == n.value && adj == n.adj;
}

bool Node::operator<(const Node &n) const {
    return value < n.value;
}