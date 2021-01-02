#include<iostream>
#include<vector>
using namespace std;

int main() {
    int problem, cases = 0;
    int produce[12], consume[12];
    while (cin >> problem && problem >= 0) {
        for (int i = 0; i < 12; i++) {
            cin >> produce[i];
        }
        for (int i = 0; i < 12; i++) {
            cin >> consume[i];
        }

        cout << "Case " << ++cases << ":" << endl;
        for (int i = 0; i < 12; i++) {
            if (problem >= consume[i]) {
                cout << "No problem! :D" << endl;
                problem -= consume[i];
            }
            else {
                cout << "No problem. :(" << endl;
            }
            problem += produce[i];
        }
    }
    return 0;
}