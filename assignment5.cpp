/*
 * assignment5.cpp
 *
 *  Date: 6-8-2024
 *  Author: Xander O'Hara
 */


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //Read data from the input file
    ifstream inputFile("FahrenheitTemperature.txt");
    if (!inputFile) {
        cerr << "Failed to open FahrenheitTemperature.txt" << endl;
        return 1;
    }

    string city;
    int fahrenheitTemp;
    ofstream outputFile("CelsiusTemperature.txt");
    if (!outputFile) {
        cerr << "Failed to create CelsiusTemperature.txt" << endl;
        inputFile.close();
        return 1;
    }

    while (inputFile >> city >> fahrenheitTemp) {
        //Convert Fahrenheit to Celsius
        double celsiusTemp = (fahrenheitTemp - 32.0) * (5.0 / 9.0);

        //write data to the output file
        outputFile << city << " " << celsiusTemp << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Fahrenheit to Celsius Conversion complete." << endl;

    return 0;
}