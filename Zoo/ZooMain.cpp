#include "Zoo.h"

int main() {
    cout << "----- Zoo Simulation -----\n";

    // Create a Zoo
    Zoo myZoo("Fikri Zoo");

    // Create animals
    Bird parrot("Polly", "Green", "Herbivore", "Rainforest", "Squawk", true, 3, 1.2, 0.3, 0.5);
    Mammal tiger("Tony", "Orange", "Carnivore", "Jungle", "Roar", false, 5, 200.0, 1.1, "Striped");
    Reptile snake("Sly", "Brown", "Carnivore", "Desert", "Hiss", false, 2, 5.0, 0.1, "Diamond");

    // --- Test addAnimal ---
    cout << "\nAdding animals...\n";
    myZoo.addAnimal(&parrot);
    myZoo.addAnimal(&tiger);
    myZoo.addAnimal(&snake);

    // Add duplicate
    cout << "\nTrying to add duplicate animal Polly...\n";
    myZoo.addAnimal(&parrot);

    // --- Test listAnimals ---
    cout << "\nListing animals in the zoo:\n";
    myZoo.listAnimals();

    // --- Test searchAnimalByName ---
    cout << "\nSearching for 'Tony'...\n";
    int idx = myZoo.searchAnimalByName("Tony");
    if (idx != -1) cout << "Found Tony at index " << idx << "\n";
    else cout << "Tony not found\n";

    cout << "Searching for 'Ghost'...\n";
    idx = myZoo.searchAnimalByName("Ghost");
    if (idx != -1) cout << "Found Ghost at index " << idx << "\n";
    else cout << "Ghost not found\n";

    // --- Test removeAnimalByName ---
    cout << "\nRemoving 'Sly'...\n";
    myZoo.removeAnimalByName("Sly");
    myZoo.listAnimals();

    cout << "Trying to remove non-existent 'Ghost'...\n";
    myZoo.removeAnimalByName("Ghost");

    // --- Test averageAgeForType ---
    cout << "\nAverage age of Birds: " << myZoo.averageAgeForType("Bird") << "\n";
    cout << "Average age of Mammals: " << myZoo.averageAgeForType("Mammal") << "\n";
    cout << "Average age of Reptiles: " << myZoo.averageAgeForType("Reptile") << "\n";

    // --- Test predictTypeWithKNN ---
    cout << "\nTesting KNN predictions (numerical)...\n";
    vector<int> knnNum = myZoo.predictTypeWithKNN(parrot, 2, "numerical");
    cout << "Nearest neighbours (numerical indices): ";
    for (int i : knnNum) cout << i << " ";
    cout << "\n";

    cout << "Testing KNN predictions (categorical)...\n";
    vector<int> knnCat = myZoo.predictTypeWithKNN(parrot, 2, "categorical");
    cout << "Nearest neighbours (categorical indices): ";
    for (int i : knnCat) cout << i << " ";
    cout << "\n";

    // --- Test edge case: Zoo at max capacity ---
    cout << "\nFilling zoo to max capacity...\n";
    for (int i = 0; i < 50; i++) {
        string name = "Animal" + to_string(i);
        myZoo.addAnimal(new Bird(name, "Color", "Diet", "Habitat", "Sound", true, 1, 1.0, 0.5, 0.5));
    }
    cout << "Trying to add one more animal beyond capacity...\n";
    myZoo.addAnimal(new Mammal("Extra", "White", "Herbivore", "Forest", "Growl", true, 2, 10, 0.5, "Fur"));

    cout << "\n----- End of Test -----\n";
    return 0;
}