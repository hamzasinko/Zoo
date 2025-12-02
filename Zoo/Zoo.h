#pragma once
#include <vector>
#include "Animal.h"
#include "Bird.h"
#include "Mammal.h"
#include "Reptile.h"
#include "KNN.h"
#include "KNNString.h"
#include "KNNDouble.h"

class Zoo
{
	private:
		string name;
		static int MAX_CAPACITY;
		vector<Animal*> animals;
	public:
		Zoo();
		Zoo(string);
		Zoo(const Zoo &);
		string getName() const;
		void setName(string);
		void listAnimals() const;
		void addAnimal(Animal*);
		int searchAnimalByName(const string&) const;
		void removeAnimalByName(const string&);
		int averageAgeForType(const string&) const;
		vector<int> predictTypeWithKNN(const Animal&, int, string) const;
};

