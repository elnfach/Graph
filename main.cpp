#include <iostream>

#include "GraphNode.h"

using namespace std;

int main()
{
	GraphNode* p1 = new GraphNode(8, 8);
	GraphNode* p2 = new GraphNode(3, 3);
	
	p1->create_edge(p2);

	p1->view();
}