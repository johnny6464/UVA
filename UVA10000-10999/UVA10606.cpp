#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

typedef long long LL;
const LL Capacity = (LL)1e8;

struct BigInteger {
	int size;
	LL value[251];
	BigInteger() {
		size = 1;
		memset(value, 0, sizeof(value));
	}
};


int computeDigits(BigInteger& b) {
	int digits = (b.size - 1) * 8;
	LL highest = b.value[b.size];
	while (highest > 0) {
		highest /= 10;
		digits++;
	}
	return digits;
}

BigInteger stov(string s) {
	if (s.empty()) {
		return BigInteger();
	}

	BigInteger b;
	while (s.size() > 8) {
		b.value[b.size++] = stoi(s.substr(s.size() - 8));
		s = s.substr(0, s.size() - 8);
	}
	b.value[b.size] = stoi(s);
	return b;
}

void carry(BigInteger& b) {
	for (int i = 1; i <= b.size; i++) {
		if (b.value[i] >= Capacity) {
			if (i == b.size) {
				b.size++;
			}
			b.value[i + 1] += b.value[i] / Capacity;
			b.value[i] %= Capacity;
		}
	}
	while (b.value[b.size] == 0 && b.size > 1) {
		b.size--;
	}
}

BigInteger operator*(BigInteger& b1, BigInteger& b2) {
	BigInteger product;
	product.size = b1.size + b2.size;
	for (int i = 1; i <= b1.size; i++) {
		for (int j = 1; j <= b2.size; j++) {
			product.value[i + j - 1] += b1.value[i] * b2.value[j];
		}
	}
	carry(product);
	return product;
}

BigInteger operator/(const BigInteger& b, const int divisor) {
	BigInteger quotient(b);
	for (int i = 2; i <= quotient.size; i++) {
		if (quotient.value[i] % 2 != 0) {
			quotient.value[i - 1] += Capacity / 2;
			if (i == 2) {
				quotient.value[i - 1] += Capacity / 2;
			}
		}
		quotient.value[i] /= 2;
	}
	quotient.value[1] /= 2;
	carry(quotient);
	return quotient;
}

BigInteger operator+(BigInteger& b1, BigInteger& b2) {
	BigInteger sum;
	if (b1.size > b2.size) {
		sum = b1;
		for (int i = 1; i <= b2.size; i++) {
			sum.value[i] += b2.value[i];
		}
		carry(sum);
	}
	else {
		sum = b2;
		for (int i = 1; i <= b1.size; i++) {
			sum.value[i] += b1.value[i];
		}
		carry(sum);
	}
	return sum;
}

BigInteger operator+(BigInteger& b, const int number) {
	BigInteger sum(b);
	sum.value[1] += number;
	carry(sum);
	return sum;
}

BigInteger operator-(BigInteger& b, const int number) {
	BigInteger difference(b);
	difference.value[1] -= number;
	for (int i = 1; i <= difference.size; i++) {
		if (difference.value[i] < 0) {
			difference.value[i + 1] -= 1;
			difference.value[i] += Capacity;
		}
	}
	carry(difference);
	return difference;
}

bool operator==(const BigInteger& b1, const BigInteger& b2) {
	if (b1.size != b2.size) {
		return false;
	}
	else {
		for (int i = b1.size; i >= 1; i--) {
			if (b1.value[i] != b2.value[i]) {
				return false;
			}
		}
		return true;
	}
}


bool operator<(const BigInteger& b1, const BigInteger& b2) {
	if (b1.size != b2.size) {
		return b1.size < b2.size;
	}
	else {
		for (int i = b1.size; i >= 1; i--) {
			if (b1.value[i] != b2.value[i]) {
				return b1.value[i] < b2.value[i];
			}
		}
		return false;
	}
}

BigInteger SquareRoot(BigInteger& b) {
	BigInteger low = stov(string((computeDigits(b) - 1) / 2, '9'));
	BigInteger high = stov(string((computeDigits(b) + 1) / 2, '9'));
	high = high + 1;
	BigInteger mid = (low + high) / 2;
	BigInteger square = mid * mid;
	while (low < high) {
		if (square == b) {
			break;
		}
		else {
			if (square < b) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
			mid = (low + high) / 2;
			square = mid * mid;
		}
	}
	if (b < square) {
		mid = mid - 1;
	}
	return mid * mid;
}

int main() {
	string bignum;
	while (cin >> bignum && bignum != "0") {
		BigInteger Y = stov(bignum);
		BigInteger X = SquareRoot(Y);

		cout << X.value[X.size];
		for (int i = X.size - 1; i >= 1; i--) {
			cout << setw(8) << setfill('0') << right << X.value[i];
		}
		cout << endl;
	}
	return 0;
}