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
	Node Empty("Empty", 0, 0, 0, 0);
	Node Doom("DOOM", 0, 0, 0, 0);
	Node Entrance("Entrance", 2, 0, 0, 0);
	Node IceBox("Ice Box", 10, 0, 0, 0);
	Node GuardRoom("Guard Room", 2, 1, 0, 0);
	Node DampCavern("Damp Cavern", 1, 2, 2, 1);
	Node Kitchen("Kitchen", 1, 1, 2, 2);
	Node Larder("Larder", 1, 0, 10, 1);
	Node Barracks("Barracks", 0, 0, 2, 0);
	Node WellRoom("Well Room", 0, 0, 1, 0);
	Node GreatHall("Great Hall", 2, 4, 1, 2);
	Node BottleRoom("Bottle Room", 0, 0, 2, 2);
	Node TrollsRoom("Troll's Room", 1, 3, 2, 0);
	Node MysteriousRoom("Mysterious Room", 3, 0, 4, 3);
	Node Library("Library", 0, 3, 1, 0);

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


Graph::~Graph(){}