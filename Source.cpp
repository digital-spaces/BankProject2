/*#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <ios>
#include <iomanip>
using namespace std;*/

/**
* Prints the calculated results of each years investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
/*void printDetails(int year, double yearEndBalance, double interestEarned) {*/

    // you may wish to change this function when you bring it into your program
    // for now please get it to work here

    //       IMPORTANT TIPS:
    // There should be two tabs in between each field
    // Dollars should be printed to the second decimal place


    /*
    Example:
     1               	$110.00                 	$10.00

    */
    // TODO: your code here to implement the method
    // returns nothing, just prints output to cout
    /*cout << fixed;
    cout.imbue(locale("en_US.UTF-8"));
    cout << setprecision(2) << right << setfill(' ') << setw(8) << year <<
        right << setfill(' ') << setw(33) << showbase << put_money(yearEndBalance * 100) <<
        right << setfill(' ') << setw(40) << showbase << put_money(interestEarned * 100) << endl;
}*/

/**
 * Calculates and returns an end of year balance for given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 * @return the final calculated end of year balance
 */
/*double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {*/
    // you may wish to change this function when you bring it into your program
    // for now please get it to work here as specified

    //       IMPORTANT TIPS:
    // You should assume a working printDetails(int yearIndex, double balance, double interestEarnedThisYear) exists
    // printDetails should be called after each year
    // Compounding should be done monthly
    // Make sure to keep values to at least 2 decimal places
    // Make sure to divide the interest rate by 100 and by 12
    // Year begins with 1, not 0

    /*
    Example:for 100 initial, 10% interest, and 4 years
    Year            Year End Balance        Interest Earned
     1               	$110.47                 	$10.47
     2                $122.04                	    $11.57
     3               	$134.82                 	$12.78
     4              	$148.94                 	$14.12
    */
    // TODO: your code here to implement the method
    /*double interest = 0;

    cout << "             Balance and Interest without Additional Monthly Deposits" << endl <<
        "=====================================================================================" << endl <<
        "    Year \t\t Year End Balance \t\t Year End Earned Interest" << endl <<
        "-------------------------------------------------------------------------------------" << endl;
    for (int i = 1; i <= numberOfYears; i++) {*/
        /*cout << endl;
        cout << initialInvestment << endl;
        cout << interestRate / 100 << endl;
        cout << numberOfYears << endl;
        cout << i << endl;
        cout << pow(100 * (1 + (.10 / 12)), 12) << endl;
        cout << interest << endl;
        cout << i << " " << initialInvestment * pow((1 + (interestRate / 100 / 12)), 12 * i) << " " << initialInvestment * pow((1 + (interestRate / 100 / 12)), 12 * i) - initialInvestment - interest << endl;*/
        /*printDetails(i, initialInvestment* pow((1 + (interestRate / 100 / 12)), 12 * i), initialInvestment* pow((1 + (interestRate / 100 / 12)), 12 * i) - initialInvestment - interest);
        interest += initialInvestment * pow((1 + (interestRate / 100 / 12)), 12 * i) - initialInvestment - interest;
    }
    cout << endl << endl;*/
    // return the final balance
    /*return initialInvestment * pow((1 + (interestRate / 100 / 12)), 12 * numberOfYears);
}*/

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
/*double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    double interest = 0;
    vector<double> interestByYear;
    interestByYear.push_back(0);
    double adjustedInterestRate = 1 + interestRate / 100 / 12;*/
    //cout << setprecision(2);

    /*cout << "                Balance and Interest with Additional Monthly Deposits" << endl <<
            "=====================================================================================" << endl <<
            "    Year \t\t Year End Balance \t\t Year End Earned Interest" << endl <<
            "-------------------------------------------------------------------------------------" << endl;
    for (int i = 1; i <= numberOfYears * 12; i++) {*/
        /*cout << endl;
        cout << initialInvestment << endl;
        cout << interestRate / 100 << endl;
        cout << numberOfYears << endl;
        cout << i << endl;
        cout << pow(100 * (1 + (.10 / 12)), 12) << endl;
        cout << interest << endl;
        if (i % 12 == 0) {
            cout << fixed << (monthlyDeposit * (-1 + pow(adjustedInterestRate, i))) / (-1 + adjustedInterestRate) + pow(adjustedInterestRate, i) * initialInvestment << endl;
        }*/
        //cout << i << " " << (investment * interestRate/100/12) + investment << endl;
        //printDetails(i, initialInvestment * pow((1 + (interestRate / 100 / 12)), 12 * i), initialInvestment * pow((1 + (interestRate / 100 / 12)), 12 * i) - initialInvestment - interest);

        /*interest += ((monthlyDeposit * (-1 + pow((1 + interestRate / 100 / 12), i)) / (-1 + (1 + interestRate / 100 / 12))) + pow(1 + interestRate / 100 / 12, i) * initialInvestment) - interest - initialInvestment - monthlyDeposit * i;
        if (i % 12 == 0) {
            double pastInterest = 0;
            for (int i = 0; i < interestByYear.size(); i++) {
                //cout << i << " " << interestByYear.at(i) << endl;
                pastInterest += interestByYear.at(i);
            }*/
            //cout << pastInterest << endl;
            /*interestByYear.push_back(interest - pastInterest);
            printDetails(i / 12, (monthlyDeposit * (-1 + pow(adjustedInterestRate, i))) / (-1 + adjustedInterestRate) + pow(adjustedInterestRate, i) * initialInvestment, interestByYear.at(i / 12));*/
            //cout << "Interest for year " << i/12 << ": " << interest << endl;
            //cout << "Test: " << (monthlyDeposit * (-1 + pow(adjustedInterestRate, 24))) / (-1 + adjustedInterestRate) + pow(adjustedInterestRate, 24)*initialInvestment << endl;
            //cout << interestByYear.at(i / 12) << endl;
        //}
    //}

    // return the final balance
    /*return (monthlyDeposit * (-1 + pow(adjustedInterestRate, numberOfYears * 12))) / (-1 + adjustedInterestRate) + pow(adjustedInterestRate, numberOfYears * 12) * initialInvestment;
}*/

/*void dataInput() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

    cout << "************************************" << endl;
    cout << "************ Data Input ************" << endl;

    cout << "Initial Investment Amount:  $";
    cin >> initialInvestment;
    cout << "Monthly Deposit:            $";
    cin >> monthlyDeposit;
    cout << "Annual Interest:            %";
    cin >> annualInterest;
    cout << "Number of Years:            ";
    cin >> numYears;

    system("pause");
    system("cls");

    calculateBalanceWithoutMonthlyDeposit(initialInvestment, annualInterest, numYears);
    balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterest, numYears);
}

int main() {
    dataInput();

    return 0;
}*/