#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <map>
#include <sstream>

using namespace std;

// ========================== Utility Functions ===============================
string getCurrentTime() {
    time_t now = time(0);
    tm* localtm = localtime(&now);
    char buffer[50];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtm);
    return string(buffer);
}

void ensureFile(const string& filename) {
    ifstream check(filename);
    if (!check.good()) {
        ofstream create(filename);
        if (filename == "quotes.txt") {
            create << "You are enough.\nThis too shall pass.\nBreathe. It will be okay.\n";
        } else if (filename == "gratitude.txt") {
            create << "Family\nHealth\nOpportunity to learn\n";
        }
        create.close();
    }
}

void pauseConsole(int ms = 2000) {
    Sleep(ms);
}

// ============================ Quote Features ===============================
string getRandomQuote() {
    ifstream file("quotes.txt");
    vector<string> quotes;
    string line;
    while (getline(file, line)) {
        if (!line.empty()) quotes.push_back(line);
    }
    if (quotes.empty()) return "Stay strong. You are not alone.";
    srand((unsigned)time(0));
    return quotes[rand() % quotes.size()];
}

void showMultipleQuotes(int count = 3) {
    cout << "\nQuotes of the Moment:\n";
    for (int i = 0; i < count; ++i) {
        cout << "- " << getRandomQuote() << endl;
        pauseConsole(500);
    }
}

// ============================ Mood Tracking ================================
void saveMood(const string& mood) {
    ofstream file("moodlog.txt", ios::app);
    file << "[" << getCurrentTime() << "] Mood: " << mood << "\n";
    file.close();
}

void moodSuggestion(const string& mood) {
    cout << "\nBased on your mood (" << mood << "), here's a suggestion:\n";
    if (mood.find("sad") != string::npos || mood.find("down") != string::npos)
        cout << "Listen to calming music or call a friend.\n";
    else if (mood.find("anxious") != string::npos)
        cout << "Try a 5-minute breathing exercise or journaling.\n";
    else if (mood.find("happy") != string::npos)
        cout << "Keep it up! Spread the joy to others today.\n";
    else
        cout << "Every feeling is valid. Take care of yourself.\n";
}

void displayMoodHistory() {
    ifstream file("moodlog.txt");
    string line;
    cout << "\nMood History:\n";
    while (getline(file, line)) cout << line << "\n";
}

void moodStats() {
    ifstream file("moodlog.txt");
    string line;
    int happy = 0, sad = 0, total = 0;
    string lastMood;

    while (getline(file, line)) {
        total++;
        if (line.find("happy") != string::npos) happy++;
        if (line.find("sad") != string::npos) sad++;
        lastMood = line;
    }

    if (total == 0) {
        cout << "No mood data available.\n";
        return;
    }

    cout << "\nMood Trend Analysis:\n";
    cout << "Happy: " << happy << " (" << (happy * 100 / total) << "%)\n";
    cout << "Sad: " << sad << " (" << (sad * 100 / total) << "%)\n";
    cout << "Last Entry: " << lastMood << "\n";
}

// ======================== Breathing and Gratitude ===========================
void breathingExercise() {
    cout << "\nBreathing Exercise (3 rounds):\n";
    for (int i = 1; i <= 3; i++) {
        cout << "\nRound " << i << ":\n";
        cout << "Inhale..."; Sleep(4000);
        cout << " Hold..."; Sleep(4000);
        cout << " Exhale...\n"; Sleep(4000);
    }
}

void gratitudeJournal() {
    ofstream file("gratitude.txt", ios::app);
    string entry;
    cout << "\nEnter 3 things you're grateful for today:\n";
    for (int i = 1; i <= 3; ++i) {
        cout << i << ". ";
        getline(cin, entry);
        if (!entry.empty())
            file << "[" << getCurrentTime() << "] " << entry << "\n";
    }
    file.close();
    cout << "Thank you for sharing your gratitude.\n";
}

void viewGratitudeJournal() {
    ifstream file("gratitude.txt");
    string line;
    cout << "\nGratitude Entries:\n";
    while (getline(file, line)) cout << "- " << line << "\n";
}

// ============================ Reminders & Motivation =======================
void dailyReminder() {
    cout << "\nDaily Mental Health Tip:\n";
    cout << getRandomQuote() << endl;
}

void motivationBooster() {
    cout << "\nMotivation Boost:\n";
    showMultipleQuotes(5);
}

// ============================ Main Menu ====================================
void showMenu() {
    cout << "\n===== Mental Health Console Simulator =====\n";
    cout << "1. Submit Mood\n";
    cout << "2. View Random Quote\n";
    cout << "3. Do Breathing Exercise\n";
    cout << "4. View Mood History\n";
    cout << "5. Analyze Mood Trends\n";
    cout << "6. Write Gratitude Journal\n";
    cout << "7. View Gratitude Journal\n";
    cout << "8. Motivation Booster\n";
    cout << "9. Daily Reminder\n";
    cout << "10. Exit\n";
    cout << "Choose option (1-10): ";
}

// ============================= MAIN ========================================
int main() {
    ensureFile("quotes.txt");
    ensureFile("moodlog.txt");
    ensureFile("gratitude.txt");

    int choice;
    string mood;

    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\nEnter your mood: ";
                getline(cin, mood);
                if (!mood.empty()) {
                    saveMood(mood);
                    cout << "Mood saved successfully.\n";
                    moodSuggestion(mood);
                } else {
                    cout << "No mood entered.\n";
                }
                break;
            case 2:
                cout << "\nQuote:\n" << getRandomQuote() << endl;
                break;
            case 3:
                breathingExercise();
                break;
            case 4:
                displayMoodHistory();
                break;
            case 5:
                moodStats();
                break;
            case 6:
                gratitudeJournal();
                break;
            case 7:
                viewGratitudeJournal();
                break;
            case 8:
                motivationBooster();
                break;
            case 9:
                dailyReminder();
                break;
            case 10:
                cout << "Stay well. See you again!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
