#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<list>

// The node uses an adjacency linked list write about it
class Node
{
private:
	// Node's name. Object will be initialized with a name.
	std::string name;
	// Node's cost. This is a test. The idea is that the cost variable should
	// be the cost to travel TO, not from, this node.
	int costToVisit;
	// A vector contains pointers to all of the node's neighbours.
	std::vector<Node*> neighbours;

public:
	// The constructor for a node will also set the name.
	Node(std::string Name);
	// Set the neighbours of this node.
	void setNeighbours(Node* nextNorth, Node* nextEast, Node* nextSouth, Node* nextWest);
	// Set the cost to VISIT this node.
	void setCostToVisit(int cost);
	// Get the cost to visit a node.
	void getCostToVisit(Node* getCost);




	// Debugging functions.
	void testExists();
	void getNeighbours();

	~Node();
};