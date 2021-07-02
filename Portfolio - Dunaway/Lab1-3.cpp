//============================================================================
// Name        : Lab1-3.cpp
// Author      : James Dunaway
// Course      : CS-260-T5434 Data Structures and Algorithms
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Forward declarations
double strToDouble(string str, char ch);

// Data structure to hold bid information.
struct Bid {
	string title;
	string fund;
	string vehicleId;
	double amount;
};

/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */
void displayBid(Bid bid) {
    cout << "Title: " << bid.title << endl;
    cout << "Fund: " << bid.fund << endl;
    cout << "Vehicle: " << bid.vehicleId << endl;
    cout << "Bid Amount: " << bid.amount << endl;

    return;
}

/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
Bid getBid() {
    Bid newBid;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, newBid.title);

    cout << "Enter fund: ";
    cin >> newBid.fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, newBid.vehicleId);

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    newBid.amount = strToDouble(strAmount, '$');

    return newBid;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method
 */
int main() {

    // Declare bid instance
	Bid bid;

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // Call functions based on user input
        switch (choice) {
            case 1:
            	bid = getBid();
                break;
            case 2:
                displayBid(bid);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
