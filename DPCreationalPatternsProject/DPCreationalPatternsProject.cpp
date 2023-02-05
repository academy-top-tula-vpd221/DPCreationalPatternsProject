#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <thread>

using namespace std;

//#include "FactoryBase.h"
//void FactoryBaseExample()
//{
//    FactoryBase factoryBase;
//    vector<Unit*> army;
//    int randId;
//    for (int i = 0; i < 10; i++)
//    {
//        randId = rand() % 3;
//        army.push_back(factoryBase.CreateUnit((UnitType)randId));
//    }
//
//    for (Unit* unit : army)
//        cout << unit->ToString() << "\n";
//}

//#include "FactoryMethod.h"
//#include "AddUnit.h"
//void FactoryMetodExample()
//{
//    vector<IFactory*> factories;
//    factories.push_back(new InfantryUnitFactory());
//    factories.push_back(new ArcherUnitFactory());
//    factories.push_back(new CavalryUnitFactory());
//    factories.push_back(new ChariotUnitFactory());
//
//    vector<Unit*> army;
//    int randId;
//    for (int i = 0; i < 10; i++)
//    {
//        randId = rand() % 3;
//        army.push_back(factories[rand() % factories.size()]->CreateUnit());
//    }
//
//    for (Unit* unit : army)
//        cout << unit->ToString() << "\n";
//}

//#include "AbstractFactory.h"
//void AbstractFactoryExample()
//{
//	class Army
//	{
//		string name;
//	public:
//		Army(string name) : name{ name } {}
//
//		vector<InfantryUnit*> infantries;
//		vector<ArcherUnit*> archers;
//		vector<CavalryUnit*> cavalries;
//		vector<UniqueUnit*> uniquies;
//
//		void Show()
//		{
//			cout << "===== Army: " << name << " =====\n";
//			cout << "Infantry:\n";
//			for (auto item : infantries) cout << item->ToString() << "\n";
//			cout << "Archers:\n";
//			for (auto item : archers) cout << item->ToString() << "\n";
//			cout << "Cavalry:\n";
//			for (auto item : cavalries) cout << item->ToString() << "\n";
//			cout << "Unique:\n";
//			for (auto item : uniquies) cout << item->ToString() << "\n";
//		}
//		~Army()
//		{
//			for (auto item : infantries) delete item;
//			for (auto item : archers) delete item;
//			for (auto item : cavalries) delete item;
//			for (auto item : uniquies) delete item;
//		}
//	};
//
//	class ArmyFactory
//	{
//		IUnitAbstractFactory* factory;
//	public:
//
//		IUnitAbstractFactory*& Factory() { return factory; }
//
//		Army* Create(string name,
//			int iCount = 10,
//			int aCount = 7,
//			int cCount = 5,
//			int uCount = 3)
//		{
//			Army* army = new Army(name);
//			for (int i = 0; i < iCount; i++)
//				army->infantries.push_back((InfantryUnit*)factory->CreateInfantryUnit());
//			for (int i = 0; i < aCount; i++)
//				army->archers.push_back((ArcherUnit*)factory->CreateArcherUnit());
//			for (int i = 0; i < cCount; i++)
//				army->cavalries.push_back((CavalryUnit*)factory->CreateCavalryUnit());
//			for (int i = 0; i < uCount; i++)
//				army->uniquies.push_back((UniqueUnit*)factory->CreateUniqueUnit());
//
//			return army;
//		}
//	};
//
//	ArmyFactory armyFactory;
//
//	armyFactory.Factory() = new UnitRomeFactory();
//	Army* armyRome = armyFactory.Create("Legion 9");
//
//	armyFactory.Factory() = new UnitCarthageFactory();
//	Army* armyCarthagen = armyFactory.Create("Falanga25");
//
//	armyRome->Show();
//	cout << "\n";
//	armyCarthagen->Show();
//}
//

//#include "Builder.h"
//void BuilderExample()
//{
//	UnitBuilder* builder = new UnitBuilder();
//
//
//	Unit* unit1 = builder->AddBaseWeapon("Crossbow")
//		->AddBaseDefense("Shield")
//		->GetUnit();
//
//	cout << unit1->ToString() << "\n";
//
//	Unit* unit2 = builder->SetNew()
//		->AddBaseWeapon("Sword")
//		->AddBaseDefense("Shield")
//		->AddOptWeapon("Dagger")
//		->AddOptWeapon("Darts")
//		->AddOptDefense("Hauberk")
//		->GetUnit();
//
//	cout << unit2->ToString() << "\n";
//
//
//	Unit* unit3 = (new InfantryUnitDirector())->GetInfantryArmed();
//	cout << unit3->ToString() << "\n";
//}

//void PrototypeExample()
//{
//	class StoreClones
//	{
//		std::map<UnitType, IUnitClonable*> clones;
//	public:
//
//		IUnitClonable* GetClone(UnitType type)
//		{
//			auto it = clones.find(type);
//			if (it != clones.end())
//				return it->second->Clone();
//
//			IFactory* factory = nullptr;
//			switch (type)
//			{
//			case UnitType::Infantry:
//				factory = new InfantryUnitFactory();
//				break;
//			case UnitType::Archer:
//				factory = new ArcherUnitFactory();
//				break;
//			case UnitType::Cavalry:
//				factory = new CavalryUnitFactory();
//				break;
//			default:
//				break;
//			}
//
//			auto unitClone = (IUnitClonable*)factory->CreateUnit();
//			auto data = std::make_pair(type, unitClone);
//
//			clones.insert(data);
//
//			return unitClone;
//		}
//
//	};
//
//	class Army
//	{
//		string title;
//		vector<InfantryUnit*> infantries;
//		vector<ArcherUnit*> archers;
//		vector<CavalryUnit*> cavalries;
//
//	public:
//
//		Army(string title, int iCount, int aCount, int cCount)
//			: title{ title }
//		{
//			IFactory* factory;
//			factory = new InfantryUnitFactory();
//			for (int i = 0; i < iCount; i++)
//				infantries.push_back((InfantryUnit*)factory->CreateUnit());
//			delete factory;
//
//			factory = new ArcherUnitFactory();
//			for (int i = 0; i < aCount; i++)
//				archers.push_back((ArcherUnit*)factory->CreateUnit());
//			delete factory;
//
//			factory = new CavalryUnitFactory();
//			for (int i = 0; i < cCount; i++)
//				cavalries.push_back((CavalryUnit*)factory->CreateUnit());
//			delete factory;
//		}
//
//
//		Army(int iCount, int aCount, int cCount, string title)
//		{
//			StoreClones store;
//			for (int i = 0; i < iCount; i++)
//				infantries.push_back((InfantryUnit*)store.GetClone(UnitType::Infantry));
//			for (int i = 0; i < aCount; i++)
//				archers.push_back((ArcherUnit*)store.GetClone(UnitType::Archer));
//			for (int i = 0; i < cCount; i++)
//				cavalries.push_back((CavalryUnit*)store.GetClone(UnitType::Cavalry));
//		}
//
//		~Army()
//		{
//			/*for (int i = 0; i < infantries.size(); i++)
//				delete infantries[i];
//			for (int i = 0; i < archers.size(); i++)
//				delete archers[i];
//			for (int i = 0; i < cavalries.size(); i++)
//				delete cavalries[i];*/
//			infantries.clear();
//			archers.clear();
//			cavalries.clear();
//
//		}
//
//		void PrintConsole()
//		{
//			cout << "Army: " << title << "\n";
//			for (int i = 0; i < infantries.size(); i++)
//				cout << "\t" << infantries[i]->ToString() << "\n";
//			for (int i = 0; i < archers.size(); i++)
//				cout << "\t" << archers[i]->ToString() << "\n";
//			for (int i = 0; i < cavalries.size(); i++)
//				cout << "\t" << cavalries[i]->ToString() << "\n";
//		}
//	};
//
//	const auto start1 = std::chrono::steady_clock::now();
//	Army army1("army1", 1000, 1000, 1000);
//	//army1.PrintConsole();
//	const auto end1 = std::chrono::steady_clock::now();
//	cout << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << "\n";
//
//
//	const auto start2 = std::chrono::steady_clock::now();
//	Army army2(1000, 1000, 1000, "army2");
//	//army2.PrintConsole();
//	const auto end2 = std::chrono::steady_clock::now();
//	cout << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << "\n";
//
//}

//#include "Singleton.h"
//void ComputerLanch(string name)
//{
//	Computer* computer = new Computer();
//	computer->Launch(name);
//	cout << computer->OS()->Name() << "\n";
//}
//void SingletonExample()
//{
//	/*Singleton* singleton = Singleton::Instance();
//	cout << singleton << "\n";
//	Singleton* singleton2 = Singleton::Instance();
//	cout << singleton2 << "\n";
//
//	delete singleton;*/
//
//	/*Computer* computer = new Computer();
//	computer->Launch("Windows 10");
//	cout << computer->OS()->Name() << "\n";
//
//	computer->Launch("Linux");
//	cout << computer->OS()->Name() << "\n";
//
//	computer->OS() = OS::GetOS("macOS");
//	cout << computer->OS()->Name() << "\n";*/
//
//	thread th1(ComputerLanch, "Windows 10");
//	thread th2(ComputerLanch, "Linux");
//
//	th1.join();
//	th2.join();
//}



int main()
{
    srand(time(nullptr));

	
}
