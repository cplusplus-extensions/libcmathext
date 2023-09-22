#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include "node/node.h"

class Graph {
	private:
		std::vector<Node>* vect;

		bool isAcyclicRec(Node p) {
			p.setVisitato(true);
			for(Node s: *(p.adjacent())) {
				if(s.getVisitato() || !isAcyclicRec(s)) {
					return false;
				}
			}
			return true;
		}
	
	public:
		/**
		* @brief Construct a new Graph object
		* 
		* @param size 
		*/
		explicit Graph() {
		    vect = new std::vector<Node>();
		}
		
		/**
		 * @brief Copy constructor.
		 * 
		 * @param g The old Graph instance from which to build the new one
		 */
		Graph(const Graph& g) {
			vect = new std::vector<Node>(g.vect->size());
			for(int i = 0; i < vect->size(); i++) {
				vect->at(i) = g.vect->at(i);
			}
		}
		
        ~Graph() {
            delete[] vect;
        }
        
		int oddVertNum();
		bool eulerianGraph();
		bool eulerianPath();
		std::map<Node, int>* erdos(Node* start, std::map<Node, Node>* p);
		void insertNode(Node* p, int value);
		Node removeNode(Node n);
		int size();

		bool isAcyclic();
		
		/* Add any other useful method */
};

#endif
