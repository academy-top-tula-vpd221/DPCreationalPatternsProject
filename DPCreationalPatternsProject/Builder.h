#pragma once
#include <vector>
#include "Unit.h"

class ArmedUnit : public Unit
{
	string baseWeapon;
	vector<string> optWeapon;
	string baseDefense;
	vector<string> optDefense;
public:
	string& BaseWeapon() { return baseWeapon; }
	vector<string>& OptWeapon() { return optWeapon; }
	string& BaseDefense() { return baseDefense; }
	vector<string>& OptDefense() { return optDefense; }

	string ToString() override
	{
		string str = Unit::ToString() + "\n";
		str += "\tWeapon: base [" + baseWeapon + "]\n\t\toptinal [";
		for (string w : optWeapon)
			str += w + ", ";
		str += "]\n\tDefense: base [" + baseDefense + "]\n\t\toptinal [";
		for (string d : optDefense)
			str += d + ", ";
		str += "]\n";

		return str;
	}
};

class UnitBuilder
{
protected:
	ArmedUnit* unit;
public:
	UnitBuilder() : unit{ new ArmedUnit() } {}
	virtual UnitBuilder* AddBaseWeapon(string baseWeapon)
	{
		unit->BaseWeapon() = baseWeapon;
		return this;
	}
	virtual UnitBuilder* AddOptWeapon(string optWeapon)
	{
		unit->OptWeapon().push_back(optWeapon);
		return this;
	}
	virtual UnitBuilder* AddBaseDefense(string baseDefense)
	{
		unit->BaseDefense() = baseDefense;
		return this;
	}
	virtual UnitBuilder* AddOptDefense(string optDefense)
	{
		unit->OptDefense().push_back(optDefense);
		return this;
	}

	UnitBuilder* SetNew()
	{
		delete unit;
		unit = new ArmedUnit();
		return this;
	}

	ArmedUnit* GetUnit() { return unit; }
};

class InfantryUnitDirector
{
	UnitBuilder* builder;
public:
	InfantryUnitDirector() : builder { new UnitBuilder() }{};
	Unit* GetInfantryArmed()
	{
		return builder->AddBaseWeapon("Sword")->AddBaseDefense("Shield")->GetUnit();
	}
};


