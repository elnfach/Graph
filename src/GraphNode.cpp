#include "GraphNode.h"
#include <iostream>

GraphNode::GraphNode()
{
    m_name = "Default name";
    m_x = 0;
    m_y = 0;
    m_parents.clear();
    m_edges.clear();
}

GraphNode::GraphNode(int x, int y)
{
    m_name = "Default name";
	m_x = x;
	m_y = y;
    m_parents.clear();
    m_edges.clear();
}

GraphNode::~GraphNode()
{
}

void GraphNode::view()
{
    std::cout << "Name Node = " << m_name << " => " << std::endl;
    for (auto i = m_edges.begin(); i != m_edges.end(); i++)
    {
        std::cout << "Name Node = " << (*i)->get_direction()->m_name << " => " << std::endl;
    }
}

void GraphNode::create_edge(GraphNode* node)
{
    Edge* edge = new Edge(this, node);
    m_edges.push_back(edge);

}

std::pair<int, int> GraphNode::get_position()
{
    return std::pair<int, int>(m_x, m_y);
}