#ifndef TEST_GRAPHS_INCLUDE_GRAPH_NODE_H
#define TEST_GRAPHS_INCLUDE_GRAPH_NODE_H

#include <string>
#include <list>
#include "Edge.h"

class GraphNode
{
	std::string m_name;
	int m_x;
	int m_y;

	std::list<GraphNode*> m_parents;
	std::list<Edge*> m_edges;
public:
	GraphNode();
	GraphNode(int x, int y);
	~GraphNode();

	void view();
	void create_edge(GraphNode* node);

	std::pair<int, int> get_position();
};

#endif // !TEST_GRAPHS_INCLUDE_GRAPH_NODE_H