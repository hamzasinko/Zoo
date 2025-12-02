# Zoo Management System in C++

## Overview

This project is a **C++ console application** simulating a Zoo Management System. It allows you to manage a collection of animals, including Birds, Mammals, and Reptiles. The application demonstrates object-oriented programming concepts such as **inheritance, polymorphism, and encapsulation**, along with practical features like searching, removing, calculating statistics, and predicting animal types using **K-Nearest Neighbors (KNN)**.

---

## Features

- **Animal Hierarchy**:  
  - `Animal` (base class)  
  - `Bird`, `Mammal`, `Reptile` (derived classes)  

- **Zoo Class**:  
  - Add and remove animals.  
  - List all animals.  
  - Search animals by name.  
  - Calculate the average age for a specific type.  
  - Predict nearest neighbours of an animal using KNN with either numerical or categorical features.  
  - Supports a maximum capacity of 50 animals.  

- **KNN Functionality**:  
  - Numerical features: `weight` and `height`.  
  - Categorical features: `color`, `diet`, `habitat`, `sounds`.  

- **Edge Cases Handled**:  
  - Duplicate animals.  
  - Animals not found during search or removal.  
  - Zoo capacity limits.
 

---

## Classes

### Animal
- Attributes: `name`, `color`, `diet`, `habitat`, `sounds`, `isPet`, `age`, `weight`, `height`.  
- Methods: Getters, setters, `printInfo()`, comparison operator `<`.  

### Bird : Animal
- Additional attribute: `wingSpan`.  
- Overrides `printInfo()`.  

### Mammal : Animal
- Additional attribute: `furColor`.  
- Overrides `printInfo()`.  

### Reptile : Animal
- Additional attribute: `scalePattern`.  
- Overrides `printInfo()`.  

### Zoo
- Attributes: `name`, `vector<Animal*> animals`, `MAX_CAPACITY`.  
- Methods:  
  - `addAnimal(Animal*)`  
  - `removeAnimalByName(const string&)`  
  - `listAnimals()`  
  - `searchAnimalByName(const string&)`  
  - `averageAgeForType(const string&)`  
  - `predictTypeWithKNN(const Animal&, int, string)`  

---

## How to Compile and Run

1. Make sure you have a **C++ compiler** supporting C++11 or higher.  
2. Compile all source files.


Author

Hamza Fikri – Computer Engineering & Networking student

Project developed as part of a C++ OOP course.
