#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <limits>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequency; // Map to store item frequencies
    const std::string INPUT_FILE = "CS210_Project_Three_Input_File.txt"; // the inputs file name
    const std::string OUTPUT_FILE = "frequency.dat"; // The outputs file name

    // Function to read items and their frequencies from input file
    void readInputFile() {
        std::ifstream inFile(INPUT_FILE); 
        std::string item; // Variable to hold each item read from file
        
        if (inFile.is_open()) { 
            while (inFile >> item) {
                itemFrequency[item]++; // Increment frequency of each item
            }
            inFile.close();
        } else {
            std::cerr << "Error: Unable to open input file." << std::endl; 
        }
    }

    // Function to write item frequencies to output file
    void writeOutputFile() {
        std::ofstream outFile(OUTPUT_FILE);
        
        if (outFile.is_open()) { // Check if file opened successfully
            for (const auto& pair : itemFrequency) {
                outFile << pair.first << " " << pair.second << std::endl; // Write item and frequency to file
            }
            outFile.close(); 
        } else {
            std::cerr << "Error: Unable to create output file." << std::endl; 
        }
    }

public:
    // Constructor to initialize and process input/output
    ItemTracker() {
        readInputFile(); // Read input file
        writeOutputFile(); // Write output file
    }

    // Function to search for a specific item and display its frequency
    void searchItem() {
        std::string item; 
        std::cout << "Enter the item to search for: ";
        std::cin >> item;
        item[0] = toupper(item[0]); //sets user input to upper to match whats in the text file
        
        auto it = itemFrequency.find(item); // Searchs for item
        if (it != itemFrequency.end()) {
            std::cout << item << " appears " << it->second << " time(s)." << std::endl;
        } else {
            std::cout << item << " not found." << std::endl; 
        }
    }

    //Function to print all item frequencies
    void printAllFrequencies() {
        for (const auto& pair : itemFrequency) {
            std::cout << std::setw(15) << std::left << pair.first << pair.second << std::endl; 
        }
    }

    // Function to print histogram
    void printHistogram() {
        for (const auto& pair : itemFrequency) {
            std::cout << std::setw(15) << std::left << pair.first; 
            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*"; 
            }
            std::cout << std::endl; 
        }
    }
};

// Main function
int main() {
    ItemTracker tracker; // Create instance of ItemTracker
    int choice; // Holds user's menu choice

    do {
        // Clear the screen ( fix for a Windows issues that came up)
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        // Display menu
        std::cout << "************************************\n";
        std::cout << "*    Corner Grocer Item Tracker    *\n";
        std::cout << "************************************\n";
        std::cout << "* 1. Search for an item            *\n";
        std::cout << "* 2. Print all item frequencies    *\n";
        std::cout << "* 3. Print histogram               *\n";
        std::cout << "* 4. Exit                          *\n";
        std::cout << "************************************\n";
        std::cout << "Enter your choice (1-4): ";

        // Input validation
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number 1-4." << std::endl;
            std::cout << "Press Enter to continue...";
            std::cin.get();
            continue;
        }

        std::cout << "************************************\n\n";

        //Method calls
        switch (choice) {
            case 1:
                tracker.searchItem(); 
                break;
            case 2:
                tracker.printAllFrequencies(); 
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!" << std::endl; 
                break;
            default:
                std::cout << "Invalid input. Please try again." << std::endl; 
        }

        if (choice != 4) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        }
    } while (choice != 4); // Repeat until user chooses to exit

    return 0;
}
