#include "Zoo.h"

int Zoo::MAX_CAPACITY = 50;

Zoo::Zoo(): name("Unnamed Zoo") {}

Zoo::Zoo(string name): name(name) {}

Zoo::Zoo(const Zoo &other): name(other.name), animals(other.animals) {}

string Zoo::getName() const {return name;}

void Zoo::setName(string name) {this->name = name;}

void Zoo::listAnimals() const
{
	cout << "Animals in " << name << ":\n";
	for (const auto& animal : animals) {
		animal->printInfo();
		cout << "---------------------\n";
	}
}

void Zoo::addAnimal(Animal* animal)
{
	for(const auto& a : animals) {
		if (a->getName() == animal->getName()) {
			cout << "Animal already exists in the zoo!\n";
			return;
		}
	}
	if (animals.size() < MAX_CAPACITY) {
		animals.insert(lower_bound(animals.begin(), animals.end(), animal->getName(),
			[](Animal* animal, const string& name) { return animal->getName() < name; }),animal);
	} else {
		cout << "Zoo is at full capacity! Cannot add more animals.\n";
	}
}

int Zoo::searchAnimalByName(const string& target) const {

	auto it = lower_bound(animals.begin(), animals.end(), target,
		[](Animal* a, const string& name) { return a->getName() < name; });

	if (it == animals.end() || (*it)->getName() != target)
		return -1;

	return (int)(it - animals.begin());
}

void Zoo::removeAnimalByName(const string& target){

	auto it = lower_bound(animals.begin(), animals.end(), target,
		[](Animal* a, const string& name) { return a->getName() < name; });

	if (it == animals.end() || (*it)->getName() != target) {
		cout << "Animal not found in the zoo!\n";
		return;
	}

	animals.erase(it);
}

int Zoo::averageAgeForType(const string& type) const {
	int totalAge = 0;
	int count = 0;

	for (const auto& animal : animals) {
		if ((type == "Mammal" && (Mammal*)(animal)) ||
			(type == "Bird" && (Bird*)(animal)) ||
			(type == "Reptile" && (Reptile*)(animal))) {
			totalAge += animal->getAge();
			count++;
		}
	}

	if (count == 0) {
		cout << "No animals of type " << type << " found in the zoo.\n";
		return 0;
	}

	return totalAge / count;
}

vector<int> Zoo::predictTypeWithKNN(const Animal& unknownAnimal, int k, string feature) const {
	vector<pair<double, double>> trainDataNum;
	vector<string> trainDataStr;

	for (const auto& animal : animals){
		
		if (feature == "numerical") {
			trainDataNum.push_back({animal->getWeight(), animal->getHeight()});
		} else if (feature == "categorical") {
			trainDataStr.push_back(animal->getColor()+" "+animal->getDiet()+" "
									+animal->getHabitat()+" "+animal->getSounds());
		} else {
			cout << "Unknown feature for KNN prediction.\n";
			return vector<int>();
		}
	}
	if (feature == "numerical") {
		KNNDouble knn(k);
		return knn.findNearestNeighbours(trainDataNum,
			{unknownAnimal.getWeight(), unknownAnimal.getHeight()});
	} else {
		KNNString knn(k);
		return knn.findNearestNeighbours(trainDataStr,
			unknownAnimal.getColor()+" "+unknownAnimal.getDiet()+" "
			+unknownAnimal.getHabitat()+" "+unknownAnimal.getSounds());
	}
}