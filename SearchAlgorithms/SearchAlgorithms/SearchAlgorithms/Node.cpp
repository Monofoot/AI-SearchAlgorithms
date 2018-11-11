#include"Node.h"
// The Node constructor uses an initializer list to set a name. This must have a value.
// When instantiating a new node on the graph, use "empty" to designate an empty
// node.
Node::Node(std::string Name)
	: name(Name)
{
}

// Set the north, south, east and west neighbours to the current node.
void Node::setNeighbours(Node* nextNorth, Node* nextEast, Node* nextSouth, Node* nextWest)
{
	// Here we use an initializer list for our neighbours vector. By using the .end() function
	// we can append the new entries to the end of the vector. At this point the vector
	// should be empty anyway - unless something has gone horribly wrong.
	// Using an array may be a suitable alternative to this as we can keep it bound to
	// four elements - north, east, south and west.
	neighbours.insert(neighbours.end(), { nextNorth, nextEast, nextSouth, nextWest });
}

// Set the cost to VISIT this node.
void Node::setCostToVisit(int cost)
{
	costToVisit = cost;
}

void Node::getCostToVisit(Node* getCost)
{
	std::cout << "THE COST OF " << neighbours[0]->name << "IS: " << neighbours[0]->costToVisit << std::endl;
	std::cout << "THE COST OF " << neighbours[1]->name << "IS: " << neighbours[1]->costToVisit << std::endl;
	std::cout << "THE COST OF " << neighbours[2]->name << "IS: " << neighbours[2]->costToVisit << std::endl;
	std::cout << "THE COST OF " << neighbours[3]->name << "IS: " << neighbours[3]->costToVisit << std::endl;
}

// Debugging
void Node::testExists()
{
	std::cout << "My name is " << name;
}

void Node::getNeighbours()
{
	std::cout << neighbours[0]->name;
	std::cout << neighbours[1]->name;
	std::cout << neighbours[2]->name;
	std::cout << neighbours[3]->name;
}

// Destructor
Node::~Node()
{}
