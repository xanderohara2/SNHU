/*
* Xander O'Hara
* 05-26-2024
* "24 Hour Clock" assignment C++ code 
*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//clock variables
int hours12, hours24, minutes, seconds;
string ampm;

//Function that adds an hour to clock
void addHour() {
    hours12 = hours12 + 1;
    // then sets the clock
    if (hours12 > 12) {
        hours12 = hours12 - 12;

    }
    else if (hours12 == 12){
        if (ampm == "PM")
            ampm = "AM";
        else
            ampm = "PM";
    }
}

//Function that adds the minutes to clock
void addMinute() {
    minutes = minutes + 1;
    if (minutes > 59) {
        minutes = 0;
        addHour();
    }
}

//Function that adds a second to  clock
void addSecond() {
    seconds = seconds + 1;
    if (seconds > 59) {
        seconds = 0;
        addMinute();
    }
}

// The astricts around the clock view
void printClock(){
    cout << "***************************\t\t***************************" << endl;
    cout << "* " << setw(18) << "12-Hour clock" << setw(7) << " *"  << setw(15) << "* " <<setw(18) << "24-Hour clock"<< setw(7) << " *"  << endl;
    cout << "* " << setw(6)<<" "<< setfill('0') << setw(2) << hours12 << ":" << setw(2) << minutes << ":" << setw(2) << seconds << " " << ampm << setfill(' ')<<setw(8)<< " *" << setw(15);
    cout << "* " << setw(7) <<" "<< setfill('0')<< setw(2) << hours24 << ":"  << setw(2) << minutes << ":" << setw(2) << seconds << " " << setfill(' ') << setw(9) << " *" << endl;
    cout << "***************************\t\t***************************" << endl;
}

// The astricts around the menu view
void printMenu(){
    cout << "\n\n****************************" << endl;
    cout << "* 1-Add one hour" << setw(12)<<" *" << endl;
    cout << "* 2-Add one minute "<< setw(9)<< " *" << endl;
    cout << "* 3-Add one second" << setw(10) <<" *" << endl;
    cout << "* 4-Exit program" << setw(12) <<" *" << endl;
    cout << "****************************" << endl;
    cout << "Choose an option: ";

}

void menuLoop(){
    int choice = 0;
    while (true) {
        // Calculates the 24-hours
        if (ampm == "PM") {
            hours24 = hours12 + 12;
            if (hours24 >= 24) {
                hours24 = hours24 - 24;
            }
        } else {
            hours24 = hours12;
        }

        // displays clock
        printClock();

        // displays menu
        printMenu();
        cin >> choice;

        // user choice options
        switch (choice) {
            case 1:
                addHour();
                break;
            case 2:
                addMinute();
                break;
            case 3:
                addSecond();
                break;
            case 4:
                cout << "Exiting program...";
                return;
            default:
                cout << "Invalid input. Try Again...";
        }
    }
}

//Main function
int main() {

    // manual clock set
    hours12 = 10;
    minutes = 59;
    seconds = 58;
    ampm = "PM";

    menuLoop();
    return 0;
}
