/************************************
Morgan Fox
SNHU CS-210
2022-06-04
Project 2
*************************************/

// Program setup
#include <iostream>
#include <vector>
#include <iomanip>
#include "BankAccount.h"
using namespace std;

/*
* Public setters for object attributes.
* No getters are provided because balance reports will deal with them.
*/
void BankAccount::setInitialInvestment(double t_investment) {
    m_initialInvestment = t_investment;
}
void BankAccount::setMonthlyDeposit(double t_deposit) {
    m_monthlyDeposit = t_deposit;
}
void BankAccount::setAnnualInterest(double t_interest) {
    m_annualInterest = t_interest;
}
void BankAccount::setNumYears(int t_years) {
    m_numYears = t_years;
}

/**
* Prints the calculated results of each years investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
void BankAccount::printDetails(int t_year, double t_yearEndBalance, double t_interestEarned) {
    // Setup the console output for currency
    cout.imbue(locale("en_US.UTF-8"));

    // Output the year, balance and interest with correct formatting
    cout << setprecision(2) << right << setfill(' ') << setw(8) << t_year <<
        right << setfill(' ') << setw(33) << showbase << put_money(t_yearEndBalance * 100) <<
        right << setfill(' ') << setw(40) << showbase << put_money(t_interestEarned * 100) << endl;
}

/**
 * Calculates and returns an end of year balance for given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 * @return the final calculated end of year balance
 */
double BankAccount::balanceReportWithoutDeposit() {
    double interest = 0; // Initial interest is 0
    double adjustedInterestRate = 1 + m_annualInterest / 100 / 12; // Calculate monthly interest rate

    cout << "             Balance and Interest without Additional Monthly Deposits" << endl <<
        "=====================================================================================" << endl <<
        "    Year \t\t Year End Balance \t\t Year End Earned Interest" << endl <<
        "-------------------------------------------------------------------------------------" << endl;

    // For every year, calculate and print balance and interest
    for (int i = 1; i <= m_numYears; i++) {
        double balance = m_initialInvestment * pow(adjustedInterestRate, 12 * i); // Calculate balance
        printDetails(i, balance, balance - m_initialInvestment - interest); // Print the yearly balance and yearly interest
        interest += balance - m_initialInvestment - interest; // Tally total interest
    }

    cout << endl << endl;

    // Return total balance
    return m_initialInvestment * pow(adjustedInterestRate, 12 * m_numYears);
}

/**
 * Calculates and returns an end of year balance for a given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param monthlyDeposit dollar amount added into the investment each month
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 * @return the final calculated end of year balance
 */
double BankAccount::balanceReportWithDeposit() {
    // Keeping track of monthly interest for more complex monthly calculations.
    double interest = 0;
    vector<double> interestByYear;
    interestByYear.push_back(0); 

    double adjustedInterestRate = 1 + m_annualInterest / 100 / 12; // Calculate monthly interest rate

    cout << "                Balance and Interest with Additional Monthly Deposits" << endl <<
        "=====================================================================================" << endl <<
        "    Year \t\t Year End Balance \t\t Year End Earned Interest" << endl <<
        "-------------------------------------------------------------------------------------" << endl;

    // For every month, calculate and print balance and interest
    for (int i = 1; i <= m_numYears * 12; i++) {
        interest += ((m_monthlyDeposit * (-1 + pow(adjustedInterestRate, i)) / (-1 + adjustedInterestRate)) + pow(adjustedInterestRate, i) * m_initialInvestment) - interest - m_initialInvestment - m_monthlyDeposit * i; // Tally interest first

        // Every year, calculate and print balance and interest
        if (i % 12 == 0) {
            // Calculate past years interest so we can remove it from this year's total
            double pastInterest = 0;
            for (int i = 0; i < interestByYear.size(); i++) {
                pastInterest += interestByYear.at(i);
            }
            interestByYear.push_back(interest - pastInterest); // Add this year's interest to the vector

            printDetails(i / 12, (m_monthlyDeposit * (-1 + pow(adjustedInterestRate, i))) / (-1 + adjustedInterestRate) + pow(adjustedInterestRate, i) * m_initialInvestment, interestByYear.at(i / 12)); // Print the yearly balance and yearly interest
        }
    }

    cout << endl << endl;

    // Return total balance
    return (m_monthlyDeposit * (-1 + pow(adjustedInterestRate, m_numYears * 12))) / (-1 + adjustedInterestRate) + pow(adjustedInterestRate, m_numYears * 12) * m_initialInvestment;
}
