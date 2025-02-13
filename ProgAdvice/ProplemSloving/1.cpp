#include <iostream>
#include <unordered_map>
#include <ctime>
#include <sstream>
#include <limits>
#include <cctype>

using namespace std;

// Mapping of month names and numbers
unordered_map<string, int> months = {
    {"january", 1}, {"february", 2}, {"march", 3}, {"april", 4},
    {"may", 5}, {"june", 6}, {"july", 7}, {"august", 8},
    {"september", 9}, {"october", 10}, {"november", 11}, {"december", 12}
};

// Function to trim spaces from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

// Function to convert input to lowercase
string toLower(string str) {
    for (char &c : str) c = tolower(c);
    return str;
}

// Function to get a valid integer input
int getInt(const string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input
            cout << "Invalid input! Please enter a number between " << minVal << " and " << maxVal << ".\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard extra input
            return value;
        }
    }
}

// Function to get a valid month input (number or name)
int getMonth() {
    string input;
    while (true) {
        cout << "Type month (1-12 or name like 'March'): ";
        getline(cin, input);
        input = trim(input);
        string lowerInput = toLower(input);

        // Check if input is a number
        if (isdigit(lowerInput[0])) {
            int monthNum = stoi(lowerInput);
            if (monthNum >= 1 && monthNum <= 12) return monthNum;
        }
        // Check if input is a valid month name
        else if (months.find(lowerInput) != months.end()) {
            return months[lowerInput];
        }

        cout << "Invalid month! Please try again.\n";
    }
}

// Function to parse 12-hour or 24-hour time format
bool parseTime(string input, int &hour, int &minute) {
    trim(input);
    toLower(input);
    int h, m;
    char colon;
    string ampm = "";

    istringstream ss(input);
    if (ss >> h >> colon >> m) {
        if (colon != ':') return false; // Must be in HH:MM format

        if (ss >> ampm) { // If AM/PM exists
            if (ampm == "am" || ampm == "pm") {
                if (h < 1 || h > 12 || m < 0 || m > 59) return false;
                if (ampm == "pm" && h != 12) h += 12; // Convert PM to 24-hour
                if (ampm == "am" && h == 12) h = 0;   // Convert 12 AM to 0-hour
            } else {
                return false; // Invalid AM/PM format
            }
        } else { // 24-hour format
            if (h < 0 || h > 23 || m < 0 || m > 59) return false;
        }

        hour = h;
        minute = m;
        return true;
    }
    return false;
}

// Function to get valid time input
void getTime(int &hour, int &minute) {
    string input;
    while (true) {
        cout << "Type time (HH:MM or HH:MM AM/PM): ";
        getline(cin, input);

        if (parseTime(input, hour, minute)) return;

        cout << "Invalid time format! Please enter in 'HH:MM' or 'HH:MM AM/PM' format.\n";
    }
}

// Function to read a date and return time_t
time_t readDate() {
    int year = getInt("Type year (1900-2025): ", 1900, 2025);
    int month = getMonth();
    int day = getInt("Type day (1-31): ", 1, 31);
    int hour, minute;

    getTime(hour, minute);

    // Create a tm structure
    struct tm timeInfo = {};
    timeInfo.tm_year = year - 1900;  // tm_year is years since 1900
    timeInfo.tm_mon = month - 1;     // tm_mon is 0-based
    timeInfo.tm_mday = day;
    timeInfo.tm_hour = hour;
    timeInfo.tm_min = minute;
    timeInfo.tm_sec = 0;

    // Convert to time_t
    time_t t = mktime(&timeInfo);
    if (t == -1) {
        cout << "Failed to convert time!" << endl;
        return -1;
    }

    return t;
}

// Main function
int main() {
    time_t userTime = readDate();
    if (userTime != -1) {
        cout << "The entered date-time is: " << ctime(&userTime);
    } else {
        cout << "Invalid date input!" << endl;
    }

    return 0;
}
