#include <iostream>
#include "GraphNode.h"

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

GraphNode::GraphNode(std::string name, int x, int y)
{
    m_name = name;
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
    if (!m_edges.empty())
    {
        std::cout << "Ребра " << m_name << "а:" << std::endl;
        for (auto i = m_edges.begin(); i != m_edges.end(); i++)
        {
            std::cout << m_name << " = " << (*i)->get_weight() << " => " << (*i)->get_direction()->m_name << std::endl;
        }
        return;
    }
    std::cout << "У " << m_name << " нет ребер\n";
}

void GraphNode::view_table(GraphNode* node)
{
    for (auto i = node->m_edges.begin(); i != node->m_edges.end(); i++)
    {
        std::cout << "\t" << (*i)->get_weight();
    }
}

void GraphNode::view_parents()
{
    if (!m_parents.empty())
    {
        std::cout << "Родители " << m_name << "а:" << std::endl;
        for (auto i = m_parents.begin(); i != m_parents.end(); i++)
        {
            std::cout << (*i)->m_name << std::endl;
        }
        return;
    }
    std::cout << "У " << m_name << " нет родителей\n";
}

void GraphNode::create_edge(GraphNode* direction)
{
    Edge* edge = new Edge(this, direction);
    direction->m_parents.push_back(this);
    m_edges.push_back(edge);
}

bool GraphNode::get_edge(GraphNode* start, GraphNode* direction)
{
    for (auto i = start->m_edges.begin(); i != start->m_edges.end(); i++)
    {
        if ((*i)->get_direction() == direction)
        {
            return true;
        }
    }
    return false;
}

std::pair<int, int> GraphNode::get_position()
{
    return std::pair<int, int>(m_x, m_y);
}