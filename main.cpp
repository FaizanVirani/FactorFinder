#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

bool validInt(string);

int main() {
  bool runAgain = false;
  
  do {
  vector<int> multiples;
  string answerHolder;
  string dummy;

  int number;
  int num1 = 0;
  int num2 = 0;
  bool found = false;

  cout << "\nEnter your number: ";
  cin >> number;
  for(num2 = 0; num2 < number; num2++) {
    for(num1 = 0; num1 < number; num1++) {
      if(num1*num2 == number) {
        for(int i = 0; i < multiples.size(); i++) {
          if (multiples[i] == num1) {
            found = true;
          }
        }
        if(!found) {
          multiples.push_back(num1);
          multiples.push_back(num2);
        }
      }
    }
  }

    for(int i = 0; i < multiples.size(); i+=2) {
      cout << endl << multiples[i] << " and " << multiples[i + 1];
    }
    getline(cin, dummy);
    do {
    cout << "\n\nWould you like to view another item? \n1) Yes\n2) No\n";
    getline(cin, answerHolder);
    if (answerHolder.length() == 0) {
            answerHolder = "a";
    }
    if (validInt(answerHolder)) {
      if (stoi(answerHolder) > 2 || stoi(answerHolder) < 1) {
      cout << "\nInvalid entry.";
      answerHolder = "a";
      }
    }
  } while(!validInt(answerHolder));
  if(answerHolder == "1") {
    runAgain = true;
  } else {
    runAgain = false;
  }
  } while(runAgain);
}

bool validInt(string a) {
  for (int i = 0; i < a.length(); i++) {
    if (!isdigit(a[i])) {
      return false;
      break;
    }
  }
  return true;
}
