//Not all of these need to be included, it's just the list I always go with for smaller projects. When space preservation is required, I'll only use the necessary ones.
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

bool validInt(string); //Data validation
int gcf(vector<int>); //GCF Finder

int main() {
  bool runAgain = false;

  //Do while to run again
  do {
  vector<int> factors;
  string answerHolder;

  int number;
  int num1 = 0;
  int num2 = 0;
  bool found = false;

  do {
    cout << "Enter your number: ";
    getline(cin, answerHolder);
    if (answerHolder.length() == 0) {
            answerHolder = "a";
    }
  } while(!validInt(answerHolder));
    number = stoi(answerHolder);

  for(num2 = 0; num2 < number; num2++) { //Checks every first number
    for(num1 = 0; num1 < number; num1++) { //Checks every second number
      if(num1*num2 == number) { //Condition to find factors
        for(int i = 0; i < factors.size(); i++) {
          if (factors[i] == num1) {
            found = true;
          }
        }
        if(!found) {
          factors.push_back(num1);
          factors.push_back(num2);
        }
      }
    }
  }

    if(factors.size() == 0) {
    factors.push_back(number);
    factors.push_back(1);
  }
    
    for(int i = 0; i < factors.size(); i+=2) {
      cout << endl << factors[i] << " and " << factors[i + 1]; //Prints factor pairs
    }

    for(int i = 0; i < factors.size(); i++) {
      if(factors[i] == 1) {
        cout << "\n\x1b[31mThis number is prime!\n\x1b[37m"; //Prime
        break;
      }
      if (i == factors.size() - 1) {
        cout << "\nGreatest Factor: " << *max_element(factors.begin(), factors.end()) << endl; //Finds and prints greatest factor
      }
    }
    gcf(factors);
    do {
    cout << "\nWould you like to find the factors of another number? \n1) Yes\n2) No\n";
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

bool validInt(string a) { //Error trapping
  for (int i = 0; i < a.length(); i++) {
    if (!isdigit(a[i])) {
      return false;
      break;
    }
  }
  return true;
}

int gcf(vector<int> fact) {
  string answerHolder;
  bool found = false;
  int number, num1, num2;
  vector<int> sameNumbers;
  vector<int> factors;

  do {
    cout << "\nWould you like to find the GCF of " << fact[0]*fact[1] << " and another number?\n1) Yes\n2) No\n";
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
    if (answerHolder == "2") {
      return 0;
    }
  
  do {
    cout << "Enter your number: ";
    getline(cin, answerHolder);
    if (answerHolder.length() == 0) {
            answerHolder = "a";
    }
  } while(!validInt(answerHolder));
    number = stoi(answerHolder);
    
  for(num2 = 0; num2 < number; num2++) { //Checks every first number
    for(num1 = 0; num1 < number; num1++) { //Checks every second number
      if(num1*num2 == number) { //Condition to find factors
        for(int i = 0; i < factors.size(); i++) {
          if (factors[i] == num1) {
            found = true;
            break;
          }
        }
        if(!found) {
          factors.push_back(num1);
          factors.push_back(num2);
        }
      }
    }
  }

  if(factors.size() == 0) {
    factors.push_back(number);
    factors.push_back(1);
  }
  
  for(int i = 0; i < factors.size(); i++) {
    for(int j = 0; j < factors.size(); j++) {
      if(factors[j] == fact[i]) {
        sameNumbers.push_back(fact[i]);
      }
    }
  }

  if(sameNumbers.size() == 0) {
    cout << endl << "\x1b[31mThese numbers have no GCF!\n\x1b[37m" << "------------------------------------";
  } else {
    cout << endl << "The GCF of " << fact[0]*fact[1] << " and " << factors[0]*factors[1] << " is " << *max_element(sameNumbers.begin(), sameNumbers.end()) << "\n------------------------------------";
  }
  return 0;
}
