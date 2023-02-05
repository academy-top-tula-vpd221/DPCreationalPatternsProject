#pragma once
#include "UnitsBase.h"

class IFactory
{
public:
	virtual Unit* CreateUnit() = 0;
	virtual ~IFactory() {}
};

class InfantryUnitFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new InfantryUnit();
	}
};

class ArcherUnitFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new ArcherUnit();
	}
};

class CavalryUnitFactory : public IFactory
{
public:
	Unit* CreateUnit() override
	{
		return new CavalryUnit();
	}
};

