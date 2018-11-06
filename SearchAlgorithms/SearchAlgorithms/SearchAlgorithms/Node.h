#pragma once
#include<string>

class Node
{
private:
	std::string name;
	Node *up, *down, *left, *right;
	int upCost, downCost, leftCost, rightCost;

public:
	Node();
	
	~Node();
};