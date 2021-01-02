#include<iostream>
using namespace std;

int main() {
    int length;
    while (cin >> length && length) {
        int max = 0, sum = 0, current;
        for (int i = 0; i < length; i++) {
            cin >> current;
            if (sum > 0) {
                sum = current + sum;
            }
            else {
                sum = current;
            }
            max = max > sum ? max : sum;
        }
        if (max == 0) {
            cout << "Losing streak." << endl;
        }
        else {
            cout << "The maximum winning streak is " << max << "." << endl;
        }
    }
    return 0;
}