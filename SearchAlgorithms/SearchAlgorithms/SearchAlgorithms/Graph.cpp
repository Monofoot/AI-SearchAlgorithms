#include"Graph.h"

Graph::Graph(){}

void Graph::map()
{
	
	// Add nodes in no particular order with their titles and cost to LEAVE.
	// So to declare a node "Shop" which has a uniform 2 for each exit,
	// Node Shop("Shop", 2, 2, 2, 2);
	// Then add their neighbour nodes by using pointers
	// to other nodes,
	// [North], [East], [South], [West]
	// Shop.setNeighbours(&North, &East, &South, &West);
	Node Empty("Empty", NULL, NULL, NULL, NULL);
	Node Doom("DOOM", NULL, NULL, NULL, NULL);
	Node Entrance("Entrance", 2, NULL, NULL, NULL);
	Node IceBox("Ice Box", 10, NULL, NULL, NULL);
	Node GuardRoom("Guard Room", 2, 1, NULL, NULL);
	Node DampCavern("Damp Cavern", 1, 2, 2, 1);
	Node Kitchen("Kitchen", 1, 1, 2, 2);
	Node Larder("Larder", 1, NULL, 10, 1);
	Node Barracks("Barracks", NULL, NULL, 2, NULL);
	Node WellRoom("Well Room", NULL, NULL, 1, NULL);
	Node GreatHall("Great Hall", 2, 4, 1, 2);
	Node BottleRoom("Bottle Room", NULL, NULL, 2, 2);
	Node TrollsRoom("Troll's Room", 1, 3, 2, NULL);
	Node MysteriousRoom("Mysterious Room", 3, NULL, 4, 3);
	Node Library("Library", NULL, 3, 1, NULL);

	// Store these nodes in a vector of nodes. This will help when displaying
	// data. Right now it's a bit messy. I might ask around
	// to see if there are any better alternatives.
	addToVector(&Entrance); addToVector(&IceBox); addToVector(&GuardRoom);
	addToVector(&DampCavern); addToVector(&Kitchen); addToVector(&Larder);
	addToVector(&Barracks); addToVector(&WellRoom); addToVector(&GreatHall);
	addToVector(&BottleRoom); addToVector(&TrollsRoom); addToVector(&MysteriousRoom);
	addToVector(&Library);

	// [North], [East], [South], [West]
	Entrance.setNeighbours(&DampCavern, &Empty, &Empty, &Empty);
	IceBox.setNeighbours(&Kitchen, &Empty, &Empty, &Empty);
	GuardRoom.setNeighbours(&Barracks, &DampCavern, &Empty, &Empty);
	DampCavern.setNeighbours(&WellRoom, &Kitchen, &Entrance, &GuardRoom);
	Kitchen.setNeighbours(&GreatHall, &Larder, &IceBox, &DampCavern);
	Larder.setNeighbours(&BottleRoom, &Empty, &Doom, &Kitchen);
	Barracks.setNeighbours(&Empty, &Empty, &GuardRoom, &Empty);
	WellRoom.setNeighbours(&Empty, &Doom, &DampCavern, &Empty);
	GreatHall.setNeighbours(&BottleRoom, &MysteriousRoom, &Kitchen, &TrollsRoom);
	BottleRoom.setNeighbours(&Empty, &Empty, &Larder, &GreatHall);
	TrollsRoom.setNeighbours(&Library, &MysteriousRoom, &GreatHall, &Empty);
	MysteriousRoom.setNeighbours(&Library, &Empty, &GreatHall, &TrollsRoom);
	Library.setNeighbours(&Empty, &MysteriousRoom, &TrollsRoom, &Empty);

	BFS(&Entrance, &MysteriousRoom);
}

void Graph::addToVector(Node* node)
{
	Nodes.push_back(node);
}

void Graph::printMap()
{
	for (int i = 0; i < Nodes.size(); i++)
	{
		Nodes[i]->getName();
		Nodes[i]->getNeighbours();
		Nodes[i]->getCostToLeave();
	}
}

// Make sure we parse a node which is the starting point and a
// node which is the end point.
void Graph::BFS(Node* start, Node* end)
{
	// Mark all nodes as not visited.
	for (int i = 0; i < size(Nodes); i++)
	{
		Nodes[i]->setVisited(false);
	}

	// Set current to start.
	current = start;

	// Make a new empty queue of Nodes
	std::list<Node*> queue;

	// Add the start node to the queue and set it as visited.
	queue.push_back(current);
	current->setVisited(true);

	// While the queue is not empty.
	while (!queue.empty())
	{
		// Dequeue the current vertex and pop it.
		current = queue.front();
		queue.pop_front();

		// For each adjacent neighbour:
		for (int i = 0; i < 4; i++)
		{
			// If the neighbour is not visited:
			if (current->getNorth()->getVisited() == false)
			{
				// Get the North neighbour and push it to the
				// back of the queue.
				queue.push_back(current->getNorth());
				// Set the North neighbour as visited.
				current->getNorth()->setVisited(true);
				std::cout << "My CURRENT location is: " << std::endl; current->getName();
				std::cout << std::endl;
				std::cout << "To the North is: ";
				current->getNorth()->getName();
				std::cout << std::endl;
			}
			if (current->getEast()->getVisited() == false)
			{
				// Get the East neighbour and push it to the
				// back of the queue.
				queue.push_back(current->getEast());
				// Set the East neighbour as visited.
				current->getEast()->setVisited(true);
				std::cout << "My CURRENT location is: " << std::endl; current->getName();
				std::cout << std::endl;
				std::cout << "To the East is: ";
				current->getEast()->getName();
				std::cout << std::endl;
			}
			if (current->getSouth()->getVisited() == false)
			{
				// Get the South neighbour and push it to the
				// back of the queue.
				queue.push_back(current->getSouth());
				// Set the South neighbour as visited.
				current->getSouth()->setVisited(true);
				std::cout << "My CURRENT location is: " << std::endl; current->getName();
				std::cout << std::endl;
				std::cout << "To the South is: ";
				current->getSouth()->getName();
				std::cout << std::endl;
			}
			if (current->getWest()->getVisited() == false)
			{
				// Get the West neighbour and push it to the
				// back of the queue.
				queue.push_back(current->getWest());
				// Set the West neighbour as visited.
				current->getWest()->setVisited(true);
				std::cout << "My CURRENT location is: " << std::endl; current->getName();
				std::cout << std::endl;
				std::cout << "To the West is: ";
				current->getWest()->getName();
				std::cout << std::endl;
			}
		}
		// If the current node is the end node:
		if (current == end)
		{
			// Break the loop and return.
			return;
		}
	}
}

Graph::~Graph(){}