#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
	private:
		string name;
		string color;
		string diet;
		string habitat;
		string sounds;
		bool isPet;
		int age;
		double weight;
		double height;
	public:
		Animal();
		Animal(string,string,string,string,string,bool,int,double,double);
		Animal(const Animal &);
		string getName() const;
		string getColor() const;
		string getDiet() const;
		string getHabitat() const;
		string getSounds() const;
		bool getIsPet() const;
		int getAge() const;
		double getWeight() const;
		double getHeight() const;
		void setName(string);
		void setColor(string);
		void setDiet(string);
		void setHabitat(string);
		void setSounds(string);
		void setIsPet(bool);
		void setAge(int);
		void setWeight(double);
		void setHeight(double);
		virtual void printInfo() const;
		bool operator<(const Animal& other) const;
};