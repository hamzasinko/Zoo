#include "Bird.h"

Bird::Bird() : Animal(), wingSpan(0.0) {}

Bird::Bird(string name, string color, string diet,
	string habitat, string sounds, bool isPet,
	int age, double weight, double height, double wingSpan) : Animal(name, color, diet,
		habitat, sounds, isPet,
		age, weight, height), wingSpan(wingSpan) {}

Bird::Bird(const Bird& bird) : Animal(bird), wingSpan(bird.wingSpan) {}

double Bird::getWingSpan() const {return wingSpan;}

void Bird::setWingSpan(double wingSpan) { this->wingSpan = wingSpan;}

void Bird::printInfo() const
{
	cout << "Animal of type Bird:" << endl;
	cout << "Name : " << getName() << endl;
	cout << "Color : " << getColor() << endl;
	cout << "Wing span : " << wingSpan << "cm" << endl;
	cout << "Diet : " << getDiet() << endl;
	cout << "Habitat : " << getHabitat() << endl;
	cout << "Age : " << getAge() << "'s old" << endl;
	cout << "Is Pet : " << (getIsPet() ? "this animal is a pet" : "this animal is not a pet") << endl;
	cout << "Weight : " << getWeight() << "kg" << endl;
	cout << "Height : " << getHeight() << "cm" << endl;
}
