#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
    int events, days = 0;
    while (cin >> events) {
        cin.ignore();
        string appointment, start, end;
        int startTime, endTime;
        bool busy[481] = { 0 };
        for (int i = 0; i < events; i++) {
            getline(cin, appointment);
            start = appointment.substr(0, appointment.find(' '));
            appointment = appointment.substr(appointment.find(' ') + 1);
            end = appointment.substr(0, appointment.find(' '));
            startTime = stoi(start.substr(0, start.find(':'))) * 60 + stoi(start.substr(start.find(':') + 1)) - 600;
            endTime = stoi(end.substr(0, end.find(':'))) * 60 + stoi(end.substr(end.find(':') + 1)) - 600;

            for (int j = startTime; j < endTime; j++) {
                busy[j + 1] = true;
            }
        }

        int snapTime[481] = { 0 };
        int longest = 0, startToSleep = 0;
        for (int i = 1; i <= 480; i++) {
            if (!busy[i]) {
                snapTime[i] = snapTime[i - 1] + 1;
                if (snapTime[i] > longest) {
                    longest = snapTime[i];
                    startToSleep = i - snapTime[i] + 600;
                }
            }
        }
        cout << "Day #" << ++days << ": the longest nap starts at ";
        cout << startToSleep / 60 << ":" << setfill('0') << setw(2) << startToSleep % 60;
        cout << " and will last for ";
        if (longest < 60) {
            cout << longest << " minutes." << endl;
        }
        else {
            cout << longest / 60 << " hours and " << longest % 60 << " minutes." << endl;
        }
    }
    return 0;
}