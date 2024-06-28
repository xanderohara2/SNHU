/*
 * BankingMain.cpp
 *
 *  Date: 6-8-2024
 *  Author: Xander O'Hara
 */

#include "Banking.h"
#include <limits>

double getValidDoubleInput(const std::string &prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // clear  error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // invalid input
            std::cout << "Invalid input, please enter a valid number.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove any remaining input
            return value;
        }
    }
}

int getValidIntInput(const std::string &prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // if invalid input
            std::cout << "Invalid input, please enter a valid number.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove any remaining input
            return value;
        }
    }
}

int main() {
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int numYears;

    std::cout << "**********************************\n";
    std::cout << "***********Data Input************\n";

    initialInvestment = getValidDoubleInput("Initial investment amount: $");
    monthlyDeposit = getValidDoubleInput("Monthly deposit: $");
    annualInterestRate = getValidDoubleInput("Annual Interest (%): ") / 100; // Converting to decimal
    numYears = getValidIntInput("Number of years: ");

    std::cout << "\nPress any key to continue . . . ";
    std::cin.get(); // Wait for user input

    // Make Banking object and calculate/display results
    Banking bank(initialInvestment, monthlyDeposit, annualInterestRate, numYears);
    bank.calculateAndDisplay();

    return 0;
}
