//******************************************************************
// Author: Kevin Hernandez-Garza
// This program tracks information on water consumption for the city of Paris,
// Texas on a monthly basis. It specifically calculates the highest and lowest
// months, and yearly average and total measured in CCF(centum cubic feet).
//  ******************************************************************

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void monthlyConsumption(int *consumption, string *months, int SIZE);
void printHeaders();
void displayConsumption(int *consumption, string *months, int SIZE);
void getAverageConsumption(int *consumption, int SIZE);
void getLowestConsumption(int consumption[], int SIZE);
void getHighestConsumption(int consumption[], int SIZE);

int main()
{
    const int SIZE = 11;
    int consumption[SIZE]; // consumption array
    string months[SIZE] = {"January", "February", "March", "April", "June", "July", "August", "September", "October", "November", "December"};

    monthlyConsumption(consumption, months, SIZE);
    printHeaders();
    displayConsumption(consumption, months, SIZE);
    getAverageConsumption(consumption, SIZE);
    getLowestConsumption(consumption, SIZE);
    getHighestConsumption(consumption, SIZE);

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
    cout << "\n\n";
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

    cout << "\n\n";
    cout << reportYear << " Consumption report for Paris, Texas " << endl;
    cout << endl;
    cout << setw(35) << left << "Month" << right << "Consumption" << endl;
    cout << "==============================================" << endl;
    cout << "\n";
}

void getLowestConsumption(int consumption[], int SIZE)
{
    for (int i = 0; i < (SIZE - 1); i++)
    {
        int min = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (consumption[j] < consumption[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = consumption[i];
            consumption[i] = consumption[min];
            consumption[min] = temp;
        }
    }

    cout << "The lowest consumption value is: " << consumption[0] << " CCF" << endl;
}

void getHighestConsumption(int consumption[], int SIZE)
{
    for (int i = 0; i < (SIZE - 1); i++)
    {
        int min = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (consumption[j] < consumption[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = consumption[i];
            consumption[i] = consumption[min];
            consumption[min] = temp;
        }
    }

    cout << "The highest consumption value is: " << consumption[SIZE - 1] << " CCF" << endl;
}

void getAverageConsumption(int *consumption, int SIZE)
{
    // calculate the total and average of all months for the year and print them.
    int sum = 0; // holds total
    double average = 0;
    for (int count = 0; count < SIZE; count++)
    {
        sum += *(consumption + count);
        count++;
    }

    average = sum / 12;

    cout << "\nThe total consumption for the year was: " << sum << " CCF" << endl;
    cout << "The average consumption for the year: " << average << " CCF\n"
         << endl;
}