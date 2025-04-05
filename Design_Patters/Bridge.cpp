/*
* Bridge - Desing Pattern
*
* This is a C++ implementation of the Bridge design pattern.
* The Bridge pattern is used to separate an abstraction from its implementation,
* allowing them to vary independently.
*/

#include <iostream>
#include <string>

using namespace std;

class Implementation {
public:
  virtual ~Implementation(){}
  virtual string OperationImplementation() const = 0;
};

class ConcreteImplementation : public Implementation{
public:
  string OperationImplementation() const override {
    return "Operation of Concrete Implementation 1";
  }
};


class ConcreteImplementation2 : public Implementation{
public:
  string OperationImplementation() const override {
    return "Operation of Concrete Implementation 2";
  }
};

class Abstraction {
protected:
  Implementation* implementation_;

public:
  Abstraction(Implementation* implementation): implementation_(implementation) {}

  virtual ~Abstraction(){}

  virtual string Operation () const {
    return "Abstraction: Base operation with: " + this->implementation_->OperationImplementation();
  }
};

class ExtendedAbstraction : public Abstraction {
public:
  ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation){}

  string Operation () const override {
    return "Extended Abstraction: operation with: " + this->implementation_->OperationImplementation();
  }
};

void ClientCode(const Abstraction& abstraction) {
  cout << abstraction.Operation();
}

int main () {
  Implementation * implementation = new ConcreteImplementation;
  Abstraction * abstraction = new Abstraction(implementation);
  ClientCode(*abstraction);

  return 0;
}
