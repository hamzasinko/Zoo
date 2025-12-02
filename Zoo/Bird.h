#pragma once
#include "Animal.h"

class Bird : public Animal
{
	private:
		double wingSpan;
	public:
		Bird();
		Bird(string, string, string, string, string, bool, int, double, double, double);
		Bird(const Bird &);
		double getWingSpan() const;
		void setWingSpan(double);
		void printInfo() const override;
};

