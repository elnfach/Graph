#ifndef GRAPH_INCLUDE_GRAPH_H
#define GRAPH_INCLUDE_GRAPH_H

#include <list>
#include <string>

class GraphNode;
class Graph
{
	std::string m_name;

	std::list<GraphNode*> m_nodes;
public:
	Graph();
	Graph(std::string name);
	~Graph();

	void view();
	void view_table();
	void add_node(std::string name);
	void add_node(std::string name, int x, int y);

	void create_edge(std::string start, std::string direction, bool is_back = false);
};
#endif // !GRAPH_INCLUDE_GRAPH_H