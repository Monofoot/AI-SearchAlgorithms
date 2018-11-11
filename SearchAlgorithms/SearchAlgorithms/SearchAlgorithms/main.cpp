#include<iostream>
#include<vector>
#include"Node.h"

int main()
{
	Node Node1("Test");
	Node Node2("SecondTest");
	Node2.setCostToVisit(2);
	Node Node3("ThirdTest");
	Node3.setCostToVisit(3);
	Node Node4("FourthTest");
	Node4.setCostToVisit(7);
	Node Node5("FifthTest");
	Node5.setCostToVisit(4);
	Node1.testExists();
	Node1.setNeighbours(&Node2, &Node3, &Node4, &Node5);
	Node1.getNeighbours();
	Node1.getCostToVisit(&Node4);
}