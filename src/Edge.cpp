#include "Edge.h"

Edge::Edge()
{
	m_weight = 0;
	m_direction = nullptr;
}

Edge::Edge(GraphNode* root, GraphNode* destination)
{
	std::pair<int, int> root_position = root->get_position();
	std::pair<int, int> destination_position = destination->get_position();

	m_weight = sqrt(pow(abs(root_position.first - destination_position.first), 2)
		+ pow(abs(root_position.second - destination_position.second), 2));

	m_direction = destination;
}

Edge::~Edge()
{
}

GraphNode* Edge::get_direction()
{
	return m_direction;
}

int Edge::get_weight()
{
	return m_weight;
}
