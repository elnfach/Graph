#ifndef GRAPH_INCLUDE_GRAPH_NODE_H
#define GRAPH_INCLUDE_GRAPH_NODE_H

#include <list>
#include <string>

#include "Edge.h"
#include "Table.h"

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
	GraphNode(std::string name, int x, int y);
	~GraphNode();

	void view();
	void view_table(GraphNode* node);
	void view_parents();

	void create_edge(GraphNode* direction);

	static bool get_edge(GraphNode* start, GraphNode* direction);
	inline std::string get_name() { return m_name; }

	std::pair<int, int> get_position();
};

#endif // !GRAPH_INCLUDE_GRAPH_NODE_H