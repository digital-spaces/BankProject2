#include <iostream>
#include "BankAccount.h"
using namespace std;
/**
* Validates and returns user input
*/
double inputValidation() {
    double input;
    while (true) {
        // Get the first number and ignore everything else
        cin >> input;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // If a valid number is found, return it. Else, continue.
        if (!cin.fail() && input > 0 && cin) {
            return input;
        }
        cout << "Please enter a valid number: ";
    }
}

/**
* Creates account, assigns input, returns account
*/
BankAccount dataInput() {
    BankAccount account; // Declare account

    // Take input from user and set account attributes
    cout << "************************************" << endl;
    cout << "************ Data Input ************" << endl;
    cout << "Initial Investment Amount:  $";
    account.setInitialInvestment(inputValidation());
    cout << "Monthly Deposit:            $";
    account.setMonthlyDeposit(inputValidation());
    cout << "Annual Interest:            %";
    account.setAnnualInterest(inputValidation());
    cout << "Number of Years:            ";
    account.setNumYears(inputValidation());

    // Let user see their data before clearing the screen
    system("pause");
    system("cls");

    // Return the new account
    return account;
}

int main() {
    BankAccount account = dataInput();

    account.balanceReportWithoutDeposit();
    account.balanceReportWithDeposit();

    return 0;
}