/**
* Last K Lines:
* Write a method to print the last K lines of an input file using C++.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> LastKLines (string fileName, int k) {
  vector<string> KLines;
  ifstream file (fileName);

  string line;
  if (file.is_open()) {
      while (getline(file, line)) {
        KLines.push_back(line);
      }
      file.close();
  } else {
      cerr << "Unable to open file!" << endl;
  }

  while (k < KLines.size()) {
    KLines.erase(KLines.begin());
  }

  return KLines;
}

int main () {

  vector<string> result = LastKLines("text.txt", 3);

  for (string s : result) {
    cout << s << endl;
  }


  return 0;
}
