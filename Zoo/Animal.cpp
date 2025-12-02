#include "Animal.h"

Animal::Animal():name("Flash"), color("black"), diet("Carnivore"), 
				habitat("Mountains"), sounds("unknown"), isPet(false),
				age(9), weight(9.9), height(1.8){}

Animal::Animal(string name, string color, string diet,
	string habitat, string sounds, bool isPet,
	int age, double weight, double height):name(name), color(color), diet(diet),
	habitat(habitat), sounds(sounds), isPet(isPet),
	age(age), weight(weight), height(height) {}

Animal::Animal(const Animal& animal):name(animal.name), color(animal.color), diet(animal.diet),
	habitat(animal.habitat), sounds(animal.sounds), isPet(animal.isPet),
	age(animal.age), weight(animal.weight), height(animal.height) {}

string Animal::getName() const
{
	return name;
}

string Animal::getColor() const
{
	return color;
}

string Animal::getDiet() const
{
	return diet;
}

string Animal::getHabitat() const
{
	return habitat;
}

string Animal::getSounds() const
{
	return sounds;
}

bool Animal::getIsPet() const
{
	return isPet;
}

int Animal::getAge() const
{
	return age;
}

double Animal::getWeight() const
{
	return weight;
}

double Animal::getHeight() const
{
	return height;
}

void Animal::setName(string name) {this->name = name;}

void Animal::setColor(string color) { this->color = color;}

void Animal::setDiet(string diet) { this->diet = diet; }

void Animal::setHabitat(string habitat) { this->habitat = habitat; }

void Animal::setSounds(string sounds) { this->sounds = sounds; }

void Animal::setIsPet(bool isPet) { this->isPet = isPet;}

void Animal::setAge(int age) { this->age = age;}

void Animal::setWeight(double weight) { this->weight = weight; }

void Animal::setHeight(double height) { this->height = height; }

void Animal::printInfo() const
{
	cout << "Animal of unkown type:" << endl;
	cout << "Name : " << name << endl;
	cout << "Color : " << color << endl;
	cout << "Diet : " << diet << endl;
	cout << "Habitat : " << habitat << endl;
	cout << "Age : " << age << "'s old" << endl;
	cout << "Is Pet : " << (isPet ? "this animal is a pet" : "this animal is not a pet") << endl;
	cout << "Weight : " << weight << "kg" << endl;
	cout << "Height : " << height << "cm" << endl;
}
bool Animal::operator<(const Animal& other) const
{
	return this->name < other.name;
}
