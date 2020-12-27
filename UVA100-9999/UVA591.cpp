#include<iostream>
#include<vector>
using namespace std;

int main() {
    int stacks;
    int cases = 0;
    while (cin >> stacks && stacks) {
        int sum = 0;
        vector<int> bricks(stacks, 0);
        for (int i = 0; i < stacks; i++) {
            cin >> bricks[i];
            sum += bricks[i];
        }

        int avg = sum / stacks, moves = 0;
        for (int i = 0; i < stacks; i++) {
            if (bricks[i] < avg) {
                moves += avg - bricks[i];
            }
        }
        cout << "Set #" << ++cases << endl;
        cout << "The minimum number of moves is " << moves << "." << endl << endl;
    }
    return 0;
}