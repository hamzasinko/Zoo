#pragma once
#include "Animal.h"

class Reptile : public Animal
{
	private:
		string scalePattern;
	public:
		Reptile();
		Reptile(string, string, string, string, string, bool, int, double, double, string);
		Reptile(const Reptile &);
		string getScalePattern() const;
		void setScalePattern(string);
		void printInfo() const override;
};