/*
* Factory Method
* A creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.
*
*/

#include <iostream>
#include <string>
using namespace std;

// This is the interface of a Product, that should be the parent of every new product
class Product {
public:
  virtual ~Product (){}
  virtual string doSomething() const = 0;
};

// Each Product class place the parent methods as needed
class ConcreteProduct1 : public Product {
public:
  string doSomething () const override {
    return "Operation of Concrete Product 1";
  }
};

class ConcreteProduct2 : public Product {
public:
  string doSomething() const override {
    return "Operation of Concrete Product 2";
  }
};

// Creator class is the interface that every concrete creator should use
class Creator {
public:
  virtual ~Creator(){}
  virtual Product* FactoryMethod() const = 0;

  string creatorOperation() const {
    Product* product = this->FactoryMethod();
    return product->doSomething();
  }
};

class ConcreteCreator1 : public Creator {
public:
  Product*  FactoryMethod() const override {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator {
public:
  Product*  FactoryMethod() const override {
    return new ConcreteProduct2();
  }
};


// Aplicabilidad

void ClientCode (const Creator & creator ) {
  cout << "This is the client Code" << endl;
  cout << creator.creatorOperation() << endl;
}

int main () {
  Creator* creator = new ConcreteCreator1();
  ClientCode(*creator);

  Creator* creator2 = new ConcreteCreator2();
  ClientCode(*creator2);
  return 0;
}
