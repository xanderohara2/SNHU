/*
 * Banking.cpp
 *
 *  Date: 6-8-2024
 *  Author: Xander O'Hara
 */


#include "Banking.h"


Banking::Banking(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numYears)
    : m_initialInvestment(t_initialInvestment), m_monthlyDeposit(t_monthlyDeposit),
      m_annualInterestRate(t_annualInterestRate), m_numYears(t_numYears) {}

void Banking::calculateAndDisplay() const {
    const int MONTHS_PER_YEAR = 12;
    double totalBalance = m_initialInvestment;
    double monthlyInterestRate = m_annualInterestRate / static_cast<double>(MONTHS_PER_YEAR);

    std::cout << "\n\n           Balance and interest without additional monthly deposits:\n";
    std::cout << "==================================================================================\n";
    std::cout << std::setw(10) << "Year" << std::setw(29) << "Year End Balance" << std::setw(36) << "Year End Earned Interest\n";
    std::cout << "----------------------------------------------------------------------------------\n";


    //iterate over years
    for (int year = 1; year <= m_numYears; ++year) {
        double yearlyInterest = 0.0;

        // Iterate over months
        for (int month = 1; month <= MONTHS_PER_YEAR; ++month) {
            double monthlyInterest = totalBalance * monthlyInterestRate;
            yearlyInterest += monthlyInterest;
            totalBalance += monthlyInterest;
        }
    // Display
        std::cout << std::setw(10) << year << std::setw(20) << "$" << std::fixed << std::setprecision(2) << totalBalance
                  << std::setw(27) << "$" << yearlyInterest << "\n";
                     std::cout << "----------------------------------------------------------------------------------\n";

    }
    std::cout << "==================================================================================\n";
    std::cout << "\n\n           Balance and interest with additional $" << m_monthlyDeposit << " monthly deposits:\n";
    std::cout << "==================================================================================\n";
    std::cout << std::setw(10) << "Year" << std::setw(29) << "Year End Balance" << std::setw(36) << "Year End Earned Interest\n";
    std::cout << "----------------------------------------------------------------------------------\n";
    

    totalBalance = m_initialInvestment;

    //Iterate over years with the added monthly deposits
    for (int year = 1; year <= m_numYears; ++year) {
        double yearlyInterest = 0.0;

        // Iterate over months
        for (int month = 1; month <= MONTHS_PER_YEAR; ++month) {
            totalBalance += m_monthlyDeposit;
            double monthlyInterest = totalBalance * monthlyInterestRate;
            yearlyInterest += monthlyInterest;
            totalBalance += monthlyInterest;
        }
        
    // Display
        std::cout << std::setw(10) << year << std::setw(20) << "$" << std::fixed << std::setprecision(2) << totalBalance
                  << std::setw(27) << "$" << yearlyInterest << "\n";
                     std::cout << "----------------------------------------------------------------------------------\n";

    }
    std::cout << "==================================================================================\n";
    std::cout << "\n------------After " << m_numYears << " years:------------\n";
    std::cout << "Your total balance will be: $" << std::fixed << std::setprecision(2) << totalBalance << "\n";
    std::cout << "--------------------------------------\n\n";

}