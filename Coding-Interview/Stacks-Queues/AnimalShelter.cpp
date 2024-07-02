/**
* Animal Shelter
*/

#include <iostream>
#include <time.h>  
#include <string>
#include <list>

using namespace std;

class Animal {
    public:
        string name;
        int order;

        Animal (string name, int order){
            this->name = name;
            this->order = order;
        }
};

class Shelter {
    int order = 0;
    list<Animal *> dogs;
    list<Animal *> cats;

    public:
        void push (int type, string name) {
            Animal * t = new Animal(name, order);
            if (type == 0) dogs.push_back(t);
            if (type == 1) cats.push_back(t);
            order++;
        }

        string popFrom (int type) {
            string result;
            if (type == 0) {
                result = dogs.front()->name;
                dogs.pop_front();
            } else {
                result = cats.front()->name;
                cats.pop_front();
            }
            return result;
        }

        string popAny () {
            if (dogs.empty() && cats.empty()) return "";
            string result;
            if (cats.empty()) {
                return this->popFrom(0);
            } else if (dogs.empty()) {
                return this->popFrom(1);
            } else if (dogs.front()->order < cats.front()->order) {
                return this->popFrom(0);
            } else {
                return this->popFrom(1);
            }
            return result;
        }

        string popCat () {
            if (cats.empty()) return "";
            string result = cats.front()->name;
            cats.pop_front();
            return result;
        }

        string popDog () {
            string result = dogs.front()->name;
            dogs.pop_front();
            return result;
        }
};


int main () {
    Shelter myShelter;
    myShelter.push(0, "Jasper");
    myShelter.push(0, "Canelita");
    myShelter.push(1, "Mewow");
    myShelter.push(1, "AristoCat");

    cout << myShelter.popAny() << endl;
    cout << myShelter.popCat() << endl;
    cout << myShelter.popDog() << endl;
    cout << myShelter.popAny() << endl;

    return 0;
}