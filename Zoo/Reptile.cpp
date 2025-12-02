#include "Reptile.h"

Reptile::Reptile():scalePattern("unknown"){}

Reptile::Reptile(string name, string color, string diet,
	string habitat, string sounds, bool isPet,
	int age, double weight, double height, string scalePattern) : Animal(name, color, diet,
		habitat, sounds, isPet,
		age, weight, height), scalePattern(scalePattern) {}

Reptile::Reptile(const Reptile& reptile) : Animal(reptile), scalePattern(reptile.scalePattern) {}

string Reptile::getScalePattern() const {return scalePattern;}

void Reptile::setScalePattern(string) { this->scalePattern = scalePattern; }

void Reptile::printInfo() const
{
	cout << "Animal of type Reptile:" << endl;
	cout << "Name : " << getName() << endl;
	cout << "Color : " << getColor() << endl;
	cout << "Scale pattern : " << scalePattern << endl;
	cout << "Diet : " << getDiet() << endl;
	cout << "Habitat : " << getHabitat() << endl;
	cout << "Age : " << getAge() << "'s old" << endl;
	cout << "Is Pet : " << (getIsPet() ? "this animal is a pet" : "this animal is not a pet") << endl;
	cout << "Weight : " << getWeight() << "kg" << endl;
	cout << "Height : " << getHeight() << "cm" << endl;
}
