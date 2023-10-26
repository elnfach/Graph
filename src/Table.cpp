#include <iostream>
#include "Table.h"

Table::Table()
{
}

Table::~Table()
{
}

void Table::view_table()
{
	for (auto i = name_nodes.begin(); i != name_nodes.end(); i++)
	{
		std::cout << "\t" << *i;
	}
	for (auto i = weight_edges.begin(); i != weight_edges.end(); i++)
	{
		std::cout << std::get<0>(*i);
	}
}
