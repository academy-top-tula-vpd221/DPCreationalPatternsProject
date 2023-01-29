#pragma once
#include <string>
class Unit
{
protected:
	std::string name;
	int attack;
	int defense;
public:
	Unit(std::string name = "") 
		: name{ name }, attack{}, defense{} {};
	
	std::string ToString() { return name; }
};

