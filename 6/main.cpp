#include <iostream>
#include <string>

using namespace std;

class Dog;

class Animal {
private:
	string type, name;
public:
	Animal() {
		this->type = "Unknown animal";
		this->name = "Unknown";
	}
	Animal(string name) {
		this->name = name;
	}

	void print() {
		cout << type <<  " named " << name << endl;
	}

	~Animal() {}
	friend class Dog;
	friend class Cat;
	friend class Parrot;
};

class Dog : public Animal {
public:
	Dog() {
		this->type = "Dog";
		this->name = "Unknown";
	}
	Dog(string name) {
		this->type = "Dog";
		this->name = name;
	}
	~Dog() {}
};

class Cat: public Animal {
public:
	Cat() {
		this->type = "Cat";
		this->name = "Unknown";
	}
	Cat(string name) {
		this->type = "Cat";
		this->name = name;
	}
	~Cat() {}
};

class Parrot : public Animal {
public:
	Parrot() {
		this->type = "Parrot";
		this->name = "Unknown";
	}
	Parrot(string name) {
		this->type = "Parrot";
		this->name = name;
	}
	~Parrot() {}
};

int main(void) {
	Dog a("Drujok");
	Cat b("Barsik");
	Parrot c("Kesha");
	a.print();
	b.print();
	c.print();
	return 0;
}