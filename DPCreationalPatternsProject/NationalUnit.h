#pragma once
#include "UnitsBase.h"

enum ArmyType
{
	Rome,
	Carthage
};

string ArmyName[]{ "Rome", "Carthage" };


// Rome Units
class InfantryUnitRome : public InfantryUnit
{
public:
	InfantryUnitRome()
	{
		this->name += " Rome";
	}
};

class ArcherUnitRome : public ArcherUnit
{
public:
	ArcherUnitRome()
	{
		this->name += " Rome";
	}
};

class CavalryUnitRome : public CavalryUnit
{
public:
	CavalryUnitRome()
	{
		this->name += " Rome";
	}
};

class ChariotUnitRome : public UniqueUnit
{
public:
	ChariotUnitRome() : UniqueUnit("Chariot Rome", 25, 20) {}
};


// Carthage Units
class InfantryUnitCarthage : public InfantryUnit
{
public:
	InfantryUnitCarthage()
	{
		this->name += " Carthage";
	}
};

class ArcherUnitCarthage : public ArcherUnit
{
public:
	ArcherUnitCarthage()
	{
		this->name += " Carthage";
	}
};

class CavalryUnitCarthage : public CavalryUnit
{
public:
	CavalryUnitCarthage()
	{
		this->name += " Carthage";
	}
};

class ElephantUnitCarthage : public UniqueUnit
{
public:
	ElephantUnitCarthage() : UniqueUnit("Elephant Carthage", 20, 25) {}
};