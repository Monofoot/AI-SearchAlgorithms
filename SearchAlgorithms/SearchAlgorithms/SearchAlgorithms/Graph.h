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

public:
	// Constructor
	Graph();
	// Set up the map of nodes
	void map();
	void addToVector(Node* node);
	// Print the map in a presentable structure.
	void printMap();

	// Destructor
	~Graph();
};