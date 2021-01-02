#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin.ignore();
        cin.ignore();

        vector<int> order;
        vector<string> sequence;
        int temp1;
        string temp2;
        while (cin.peek() != '\n') {
            cin >> temp1;
            order.push_back(temp1);
        }
        cin.ignore();
        while (cin.peek() != '\n') {
            cin >> temp2;
            sequence.push_back(temp2);
        }

        map<int, string> permuatation;
        for (int i = 0; i < order.size(); i++) {
            permuatation[order[i]] = sequence[i];
        }

        for (auto iter = permuatation.begin(); iter != permuatation.end(); iter++) {
            cout << iter->second << endl;
        }
        if (cases) {
            cout << endl;
        }
    }
    return 0;
}