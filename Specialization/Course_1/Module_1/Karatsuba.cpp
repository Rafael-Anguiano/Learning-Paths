#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

map<char, int>nums;

void makeStringSameLength (string & s1, string & s2) {
  if (s1.length() == s2.length()) return;

  if (s1.length() < s2.length()) {
    s1 = string(s2.length() - s1.length(), '0') + s1;
  } else {
    s2 = string(s1.length() - s2.length(), '0') + s2;
  }
}

string stringSum (string s1, string s2) {
  makeStringSameLength(s1, s2);
  int sum = 0;
  int carry = 0;
  string result = "";
  for (int i = s1.length()-1; 0 <= i; i--) {
    sum = carry + nums[s1[i]] + nums[s2[i]];
    if (sum > 9) {
      carry = 1;
      sum -= 10;
    } else {
      carry = 0;
    }
    result = to_string(sum)  + result;
  }
  if (carry) result = to_string(carry) + result;
  return result;
}

string stringSubstract (string s1, string s2) {
  makeStringSameLength(s1, s2);
  int sub = 0;
  int carry = 0;
  string result = "";
  for (int i = s1.length()-1; 0 <= i; i--) {
    sub = nums[s1[i]] - nums[s2[i]] - carry;
    if (sub < 0) {
      carry = 1;
      sub += 10;
    } else {
      carry = 0;
    }
    result = to_string(sub)  + result;
  }
  return result;
}

string appendStart(string s, int n) {
  return string(n, '0') + s;
}

string karatsuba (string s1, string s2) {
  if (s1.length() == 1 && s2.length() == 1) {
    return to_string(nums[s1[0]] * nums[s2[0]]);
  }

  if (s1.length() < s1.length()) {
    s1 = appendStart(s1, s2.length() - s1.length());
  } else {
    s2 = appendStart(s2, s1.length() - s2.length());
  }

  if (s1.length() % 2 != 0) {
    s1 = "0" + s1;
    s2 = "0" + s2;
  }

  string a = "", b = "", c = "", d = "";
  for (int i=0; i< s1.length() ; i++) {
    if (i < ceil((double)s1.length()/2)) {
      a += s1[i];
      c += s2[i];
    } else {
      b += s1[i];
      d += s2[i];
    }
  }

  string ac = karatsuba(a, c);
  string bd = karatsuba(b, d);
  string ad = karatsuba(a, d);
  string bc = karatsuba(b, c);
  string adbc = stringSum(ad, bc);
  string firstTerm = ac + string(s1.length(), '0');
  string secondTerm = adbc + string(floor(s1.length()/2),'0');
  string result = stringSum(stringSum(firstTerm, secondTerm), bd);
  return result;
}

int main () {
  nums.insert({'0', 0});
  nums.insert({'1', 1});
  nums.insert({'2', 2});
  nums.insert({'3', 3});
  nums.insert({'4', 4});
  nums.insert({'5', 5});
  nums.insert({'6', 6});
  nums.insert({'7', 7});
  nums.insert({'8', 8});
  nums.insert({'9', 9});
  string s1 = "3141592653589793238462643383279502884197169399375105820974944592";
  string s2 = "2718281828459045235360287471352662497757247093699959574966967627";
  string s3 = karatsuba(s1, s2);
  cout << s3 << endl;

  return 0;
}
