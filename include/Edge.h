#ifndef GRAPH_INCLUDE_EDGE_H
#define GRAPH_INCLUDE_EDGE_H

class GraphNode;
class Edge
{
	int m_weight;
	GraphNode* m_direction;
public:
	Edge();
	Edge(GraphNode* root, GraphNode* direction);
	~Edge();

	GraphNode* get_direction();
	int get_weight();
};

#endif // !GRAPH_INCLUDE_EDGE_H