// SEDAssignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal(string name, int age);
	string GetName();
	void SetName(string name);
	int GetAge();
	void SetAge(int age);
	virtual void Speak();
protected:
	string Name;
	int Age;
};

Animal::Animal(string name, int age)
{
	Name = name;
	Age = age;
}

string Animal::GetName()
{
	return this->Name;
}

void Animal::SetName(string name)
{
	this->Name = name;
}

int Animal::GetAge()
{
	return this->Age;
}

void Animal::SetAge(int age)
{
	this->Age = age;
}

void Animal::Speak()
{
	cout << "Hello World" << endl;
}

class Dog :public Animal
{
public:
	Dog(string name, int age);
	void Speak() override;
	virtual void Action();
};

Dog::Dog(string name, int age) :Animal(name, age)
{
	//Empty
}

void Dog::Speak()
{
	cout << "Bow wow" << endl;
}

void Dog::Action()
{
	cout << "The dog meows" << endl;
}

class PetDog : public Dog
{
public:
	PetDog(string name, int age);
	void Action() override;
};

PetDog::PetDog(string name, int age) :Dog(name, age)
{
	//Fucking empty
}

void PetDog::Action()
{
	cout << "Fetch a stick" << endl;
}

class StrayDog :public Dog
{
public:
	StrayDog(string name, int age);
	void Speak() override;
	void Action() override;
};

StrayDog::StrayDog(string name, int age):Dog(name, age)
{
	//zzz....
}

void StrayDog::Speak()
{
	cout << "woof woof" << endl;
}

void StrayDog::Action()
{
	cout << "chase cars" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name, int age);
	void Speak() override;
};

Cat::Cat(string name, int age):Animal(name, age)
{
	//Looooollllll
}

void Cat::Speak()
{
	cout << "Meowther fucka" << endl;
}

int main()
{
	StrayDog someDog = StrayDog("SomeDog", 99);
	someDog.Speak();
	someDog.Action();
	system("pause");
    return 0;
}

