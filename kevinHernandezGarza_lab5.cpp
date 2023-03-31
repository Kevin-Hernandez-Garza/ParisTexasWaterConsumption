//******************************************************************
// Author: Kevin Hernandez-Garza
// Assignment Number: Programming Assignment "5"
// File Name: KevinHernandezGarza_lab5.cpp
// Course/Section: COSC 1337 Section -009
// Due Date: 3/25/23
// Instructor: Dr.Haytham Mohamed
//
// This program tracks information on water consumption for the city of Paris,
// Texas on a monthly basis. It specifically calculates the highest and lowest
// months, and yearly average and total measured in CCF(centum cubic feet).
//  ******************************************************************

/*
    The lowest consumption was in March with 100000 CCF
    The highest consumption was in July with 200000 CCF
    The total consumption for the year was: 20000000 CCF

    MODULARITY: Your program must be a modular program. Your main function should not contain
    any loops. It should call all of the functions described above, calling a total of 6 functions.

    ADDITIONAL REQUIREMENTS:
        1. Do not use global in any assignment. A global variable is a variable that is declared outside any function. It is okay to use global constants.

        2. When passing the array to a function that does not modify it, use the const keyword
        to prevent any modification to the array.

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void monthlyConsumption(int *consumption, string *months, int SIZE);
void printHeaders();
void displayConsumption(int *consumption, string *months, int SIZE);
void getAverageConsumption(int *consumption, int SIZE);

int main()
{
    const int SIZE = 11;
    int consumption[SIZE]; // consumption array
    string months[SIZE] = {"January", "February", "March", "April", "June", "July", "August", "September", "October", "November", "December"};

    monthlyConsumption(consumption, months, SIZE);
    printHeaders();
    displayConsumption(consumption, months, SIZE);
    getAverageConsumption(consumption, SIZE);

    return 0;
}

void monthlyConsumption(int *consumption, string *months, int SIZE)
{
    for (int count = 0; count < SIZE; count++)
    {
        cout << "Enter the CCF consumption for " << *(months + count) << ": ";
        do
        {
            cin >> consumption[count];

            if (consumption[count] < 0)
            {
                cout << "Error: Consumption cannot be a negative integer!" << endl;
                cout << "Enter a non-negative integer for " << consumption[count] << ": ";
            }
        } while (consumption[count] < 0);
    }
}

void displayConsumption(int *consumption, string *months, int SIZE)
{
    // iterating over the months and consumption array to display them on
    // the console for the user.
    for (int count = 0; count < SIZE; count++)
    {
        cout << setw(38) << left << *(months + count) << right << *(consumption + count) << endl;
    }
    cout << endl;
    cout << endl;
}

void printHeaders()
{
    int reportYear;
    // asking user for report year with input validation
    do
    {
        cout << "Enter year of the report: ";
        cin >> reportYear;

        if (reportYear < 2005 || reportYear > 2020)
        {
            cout << "Error: Incorrect year! " << endl;
            cout << "Please enter a year between 2005 & 2020." << endl;
        }
    } while (reportYear < 2005 || reportYear > 2020);

    cout << endl;
    cout << endl;
    cout << reportYear << " Consumption report for Paris, Texas " << endl;
    cout << endl;
    cout << setw(35) << left << "Month" << right << "Consumption" << endl;
    cout << "==============================================" << endl;
    cout << endl;
}

/*
int getLowestConsumption()
{
    // FUNCTION #4: GET THE LOWEST CONSUMPTION: Using the data from the consumption array, determine the month with the lowest consumption, print the month name and the amount of the consumption for that month.
}

int getHighestConsumption()
{
    // FUNCTION #5: GET THE HIGHEST CONSUMPTION: Using the data from the consumption array, determine the month the highest
    // consumption, print the month name and the amount of the consumption for that month.
}*/

void getAverageConsumption(int *consumption, int SIZE)
{
    // FUNCTION #6: GET THE TOTAL AVERAGE CONSUMPTION: Using the data from the consumption array
    // calculate the total and average of all months for the year and print them.
    int sum = 0; // holds total
    double average = 0;
    for (int count = 0; count < SIZE; count++)
    {
        sum += *(consumption + count);
        count++;
    }

    average = sum / 12;

    cout << endl;
    cout << "The total consumption for the year was: " << sum << " CCF" << endl;
    cout << "The average consumption for the year: " << average << " CCF" << endl;
    cout << endl;
}