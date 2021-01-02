#include<iostream>
using namespace std;

int main() {
    int cases, stops;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        cin >> stops;
        int max = 0, sum = 0, start = 1, bestStart = 0, bestEnd = 0, current;
        for (int i = 1; i < stops; i++) {
            cin >> current;
            if (sum >= 0) {
                sum = current + sum;
            }
            else {
                start = i;
                sum = current;
            }
            
            if (sum > max || sum == max && i + 1 - start > bestEnd - bestStart) {
                max = sum;
                bestStart = start;
                bestEnd = i + 1;
            }
        }
        if (max == 0) {
            cout << "Route " << i << " has no nice parts" << endl;
        }
        else {
            cout << "The nicest part of route " << i << " is between stops " << bestStart << " and " << bestEnd << endl;
        }
    }
    return 0;
}