#include "Mammal.h"

Mammal::Mammal() : Animal(), furColor("Tawny"){}

Mammal::Mammal(string name, string color, string diet,
	string habitat, string sounds, bool isPet,
	int age, double weight, double height, string furColor) : Animal(name, color, diet,
		habitat, sounds, isPet,
		age, weight, height), furColor(furColor){}

Mammal::Mammal(const Mammal& mammal): Animal(mammal), furColor(mammal.furColor) {}

string Mammal::getFurColor() const {return furColor;}

void Mammal::setFurColor(string furColor) { this->furColor = furColor;}

void Mammal::printInfo() const
{
	cout << "Animal of type Mammal:" << endl;
	cout << "Name : " << getName() << endl;
	cout << "Color : " << getColor() << endl;
	cout << "Fur Color : " << furColor << endl;
	cout << "Diet : " << getDiet() << endl;
	cout << "Habitat : " << getHabitat() << endl;
	cout << "Age : " << getAge() << "'s old" << endl;
	cout << "Is Pet : " << (getIsPet() ? "this animal is a pet" : "this animal is not a pet") << endl;
	cout << "Weight : " << getWeight() << "kg" << endl;
	cout << "Height : " << getHeight() << "cm" << endl;
}