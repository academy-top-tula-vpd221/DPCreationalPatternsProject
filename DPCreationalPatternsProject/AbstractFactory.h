#pragma once
#include <iostream>
#include <vector>
# include "NationalUnit.h"

class IUnitAbstractFactory
{
public:
	virtual Unit* CreateInfantryUnit() = 0;
	virtual Unit* CreateArcherUnit() = 0;
	virtual Unit* CreateCavalryUnit() = 0;
	virtual Unit* CreateUniqueUnit() = 0;
};

class UnitRomeFactory : public IUnitAbstractFactory
{
	Unit* CreateInfantryUnit() override {
		return new InfantryUnitRome();
	}
	Unit* CreateArcherUnit() override {
		return new ArcherUnitRome();
	}
	Unit* CreateCavalryUnit() override {
		return new CavalryUnitRome();
	}
	Unit* CreateUniqueUnit() override {
		return new ChariotUnitRome();
	}
};

class UnitCarthageFactory : public IUnitAbstractFactory
{
	Unit* CreateInfantryUnit() override {
		return new InfantryUnitCarthage();
	}
	Unit* CreateArcherUnit() override {
		return new ArcherUnitCarthage();
	}
	Unit* CreateCavalryUnit() override {
		return new CavalryUnitCarthage();
	}
	Unit* CreateUniqueUnit() override {
		return new ElephantUnitCarthage();
	}
};



