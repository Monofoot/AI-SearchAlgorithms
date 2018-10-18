#pragma once
#include<list>

class BFS
{
private:
	// Set all nodes as not visited.

	// Need a queue to decide which vertex to explore next.
	// Using a queue is the staple of a BFS algorithm.
	std::list<int> queue;

	// Visit the node (print its value)
	// Add the left child to queue
	// Add the right child to queue
	// Remove the node from the queue



public:
	BFS();

	~BFS();
};