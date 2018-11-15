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
	// The cost to travel in a direction FROM this node.
	// [North], [East], [South], [West]
	int costToLeave[4];
	// Use an array of:
	// [North], [East], [South], [West] as we know how many adjacent links we'll be using.
	Node* neighbours[4];
	// We must hold a boolean in each node for the visited status.
	// This is to prevent algorithms hitting the node more than once
	// and potentially endlessly looping.
	bool visited;

public:
	// The constructor for a node will also set the name.
	// The constructor also sets the cost to LEAVE this node.
	// I would prefer to have the cost be for VISITING this node,
	// but the specification of Tunnels of Terror is such that
	// costs are different for one node depending on which direction
	// you approach from.
	// Name "empty" and set cost to 0 if the node is empty. <- this may cause future issues
	Node(std::string Name, int costN, int costE, int costS, int costW);
	// Set the neighbours of this node.
	void setNeighbours(Node* nextNorth, Node* nextEast, Node* nextSouth, Node* nextWest);
	// Setter for the visited boolean.
	void setVisited(bool x);
	
	// Accessor Methods
	// These three functions are used heavily in the Graph class.
	// Using these three together we can neatly present our data structure.
	void getCostToLeave();
	void getNeighbours();
	Node* getNorth();
	Node* getEast();
	Node* getSouth();
	Node* getWest();
	void getName();
	bool getVisited();

	// Destructor
	~Node();
};