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
	InfantryUnit() : Unit("Infantry")
	{
		attack = 5;
		defense = 10;
	}
};

class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer")
	{
		attack = 10;
		defense = 5;
	}
};

class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry")
	{
		attack = 15;
		defense = 10;
	}
};

