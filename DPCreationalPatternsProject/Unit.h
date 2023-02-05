#pragma once
#include <string>

using namespace std;

class Unit;

class IUnitClonable
{
public:
	virtual Unit* Clone() = 0;
};


class Unit : public IUnitClonable
{
protected:
	std::string name;
	int attack;
	int defense;
public:
	Unit(std::string name = "") 
		: name{ name }, attack{}, defense{} {};
	
	virtual std::string ToString() 
	{ 
		return "Name: " + name
			+ " [attack: " + to_string(attack) + "]"
			+ " [defese: " + to_string(defense) + "]";
	}
};

