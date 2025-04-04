/*
* Singleton
* 
* Due to the fact that we should just have one instance, 
* we shouldn't being able to call the new operator on the
* class.
* That is why we should have the constructor it self as a private method.
* And create an static method that could act as a constructor.
*
* This static method should call the constructor and store in an static space, so every time the 'constructor' is called, the stored object is returned.
*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

class Singleton {
private:
  static Singleton* pinstance_;
  static mutex mutex_;
protected:
  Singleton(const string value): value_(value){}
  string value_;
 
public:
  // Not clonable
  Singleton(Singleton & other) = delete;

  // Not assignable
  void operator = (const Singleton &) = delete;

  // Create the static method that simulates the constructor
  static Singleton* GetInstance (const string & value);

  void SomeLogic () {
    cout << "This code is doing some logic" << endl;
  }

  string value () const {
    return value_;
  }
};

Singleton* Singleton::pinstance_{nullptr};
mutex Singleton::mutex_;

Singleton* Singleton::GetInstance(const string & value) {
  lock_guard<mutex> lock (mutex_);
  if (pinstance_ == nullptr) {
    pinstance_ = new Singleton(value);
  }
  return pinstance_;
}

void FirstThread () {
  this_thread::sleep_for(chrono::milliseconds(1000));
  Singleton* singleton = Singleton::GetInstance("FOO");
  cout << singleton->value() << endl;
  singleton->SomeLogic();
}

void SecondThread () {
  this_thread::sleep_for(chrono::milliseconds(1000));
  Singleton* singleton2 =  Singleton::GetInstance("BAR");
  cout << singleton2->value() << endl;
  singleton2->SomeLogic();
}

int main () {

  thread t1(FirstThread);
  thread t2(SecondThread);

  t1.join();
  t2.join();

  return 0;
}

