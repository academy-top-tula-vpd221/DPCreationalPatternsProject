#pragma once
#include "UnitsBase.h"

class FactoryBase
{
public:
	Unit* CreateUnit(UnitType type)
	{
		Unit* unit = nullptr;
		switch (type)
		{
		case Infantry:
			unit = new InfantryUnit();
			break;
		case Archer:
			unit = new ArcherUnit();
			break;
		case Cavalry:
			unit = new CavalryUnit();
			break;
		default:
			unit = nullptr;
			break;
		}
		return unit;
	}
};

