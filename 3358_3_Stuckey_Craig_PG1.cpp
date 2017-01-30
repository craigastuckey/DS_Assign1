// Craig Stuckey, DeVante Walls
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
#include <vector>

using namespace std;

void CoinCalculation(int); //changes a dollar amount to # of different coins
void AgeCalculation(int); //calculates how many months, weeks, days, hours, 
                          //minutes and seconds lived from # of years
void DigitSeperation(int); //displays user value with digits seperated and 
                           //spelled out in english
void ArmstrongNumber(int); //sees if user entered value is an Armstrong number
void FactorialCalculation(int); //calculates factorial of user entered value
void PrimeCalculation(int); //calculates primes between 0 and user entered value
void HailstoneSequence(int); //displays hailstone sequence of user entered value

int main()
{
    int value;      // value entered by user
    char repeat = 'n';    // stores user's choice to run program again
    bool valid = false;// variable for checking user input validity

    do
    {
        do
        {
            cout << endl << "Please enter a number between 0 and 200: ";
            cin >> value;
            cin.clear();
            cin.ignore(120, '\n');
            cout << endl;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Error: input must be an integer" << endl;
            }

            else if(value < 1 || value > 199)
            {
                cout << "Error: input must be between 0 and 200" << endl;
            }

            else
                valid = true;
        }
        while(!valid);
        cout << endl;

        CoinCalculation(value);

        valid = false;

        do {
          cout << endl << "Would you like to run the program again? (y/n): ";
          cin >> repeat;
          if(repeat != 'y' && repeat != 'Y' && repeat != 'n' && repeat != 'N')
            cout << endl << "Please enter y/Y for Yes or n/N for no" << endl;
        }
        while(repeat != 'y' && repeat != 'Y' && repeat != 'n' && repeat != 'N');
    }
    while(repeat == 'y' || repeat == 'Y');

    return 0;
}

void CoinCalculation(int value)
{
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
    cout << "nickels" << endl;

    cout << setw(6) << left << pennies;
    cout << "pennies" << endl << endl;

    AgeCalculation(value);

    return;
}

void AgeCalculation(int value)
{
    long int const SEC_IN_YEAR = 31536000;
    int const MIN_IN_YEAR = 525600;
    int const HOURS_IN_YEAR = 8760;
    int const DAYS_IN_YEAR = 365;
    int const WEEKS_IN_YEAR = 52;
    int const MONTHS_IN_YEAR = 12;
    int months = value * MONTHS_IN_YEAR;
    int weeks = value * WEEKS_IN_YEAR;
    int days = value * DAYS_IN_YEAR;
    int hours = value * HOURS_IN_YEAR;
    long int minutes = value * MIN_IN_YEAR;
    long long int seconds = value * SEC_IN_YEAR;

    cout << "********Age Calculation********" << endl << endl;

    cout << "Assuming you're " << value << " years old," << endl;
    cout << "You have lived at least:" << endl << endl;

    cout << months << " months" << endl;
    cout << weeks << " weeks" << endl;
    cout << days << " days" << endl;
    cout << hours << " hours" << endl;
    cout << minutes << " minutes" << endl;
    cout << seconds << " seconds" << endl << endl;

    DigitSeperation(value);

}

void DigitSeperation(int value)
{
    int hundreds = 0;
    int tens = 0;
    int ones = 0;

    cout << "********Digit Seperation********" << endl << endl;
    cout << "Seperating digits for the integer " << value << endl;

    if(value >= 100)
    {
        hundreds = 1;
        tens = (value - 100) / 10;
        ones = (value - 100) - (10 * tens);
        cout << setw(6) << left << "1";
        cout << setw(6) << left << tens;
        cout << setw(6) << left << ones;
    }

    if(value >= 10 && value < 100)
    {
        tens = value / 10;
        ones = value - (tens * 10);
        cout << setw(6) << left << tens;
        cout << setw(6) << left << ones;
    }

    if(value < 10)
    {
        ones = value;
        cout << setw(6) << left << ones;
    }

    cout << endl;

    if(hundreds > 0)
        cout << setw(6) << left << "one";
    if(value >= 10)
    {
        switch(tens)
        {
            case 1 : cout << setw(6) << left << "one";
                     break;
            case 2 : cout << setw(6) << left << "two";
                     break;
            case 3 : cout << setw(6) << left << "three";
                     break;
            case 4 : cout << setw(6) << left << "four";
                     break;
            case 5 : cout << setw(6) << left << "five";
                     break;
            case 6 : cout << setw(6) << left << "six";
                     break;
            case 7 : cout << setw(6) << left << "seven";
                     break;
            case 8 : cout << setw(6) << left << "eight";
                     break;
            case 9 : cout << setw(6) << left << "nine";
                     break;
            default : cout << setw(6) << left << "zero";
        }
    }    
    switch(ones)
    {  
        case 1 : cout << setw(6) << left << "one";
            break;
        case 2 : cout << setw(6) << left << "two";
            break;
        case 3 : cout << setw(6) << left << "three"; 
            break;
        case 4 : cout << setw(6) << left << "four";
            break;
        case 5 : cout << setw(6) << left << "five";
            break;
        case 6 : cout << setw(6) << left << "six";
            break;
        case 7 : cout << setw(6) << left << "seven";
            break;
        case 8 : cout << setw(6) << left << "eight";
            break;
        case 9 : cout << setw(6) << left << "nine";
            break;
    }
    

    cout << endl << endl;

    ArmstrongNumber(value);

    return;
}
void ArmstrongNumber(int value)
{

    cout << "********Armstrong Number Calculation********" << endl << endl;

    vector<int> digits(10); //An integer can only ever be 10 digits in length

    int count = 0;
    int mutatedValue = value;

    while(mutatedValue != 0)
    {
        digits[count++] = mutatedValue % 10;
        mutatedValue /= 10;
    }

    int sumOfCubes = 0;

    for(int i = 0; i < count; i++)
        sumOfCubes += digits[i] * digits[i] * digits[i];

    bool isArmstrongNumber = (sumOfCubes == value);

    cout << "The sum of the cubes is: " << sumOfCubes << endl;
    cout << "Since " << sumOfCubes << " is ";
    cout << (isArmstrongNumber ? "equal" : "not equal") << " to " << value;
    cout << ", " << value << " " << (isArmstrongNumber ? "is" : "is not");
    cout << " an Armstrong number" << endl << endl;

    PrimeCalculation(value);
}
void PrimeCalculation(int value)
{
    int size = 46;
    vector<int> primes (46);
    int count = 0;

    cout << "********Prime Calculation********" << endl << endl;

    for(int i=2; i<=value; i++)
    {
        for(int j=2; j<=i; j++)
        {
            if(i % j == 0 && j != i)break;
            if(j == i)
            {
                primes[count++] = i;
            }
        }
    }

    if(primes[count-1] == value)
        cout << value << " is a prime" << endl << endl;
    else
        cout << value << " is not a prime" << endl << endl;

    cout << "Primes between 0 and " << value << " are:" << endl;

    for(int i=0; i<count; i++)
        cout << primes[i] << " ";

    cout << endl << endl;

    FactorialCalculation(value);
}

void FactorialCalculation(int value)
{

    long long int factorial = 1;

    cout << "********Factorial Calculation********" << endl << endl;

    for(int i = 2; i <= value; i++)
    {
        factorial = factorial*i;
    }

    cout << "Factorial of " << value << " is: " << factorial << endl << endl;


    HailstoneSequence(value);
}

void HailstoneSequence(int value)
{
    /*
    3n+1 if odd, n/2 if even
    */
    cout << "********Hailstone Sequence Calculation********" << endl << endl;

    int mutatedValue = value;

    while(mutatedValue != 1)
    {
        cout << mutatedValue << " ";

        if(mutatedValue % 2 != 0)
            mutatedValue = (mutatedValue * 3) + 1;
        else
            mutatedValue /= 2;
    }

    cout << 1 << endl << endl;
}
