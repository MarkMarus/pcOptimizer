#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

void getSettings() {
    ifstream fs("settings.cfg");

    if (!fs.is_open()) {
        cout << "Oops.. something is wrong with your configuration file. Please try again with another file." << endl;
        return;
    }

    const char* settings[4] = { "Blue", "Red", "Orange", "Yellow" };
    string Line;
    unsigned int found = 0;

    while (getline(fs, Line)) {
        for (int i = 0; i < sizeof(settings) / sizeof(settings[0]); i++) {
            if (Line == settings[i])
                ++found;
        }
    }

    fs.close();

    cout << "Number of settings found: " << found << endl;
    cout << "Press enter to exit." << endl;
    cin.get();
}