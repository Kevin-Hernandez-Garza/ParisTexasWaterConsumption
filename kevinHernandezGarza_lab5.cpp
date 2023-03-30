//******************************************************************
// Author: Kevin Hernandez-Garza
// Assignment Number: Programming Assignment "5"
// File Name: KevinHernandezGarza_lab5.cpp
// Course/Section: COSC 1337 Section -009
// Due Date: 3/11/23
// Instructor: Dr.Haytham Mohamed
//
// This program tracks information on water consumption for the city of Paris, Texas on a monthly basis. It specifically calculates the highest and lowest months, and yearly average and total measured in CCF(centum cubic feet).
//  ******************************************************************

/*
 - The city of Paris, Texas tracks how much water is consumed by its citizens on a monthly basis.
 The city manager would like statistics about the consumption. She would like to know the months
 with the highest and lowest consumption, the yearly average, and the yearly total.

    INPUT VALIDATION: DO NOT ACCEPT NEGATIVE NUMBERS

    Enter water consumption in CCF for January: 500000
    Enter water consumption in CCF for February: 400000
    etc...

    ==========================
    SAMPLE OUTPUT
    ==========================

    2016 Consumption Report for Paris, Texas

    Month           Consumption in CCF
    ----------------------------------
    January         500000
    February        250000
    etc..


    The lowest consumption was in March with 100000 CCF
    The highest consumption was in July with 200000 CCF
    The total consumption for the year was: 20000000 CCF
    The average consumption for the year was: 500000 CCF


    MODULARITY: Your program must be a modular program. Your main function should not contain
    any loops. It should call all of the functions described above, calling a total of 6 functions.

    ADDITIONAL REQUIREMENTS:
        1. Do not use global in any assignment. A global variable is a variable that is declared outside any function. It is okay to use global constants.

        2. When passing the array to a function that does not modify it, use the const keyword
        to prevent any modification to the array.

*/

#include <iostream>
#include <string>
using namespace std;

// declare function prototypes
// pass the array pointers
void monthlyConsumption(int *consumption, string *months, int SIZE);

int main()
{
    //- the MAIN function should:
    //- create an array to store the twelve months of consumption
    //- call the following functions, passing the array to all but the print headers functions.
    // set the array size to 12 to hold each month
    const int SIZE = 11;
    int consumption[SIZE]; // consumption array
    string months[SIZE] = {"January", "February", "March", "April", "June", "July", "August", "September", "October", "November", "December"};

    // learn how to pass arrays into a function
    monthlyConsumption(consumption, months, SIZE);

    // printHeaders();
    // displayConsumption();

    return 0;
}

void monthlyConsumption(int *consumption, string *months, int SIZE)
{
    // FUNCTION #1: The function should use a loop to ask the user for the amount consumed for 12 months, using the appropriate month name and store the data in the consumption array
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

int printHeaders()
{
    // FUNCTION #2: Print the headers
    //- Which should ask for the year of the report to be displayed in the header
    // and print the headers.
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

    cout << "The report year is: " << reportYear << endl;

    return 0;
}

int displayConsumption()
{
    // FUNCTION #3: DISPLAY THE CONSUMPTION: display the consumption for the year for each
    // month with the appropriate labels.
    for (int count = 0; count < SIZE; count++)
    {
        cout << months[count] << "'s consumption is " << consumption[count] << " CCF" << endl;
    }

    return 0;
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
}

int getAverageConsumption()
{
    // FUNCTION #6: GET THE TOTAL AVERAGE CONSUMPTION: Using the data from the consumption array
    // calculate the total and average of all months for the year and print them.
    int sum = 0; // holds total
    int i = 0;   // array index
}*/