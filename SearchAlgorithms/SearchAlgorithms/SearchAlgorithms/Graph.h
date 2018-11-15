#pragma once
#include"Node.h"
class Graph
{
private:
	// Add the cost to travel from one node to another
	// and hold the total here.
	int totalCost;

	// Store the nodes in a vector.
	std::vector<Node*> Nodes;

	// Store the current node.
	Node* current;

public:
	// Constructor.
	Graph();
	// Set up the map of nodes.
	void map();
	void addToVector(Node* node);
	// Print the map in a presentable structure.
	void printMap();
	// Breadth First Search algorithm.
	// Parses the starting location to understand where we start from.
	// We also need to parse the end.
	void BFS(Node* start, Node* end);

	// Destructor.
	~Graph();
};