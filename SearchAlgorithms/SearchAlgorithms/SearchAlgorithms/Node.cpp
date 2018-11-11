#include"Node.h"
// The Node constructor uses an initializer list to set a name. This must have a value.
// When instantiating a new node on the graph, use "empty" to designate an empty
// node.
// Also parse the four costs to the cost array.
Node::Node(std::string Name, int costN, int costE, int costS, int costW):name(Name)
{
	costToLeave[0] = costN; // North.
	costToLeave[1] = costE; // East.
	costToLeave[2] = costS; // South.
	costToLeave[3] = costW; // West.

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

void Node::getCostToLeave()
{
	// For loop cycling through the size of the vector.
	// Uses the size function to determine how many neighbours
	// are attached to this node.
	for (int i = 0; i < neighbours.size(); i++)
	{
		std::cout << "The cost to get to " << neighbours[i]->name << " is: " << costToLeave[i] << std::endl;
	}
}

void Node::getNeighbours()
{
	// For loop cycling through the size of the vector.
	// Uses the size function to determine how many neighbours
	// are attached to this node.
	// This function is essentially the same as getCostToVisit
	// but accesses a different member.
	for (int i = 0; i < neighbours.size(); i++)
	{
		std::cout << "My neighbour is: " << neighbours[i]->name << std::endl;
	}
}

// Simple getter - however it is important to pay attention to formatting here.
void Node::getName()
{
	std::cout << std::endl << "Current location: " << name << std::endl;
}

// Destructor
Node::~Node()
{}
