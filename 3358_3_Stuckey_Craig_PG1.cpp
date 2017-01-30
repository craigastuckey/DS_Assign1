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
void DigitSeparation(int); //displays user value with digits seperated and
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

    //Two do while loops with if else statements that help check if the value entered by the user
    //is actually a valid integer. Returning errors if the integer is not valid or a character is entered
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

        //Calling the CoinCalculation function
        CoinCalculation(value);

        valid = false;

        //A do while loop that asks the user if they would like to repeat the program with a different number.
        //The while portions of the loop help check if the character was entered to repeat.
        //The if loop tells the user to enter a valid number in case an integer was not entered.
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
//******************************************************************************************************
//Coin Calculation is the function that converts the user's input into dollars and then
//into various coin amounts.
//This function is called previously in the main. The function takes the user's input and multiplies
//it by the respected number of each category for quarters, pennies, nickels, and dimes.
//
//param-1- value this parameter is an int that is the user's input
//when prompted to give a number between 0-200
//returns the user input into pennies, nickels, dimes, and quarters.
//******************************************************************************************************
void CoinCalculation(int value)
{
    //Assigning Variables to their respected values
    int quarters = value * 4;
    int dimes = value * 10;
    int nickles = value * 20;
    long int pennies = value * 100;

    cout << "********Coin Calculation********" << endl << endl;

    //Outputting the dollar amount of the value entered and what the equivalent is in
    //quarters, dimes, nickels, and pennies.
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

//********************************************************************************************************
//Age Calculation is the function that converts the user's input into years and then
//calculates various times.
//The function is called previously in Coin calculation. The function takes the user input and multiplies
//the value by the given amount of time in each category.
//
//param-1- value this parameter is an int that is the user's input
//when prompted to give a number between 0-200
//returns the user input into how many years, months, weeks, days, hours, mins, and seconds
//the input is equal to.
//********************************************************************************************************
void AgeCalculation(int value)
{
    //Assigning Variables to convert input from years into months, weeks, days, hours, mins, and seconds
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

    //Below are output statements that output value multiplied by each specific variable
    cout << "********Age Calculation********" << endl << endl;

    cout << "Assuming you're " << value << " years old," << endl;
    cout << "You have lived at least:" << endl << endl;

    cout << months << " months" << endl;
    cout << weeks << " weeks" << endl;
    cout << days << " days" << endl;
    cout << hours << " hours" << endl;
    cout << minutes << " minutes" << endl;
    cout << seconds << " seconds" << endl << endl;

    //Calling the Digit Separation method
    DigitSeparation(value);

}

//**********************************************************************************************************
//Digit Separation is the function that takes the user's input value and separates the numbers.
//The separated numbers are then labeled underneath with their respective numbers. The function
//compares the input by the ones tens and hundreds places to correctly separate the numbers and label them.
//
//param-1- value this parameter is an int that is the user's input
//when prompted to give a number between 0-200
//returns the user input separated with some spaces between the numbers followed by the numbers
//spelled out on a new line.
//**********************************************************************************************************
void DigitSeparation(int value)
{
    //Declaring Variables
    int hundreds = 0;
    int tens = 0;
    int ones = 0;

    //Output statement that outputs the function we're going over and the value that has been entered
    cout << "********Digit Separation********" << endl << endl;
    cout << "Separating digits for the integer " << value << endl;

    //If statement that checks to see if value is greater than or equal to 100 for the hundreds place
    //Then gathers the hundreds place, tens place, and ones place if the number is greater than or equal to 100
    //Dividing each respectively
    if(value >= 100)
    {
        hundreds = 1;
        tens = (value - 100) / 10;
        ones = (value - 100) - (10 * tens);
        cout << setw(6) << left << "1";
        cout << setw(6) << left << tens;
        cout << setw(6) << left << ones;
    }

    //If statement that checks to see if the value is greater than or equal to 10 and less than 100 for the tens place
    //similarly to the first if statement
    if(value >= 10 && value < 100)
    {
        tens = value / 10;
        ones = value - (tens * 10);
        cout << setw(6) << left << tens;
        cout << setw(6) << left << ones;
    }

    //If statement similar to the first two, but checks if the value is equal to the ones place
    if(value < 10)
    {
        ones = value;
        cout << setw(6) << left << ones;
    }

    cout << endl;

    //If statement that checks if the hundreds place is greater than 0, if so out puts one to the left
    //Since the number is between 0 and 200 nothing can be bigger than 1
    if(hundreds > 0)
        cout << setw(6) << left << "one";

    if(value >= 10)
    {
        //Switch statement for the tens place that compares the second digit and writes the correct digit
        //underneath the separated number.
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
        //Similar switch statement to the tens, but for the ones place.
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

    //Calling the ArmstrongNumber function
    ArmstrongNumber(value);

    return;
}

//*********************************************************************************************************
//Armstrong Number is the function that takes the user's input and determines if the input is an
//Armstrong Number. The function cubes each input number and adds them together to find the sum to equate
//the input to an Armstrong Number.
//
//param-1- value this parameter is an int that is the user's input
//when prompted to give a number between 0-200
//returns the sum of the user's output and also returns whether or not the sum equals an Armstrong Number.
//*********************************************************************************************************
void ArmstrongNumber(int value)
{

    cout << "********Armstrong Number Calculation********" << endl << endl;

    //Assigning Variables
    int sumOfCubes = 0;
    int mutatedValue = value;

    //For loop that loops 10 times, cubes each value and sums the mutated value
    for(int i = 0; i < 10; i++){
        int digit = mutatedValue % 10;

        sumOfCubes += digit * digit * digit;

        mutatedValue /= 10;
    }

    //Boolean statement that value of the sumOfCubes for true or false and puts it into a variable
    //that we can reference
    bool isArmstrongNumber = (sumOfCubes == value);

    cout << "The sum of the cubes is: " << sumOfCubes << endl;
    cout << "Since " << sumOfCubes << " is ";
    cout << (isArmstrongNumber ? "equal" : "not equal") << " to " << value;
    cout << ", " << value << " " << (isArmstrongNumber ? "is" : "is not");
    cout << " an Armstrong number" << endl << endl;

    PrimeCalculation(value);
}

//********************************************************************************************************
//Prime Calculation is a function that takes the user's input and finds out whether or not there are any
//primes between and including the input itself. The function takes the user's input and checks if the
//input is divisible by 2 to see if the input is prime.
//
//param-1- value this parameter is an int that is the user's input
//when prompted to give a number between 0-200
//returns whether or not the user input is a prime number and all the numbers that are prime prior to
//the user's input.
//********************************************************************************************************
void PrimeCalculation(int value)
{
    //Assigning Variables
    int size = 46;
    vector<int> primes (46);
    int count = 0;

    cout << "********Prime Calculation********" << endl << endl;

    //For loop that checks if its divisible from 2 to the value
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

    //If prime the number is output as a prime, if not prime the output is not a prime
    //Also prints out the primes between the 0 and the value
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

//********************************************************************************************************
//Factorial Calculate is a function that takes the user's input value and calculates the factorial.
//
//param-1- value this parameter is an int that is the user's input
//when prompted to give a number between 0-200
//returns the user input into the calculated factorial.
//********************************************************************************************************
void FactorialCalculation(int value)
{

    long long int factorial = 1;

    cout << "********Factorial Calculation********" << endl << endl;

    for(int i = 2; i <= value; i++)
    {
        factorial = factorial*i;
    }

    cout << "Factorial of " << value << " is: " << factorial << endl << endl;

    //Calling the HailstoneSequence function
    HailstoneSequence(value);
}

//**********************************************************************************************************
//Hailstone Sequence is a function that calculates the hailstone sequence of the user's input.
//The function takes the user input and checks if its odd or even and calculates the sequence based on
//the odd or even input.
//
//param-1- value this parameter is an int that is the user's input
//when prompted to give a number between 0-200
//returns the user's input into the calculated sequence outputting all the numbers until the sequence is 1.
//**********************************************************************************************************
void HailstoneSequence(int value)
{
    //3n+1 if odd, n/2 if even
    cout << "********Hailstone Sequence Calculation********" << endl << endl;

    int mutatedValue = value;

    //While loop that runs if the mutated value does not equal one
    while(mutatedValue != 1)
    {
        cout << mutatedValue << " ";

        //Checks to see if the number is odd and runs the 3n+1 formula
        //Else the number is even and runs the n/2 formula
        if(mutatedValue % 2 != 0)
            mutatedValue = (mutatedValue * 3) + 1;
        else
            mutatedValue /= 2;
    }

    cout << 1 << endl << endl;
}
