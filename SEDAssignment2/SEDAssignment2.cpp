// SEDAssignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


//Animal Class
class Animal
{
public:
	Animal();										//Default Constructor
	Animal(string name, int age);					//Overloading Constructor
	string GetName();								//Getter function for Name
	void SetName(string name);						//Setter function for Name
	int GetAge();									//Getter function for Age
	void SetAge(int age);							//Setter function for Age
	virtual void Speak();							//Virtual function of Speak to be overriden later
protected:
	string Name;									//Name property
	int Age;										//Age property
};

Animal::Animal(string name, int age)				//Overloading constructor function
{
	Name = name;
	Age = age;
}

Animal::Animal()									//Default constructor function
{
	Name = "Default Name";
	Age = 0;
}

string Animal::GetName()							//Getter function for Name
{
	return this->Name;
}

void Animal::SetName(string name)					//Setter function for Name
{
	this->Name = name;
}

int Animal::GetAge()								//Getter function for Age
{
	return this->Age;
}

void Animal::SetAge(int age)						//Setter function for Age
{
	this->Age = age;
}

void Animal::Speak()								//Default Speak function
{
	cout << "Hello World" << endl;
}


//Dog Class
class Dog :public Animal
{
public:
	Dog(string name, int age);						//Dog constructor
	void Speak() override;							//Overrides the default Speak function from Animal class
	virtual void Action();							//Virtual function of Action to be overriden later
};

Dog::Dog(string name, int age) :Animal(name, age)	//Dog constructor function
{													//Inherits constructor from Animal class
	//Empty
}

void Dog::Speak()									//New function method for overidden Speak function
{
	cout << "Bow wow" << endl;
}

void Dog::Action()									//Default method for Action function
{
	cout << "The dog meows" << endl;
}


//PetDog Class
class PetDog : public Dog
{
public:
	PetDog(string name, int age);					//PetDog constructor
	void Action() override;							//Overrides the default Action function from Dog class
};

PetDog::PetDog(string name, int age) :Dog(name, age)//PetDog constructor function
{													//Inherits constructor from Deg class
	//Empty
}

void PetDog::Action()								//New function method for overriden Action function
{
	cout << "Fetch a stick" << endl;
}


//StrayDog Class
class StrayDog :public Dog
{													
public:
	StrayDog(string name, int age);					//Dog constructor function
	void Speak() override;							//Overrides the default Speak function from Animal class
	void Action() override;							//Overrides the default Action function from Dog class
};

StrayDog::StrayDog(string name, int age):Dog(name, age)
{
	//Empty
}

void StrayDog::Speak()								//New function method for overriden Speak function
{
	cout << "woof woof" << endl;
}

void StrayDog::Action()								//New function method for overriden Action function
{
	cout << "chase cars" << endl;
}


//Cat Class
class Cat :public Animal
{
public:
	Cat(string name, int age);
	void Speak() override;
};

Cat::Cat(string name, int age):Animal(name, age)
{
	//Empty
}

void Cat::Speak()
{
	cout << "Meow meow" << endl;
}

int main()
{
	Animal* animalArray[7];							//Declare an array of the Animal pointer type

	Animal animalVariable = Animal("Animal", 1);
	Animal* animal = &animalVariable;				//Declare object pointers
	Cat catVariable = Cat("Cat", 2);
	Cat* cat = &catVariable;
	Dog dogVariable = Dog("Dog", 3);
	Dog* dog = &dogVariable;
	PetDog petDogVariable = PetDog("PetDog", 4);
	PetDog* petDog = &petDogVariable;
	StrayDog strayDogVariable = StrayDog("StrayDog", 5);
	StrayDog* strayDog = &strayDogVariable;

	animalArray[0] = animal;						//Assign objects into array
	animalArray[1] = cat;
	animalArray[2] = dog;
	animalArray[3] = petDog;
	animalArray[4] = strayDog;

	for (int i = 0; i < 5; i++)						//Loop through the Speak functions of the objects that were pointed to
	{
		animalArray[i]->Speak();
		cout << animalArray[i]->GetName() << endl;
	}

	system("pause");
    return 0;
}

