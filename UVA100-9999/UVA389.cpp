#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;


int main() {
	string before;
	int prev, last;
	while (cin >> before >> prev >> last) {
		long long num = 0;
		int power = 0;
		for (int i = before.size() - 1; i >= 0; i--) {
			char digit = before[i];
			if (digit <= '9' && digit >= '0') {
				digit -= '0';
			}
			else {
				digit -= 'A' - 10;
			}
			
			num += int(digit * pow(prev, power++));
		}

		string after;
		while (num > 0) {
			int temp = num % last;
			if (temp < 10) {
				after += temp + '0';
			}
			else {
				after += temp + 'A' - 10;
			}
			num /= last;
		}
		if (after.size() > 7) {
			cout << setw(7) << "ERROR" << endl;
		}
		else if (after.empty()) {
			cout << setw(7) << 0 << endl;
		}
		else {
			reverse(after.begin(), after.end());
			cout << setw(7) << after << endl;
		}
	}
	return 0;
}