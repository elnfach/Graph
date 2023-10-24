#ifndef TEST_GRAPHS_INCLUDE_EDGE_H
#define TEST_GRAPHS_INCLUDE_EDGE_H

#include "GraphNode.h"

class Edge
{
	int m_weight;
	GraphNode* m_direction;
public:
	Edge();
	Edge(GraphNode* root, GraphNode* destination);
	~Edge();

	GraphNode* get_direction();
	int get_weight();
};

#endif // !TEST_GRAPHS_INCLUDE_EDGE_H