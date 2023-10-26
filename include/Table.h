#ifndef GRAPH_INCLUDE_TABLE_H
#define GRAPH_INCLUDE_TABLE_H

#include <list>
#include "GraphNode.h"

static class Table
{
	static int count_nodes;
	static std::list<std::string> name_nodes;

	// 1.start 2.direction 3.weight
	static std::list<std::tuple<std::string, std::string, int>> weight_edges;
	template<class _T>
	struct Cell
	{
		_T data;
	};
public:
	Table();
	~Table();

	static void view_table();
	inline static void increase(std::string name) { count_nodes += 1; name_nodes.push_back(name); }
};

#endif // !GRAPH_INCLUDE_TABLE_H