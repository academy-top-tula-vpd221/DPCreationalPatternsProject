#pragma once
#include "FactoryMethod.h"

class ChariotUnit : public Unit
{
public:
	ChariotUnit() : Unit("Chariot")
	{
		attack = 25;
		defense = 15;
	}
	Unit* Clone()
	{
		return new ChariotUnit(*this);
	}
};

class ChariotUnitFactory : public IFactory
{
	Unit* CreateUnit() override
	{
		return new ChariotUnit();
	}
};