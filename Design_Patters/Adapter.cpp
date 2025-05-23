/*
* Adapter
*
* Structural Desing Pattern that allows colaboration between objects with incompatible interfaces.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Domain-specific interface used by the client cde.
class Target {
public:
  virtual ~Target () = default;

  virtual string Request() const {
    return "Target: Default target Behavior";
  }
};

class Adaptee {
public:
  string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

// Adapter makes Adaptee interface compatible with target
class Adapter : public Target {
private:
  Adaptee * adaptee_;
public:
  Adapter(Adaptee * adaptee): adaptee_(adaptee) {}

  string Request() const override {
    string to_reverse = this->adaptee_->SpecificRequest();
    reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }
};

void ClientCode (const Target* target) {
  cout << target->Request();
}

int main () {
  cout << "Client: I can work just fine with the Target objects:\n";
  Target *target = new Target;
  ClientCode(target);
  cout << "\n\n";
  Adaptee *adaptee = new Adaptee;
  cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
  cout << "Adaptee: " << adaptee->SpecificRequest();
  cout << "\n\n";
  cout << "Client: But I can work with it via the Adapter:\n";
  Adapter *adapter = new Adapter(adaptee);
  ClientCode(adapter);
  cout << "\n";

  delete target;
  delete adaptee;
  delete adapter;

  return 0;
}
