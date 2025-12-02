#pragma once
#include "Animal.h"

class Mammal : public Animal
{
	private:
		string furColor;
	public:
		Mammal();
		Mammal(string, string, string, string, string, bool, int, double, double, string);
		Mammal(const Mammal &);
		string getFurColor() const;
		void setFurColor(string);
		void printInfo() const override;
};

