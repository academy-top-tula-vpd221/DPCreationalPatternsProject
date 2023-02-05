#pragma once
#include "Unit.h"

enum UnitType
{
	Infantry,
	Archer,
	Cavalry,
};

class InfantryUnit : public Unit
{
public:
	InfantryUnit(string name = "Infantry", int attack = 5, int defense = 10) : Unit(name)
	{
		this->attack = attack;
		this->defense = defense;
	}
	Unit* Clone()
	{
		return new InfantryUnit(*this);
	}
};

class ArcherUnit : public Unit
{
public:
	ArcherUnit(string name = "Archer", int attack = 10, int defense = 10) : Unit(name)
	{
		this->attack = attack;
		this->defense = defense;
	}
	Unit* Clone()
	{
		return new ArcherUnit(*this);
	}
};

class CavalryUnit : public Unit
{
public:
	CavalryUnit(string name = "Cavalry", int attack = 15, int defense = 15) : Unit(name)
	{
		this->attack = attack;
		this->defense = defense;
	}
	Unit* Clone()
	{
		return new CavalryUnit(*this);
	}
};

class UniqueUnit : public Unit
{
public:
	UniqueUnit(std::string name, int attack, int defense) 
		: Unit(name)
	{
		this->attack = attack;
		this->defense = defense;
	}
	Unit* Clone()
	{
		return new UniqueUnit(*this);
	}
};



