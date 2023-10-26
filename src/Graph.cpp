#include <iostream>
#include <algorithm>

#include "Graph.h"
#include "GraphNode.h"


Graph::Graph()
{
}

Graph::Graph(std::string name)
{
}

Graph::~Graph()
{
}

void Graph::view()
{
	for (auto i = m_nodes.begin(); i != m_nodes.end(); i++)
	{
		std::cout << "\n";
		(*i)->view();
		(*i)->view_parents();
	}
}

void Graph::view_table()
{
	std::cout << "\t";
	for (auto i = m_nodes.begin(); i != m_nodes.end(); i++)
	{
		std::cout << (*i)->get_name() << "\t";
	}
	std::cout << std::endl;
	for (auto i = m_nodes.begin(); i != m_nodes.end(); i++)
	{
		std::cout << (*i)->get_name();
		(*i)->view_table((*i));
		std::cout << std::endl;
	}
}

void Graph::add_node(std::string name)
{
	GraphNode* node = new GraphNode(name, 0, 0);
	m_nodes.push_back(node);
	Table::increase(name);
}

void Graph::add_node(std::string name, int x, int y)
{
	GraphNode* node = new GraphNode(name, x, y);
	m_nodes.push_back(node);
	Table::increase(name);
}

void Graph::create_edge(std::string start, std::string direction, bool is_back)
{
	for (auto i = m_nodes.begin(); i != m_nodes.end(); i++)
	{
		if (strcmp((*i)->get_name().c_str(), start.c_str()) == 0)
		{
			for (auto j = m_nodes.begin(); j != m_nodes.end(); j++)
			{
				if (strcmp((*j)->get_name().c_str(), direction.c_str()) == 0)
				{
					if (!GraphNode::get_edge((*i), (*j)))
					{
						if (is_back)
						{
							(*i)->create_edge(*j);
							(*j)->create_edge(*i);
							return;
						}
						(*i)->create_edge(*j);
					}
					else
					{
						std::cout << "Ребро уже существует из " << (*i)->get_name() << "а в " << (*j)->get_name() << std::endl;
					}
					return;
				}
			}
		}
	}
	std::cout << start << " или " << direction << " не существующие узлы!\n";
}
