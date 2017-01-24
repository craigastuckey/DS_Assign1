// Craig Stuckey, Devonte Walls
// Due Date: January 30th
// Programming Assignment Number 1
// Spring 2017 - CS 3358 - Section 3
//
// Instructor: Husain Gholoom
//
// This program accepts an integer between 0 and 200 from the user and performs
// multiple operations on that integer

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void CoinCalculation(int);
void AgeCalculation(int);
//void DigitSeperation(int);
//void ArmstrongNumber(int);
//void FactorialCalculation(int);
//void PrimeCalculation(int);
//void HailstoneSequence(int);

int main() {
  int value;      // value entered by user
  char repeat = 'n';    // stores user's choice to run program again
  bool valid = false;   // variable for checking user input validity

  do {
    do {
      cout << endl << "Please enter a number between 0 and 200: ";
      cin >> value;
      cin.clear();
      cin.ignore(120, '\n');
      cout << endl;

      if(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Error: input must be an integer" << endl;
      }

      else if(value < 1 || value > 199) {
        cout << "Error: input must be between 0 and 200" << endl;
      }

      else
        valid = true;
    }
    while(!valid);
    cout << endl;

    CoinCalculation(value);

    cout << endl << "Would you like to run the program again? (y/n): ";
    cin >> repeat;
  }
  while(repeat == 'y' || repeat == 'Y');

  return 0;
}

void CoinCalculation(int value) {
  int quarters = value * 4;
  int dimes = value * 10;
  int nickles = value * 20;
  long int pennies = value * 100;
  
  cout << "********Coin Calculation********" << endl << endl;

  cout << "$" << setw(5) << left << value;
  cout << "is equivalent to:" << endl << endl;

  cout << setw(6) << left << quarters;
  cout << "quarters" << endl; 
  
  cout << setw(6) << left << dimes;
  cout << "dimes" << endl;
  
  cout << setw(6) << left << nickles;
  cout << "nickles" << endl;
  
  cout << setw(6) << left << pennies;
  cout << "pennies" << endl << endl;

  AgeCalculation(value);

  return 0;
}

void AgeCalculation(int value) {
  int months = value * 12;
  int weeks = value * 52;
  int days = value * 365;
  int hours = value * 8760;
  long int minutes = value * 525600;
  long int seconds = value * (525600 * 60);

  cout << "********Age Calculation********" << endl << endl;

  cout << "You have lived: " << endl << endl;

  cout << months << " months" << endl;
  cout << weeks << " weeks" << endl;
  cout << days << " days" << endl;
  cout << hours << " hours" << endl;
  cout << minutes << " minutes" << endl;
  cout << seconds << " seconds" << endl << endl;

//  DigitSeperation(value);

  return;

}
