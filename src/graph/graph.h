#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include "node/node.h"

class Graph {
	private:
		std::vector<Node>* vect;
	
	public:
		/**
		* @brief Construct a new Graph object
		* 
		* @param size 
		*/
		explicit Graph() {
		    vect = new std::vector<Node>();
		}
		
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
		
		/* Add any other useful method */
};

#endif
