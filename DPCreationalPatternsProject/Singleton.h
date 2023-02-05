#pragma once
#include <mutex>

std::mutex m;

class Singleton
{
	static Singleton* instance;
	Singleton() {}
public:

	Singleton(const Singleton& obj) = delete;
	Singleton* operator=(const Singleton& obj) = delete;

	static Singleton* Instance()
	{
		if (!instance)
			instance = new Singleton();
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;

class OS
{
	string name;
	static OS* osInstance;
	OS(string name) : name{ name } {}
public:
	string Name() { return name; }
	static OS* GetOS(string name)
	{
		std::lock_guard<mutex> lg(m);
		if (!osInstance)
			osInstance = new OS(name);
		return osInstance;
	}
};

class Computer
{
	OS* os;
public:
	OS*& OS() { return os; }
	void Launch(string osName)
	{
		os = OS::GetOS(osName);
	}
};

OS* OS::osInstance = nullptr;