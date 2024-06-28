/*
 * Banking.h
 *
 *  Date: 6-8-2024
 *  Author: Xander O'Hara
 */

#ifndef AIRGEAD_BANKING_H_
#define AIRGEAD_BANKING_H_

#include <iostream>
#include <iomanip>
#include <cmath>

class Banking {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numYears;

public:
    Banking(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numYears);
    void calculateAndDisplay() const;
};

#endif