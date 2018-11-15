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
	neighbours[0] = nextNorth;
	neighbours[1] = nextEast;
	neighbours[2] = nextSouth;
	neighbours[3] = nextWest;
}

// Set whether or not this node has been visited. 
// This is important for most of the algorithms to work as
// we need to mark whether or not a node is visited to prevent
// recursion.
void Node::setVisited(bool x)
{
	if (x == true)
	{
		visited = true;
	}
	else
	{
		visited = false;
	}
}

// Accessor Methods

void Node::getCostToLeave()
{
	// For loop cycling through the size of the vector.
	// Uses the size function to determine how many neighbours
	// are attached to this node.
	int n = sizeof(neighbours) / sizeof(neighbours[0]);

	for (int i = 0; i < n; i++)
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
	int n = sizeof(neighbours) / sizeof(neighbours[0]);

	for (int i = 0; i < n; i++)
	{
		std::cout << "My neighbour is: " << neighbours[i]->name << std::endl;
	}
}

Node* Node::getNorth()
{
	return neighbours[0];
}

Node* Node::getEast()
{
	return neighbours[1];
}

Node* Node::getSouth()
{
	return neighbours[2];
}

Node* Node::getWest()
{
	return neighbours[3];
}

void Node::getName()
{
	std::cout << name;
}

bool Node::getVisited()
{
	return visited;
}

// Destructor
Node::~Node()
{}
