#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <thread>
#include <stdlib.h>
using namespace std;

const auto processor_count = std::thread::hardware_concurrency();

map<string, string> settingsMap; // Declare settingsMap globally to make it accessible to all functions

void getSettings() {
    ifstream fs("settings.cfg");

    if (!fs.is_open())
    {
        cout << "Oops.. something is wrong with your configuration file. Please try again with another file." << endl;
        return;
    }

    const char* settings[1] = { "threads" };
    string Line;
    unsigned int found = 0;

    while (getline(fs, Line)) {
        for (int i = 0; i < sizeof(settings) / sizeof(settings[0]); i++) {
            if (Line.find(settings[i]) != string::npos) {
                size_t pos = Line.find(settings[i]) + strlen(settings[i]) + 1;
                string value = Line.substr(pos);

                settingsMap[settings[i]] = value; // Store setting and its value in the map

                cout << "Setting: " << settings[i] << ", Value: " << value << endl;
                ++found;
            }
        }
    }

    fs.close();
}

void getCurrentThreads() {
    getSettings();
    // Check if "threads" setting was found and retrieve its value
    if (settingsMap.find("threads") != settingsMap.end()) {
        string threads = settingsMap["threads"];
        if (threads == "max")
        {
            int threadsToSet = processor_count;
            std::cout << threadsToSet;
        }
    }
}
