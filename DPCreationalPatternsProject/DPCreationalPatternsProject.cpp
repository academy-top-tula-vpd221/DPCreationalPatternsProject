#include <iostream>
#include <vector>

#include "FactoryBase.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    FactoryBase factoryBase;
    vector<Unit*> army;
    int randId;
    for (int i = 0; i < 10; i++)
    {
        randId = rand() % 3;
        army.push_back(factoryBase.CreateUnit((UnitType)randId));
    }

    for (Unit* unit : army)
        cout << unit->ToString() << "\n";
}
