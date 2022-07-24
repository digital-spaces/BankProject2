#ifndef PROJECT2_BANKACCOUNT_H
#define PROJECT2_BANKACCOUNT_H

class BankAccount {
public:
    // Object methods
    double balanceReportWithDeposit();
    double balanceReportWithoutDeposit();
    void printDetails(int t_year, double t_yearEndBalance, double t_interestEarned);

    // Object setters
    void setInitialInvestment(double t_investment);
    void setMonthlyDeposit(double t_deposit);
    void setAnnualInterest(double t_interest);
    void setNumYears(int t_years);

private:
    // Account attributes
    double m_initialInvestment = -1, m_monthlyDeposit = -1, m_annualInterest = -1.0;
    int m_numYears = -1;
};

#endif