#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long LL;

class BigInteger {
	friend ostream& operator<<(ostream&, const BigInteger&);
	friend BigInteger pow(const BigInteger&, const BigInteger&);
public:
	BigInteger(LL = 0);
	BigInteger(string);
	BigInteger(const BigInteger&);
	virtual ~BigInteger();
	const BigInteger& operator=(const BigInteger&);

	const BigInteger operator+(const BigInteger&) const;
	const BigInteger operator-(const BigInteger&) const;
	const BigInteger operator*(const BigInteger&) const;
	const BigInteger operator/(const BigInteger&) const;
	const BigInteger operator%(const BigInteger&) const;
	const BigInteger operator-() const;

	bool operator==(const BigInteger&) const;
	bool operator!=(const BigInteger&) const;
	bool operator>(const BigInteger&) const;
	bool operator<(const BigInteger&) const;
	int& operator[](size_t);
	int operator[](size_t) const;

	bool getSign() const;

	const static int DIGIT_PER_ELEMENT = 3;
	const static int MAX_NUMBER = 1000;
private:
	void resize(size_t);
	void reserve(size_t);
	void checkCarry();
	void checkBorrow();
	void setString(string);

	size_t capacity_;
	size_t size_;
	int* arr_;
};

BigInteger::BigInteger(LL bignum) :size_(0), capacity_(10) {
	arr_ = new int[capacity_] {0};
	if (bignum == 0) {
		size_ = 1;
	}
	else {
		bool neg = false;
		if (bignum < 0) {
			bignum *= -1;
			neg = true;
		}
		while (bignum != 0) {
			(*this)[size_++] = bignum % BigInteger::MAX_NUMBER;
			bignum /= BigInteger::MAX_NUMBER;
		}

		if (neg) {
			(*this)[size_ - 1] *= -1;
		}
	}
}

BigInteger::BigInteger(string bignum) :size_(1), capacity_(10) {
	arr_ = new int[capacity_] {0};
	setString(bignum);
}

BigInteger::BigInteger(const BigInteger& other)
	: size_(other.size_), capacity_(other.capacity_)
{
	arr_ = new int[capacity_] {0};
	for (size_t i = 0; i < size_; i++) {
		(*this)[i] = other[i];
	}
}

BigInteger::~BigInteger() {
	delete[] arr_;
}

const BigInteger& BigInteger::operator=(const BigInteger& other) {
	if (*this != other) {
		if (capacity_ != other.capacity_) {
			delete[] arr_;
			capacity_ = other.capacity_;
			arr_ = new int[capacity_] { 0 };
		}
		size_ = other.size_;
		for (size_t i = 0; i < size_; i++) {
			(*this)[i] = other[i];
		}
	}
	return *this;
}

const BigInteger BigInteger::operator+(const BigInteger& right) const {
	if (!getSign() && !right.getSign()) {
		return -(-*this + -right);
	}
	if (getSign() && !right.getSign()) {
		return *this - -right;
	}
	if (!getSign() && right.getSign()) {
		return right - -*this;
	}
	if (*this < right) {
		return right + *this;
	}

	BigInteger sum(*this);
	for (size_t i = 0; i < right.size_; i++) {
		sum[i] += right[i];
	}
	sum.checkCarry();
	return sum;
}

const BigInteger BigInteger::operator-(const BigInteger& right) const {
	if (!getSign() && !right.getSign()) {
		return -right - -*this;
	}
	if (getSign() && !right.getSign()) {
		return *this + -right;
	}
	if (!getSign() && right.getSign()) {
		return -(-*this + right);
	}
	if (*this < right) {
		return -(right - *this);
	}

	BigInteger difference(*this);
	for (size_t i = 0; i < right.size_; i++) {
		difference[i] -= right[i];
	}
	difference.checkBorrow();
	return difference;
}

const BigInteger BigInteger::operator*(const BigInteger& right) const {
	if (*this == 0 || right == 0) {
		return 0;
	}
	if (!getSign() && !right.getSign()) {
		return -*this * -right;
	}
	if (getSign() && !right.getSign()) {
		return -(*this * -right);
	}
	if (!getSign() && right.getSign()) {
		return -(-*this * right);
	}

	BigInteger product;
	product.resize(size_ + right.size_);
	for (size_t i = 0; i < size_; i++) {
		for (size_t j = 0; j < right.size_; j++) {
			product[i + j] += (*this)[i] * right[j];
		}
	}
	product.checkCarry();
	return product;
}

const BigInteger BigInteger::operator/(const BigInteger& right) const {
	if (!getSign() && !right.getSign()) {
		return -*this / -right;
	}
	if (getSign() && !right.getSign()) {
		return -(*this / -right);
	}
	if (!getSign() && right.getSign()) {
		return -(-*this / right);
	}
	if (*this == 0 || right == 0 || *this < right) {
		return 0;
	}

	BigInteger quotient(*this);
	for (int i = size_ - 1; i >= 1; i--) {
		if (quotient[i] % 2 != 0) {
			quotient[i - 1] += BigInteger::MAX_NUMBER;
		}
		quotient[i] /= 2;
	}
	quotient[0] /= 2;
	quotient.checkBorrow();
	return quotient;
}

const BigInteger BigInteger::operator%(const BigInteger& right) const {
	if (!getSign() || !right.getSign() || *this == right) {
		return 0;
	}
	if (*this < right) {
		return *this;
	}
	BigInteger quotient = *this / right;
	BigInteger remainder = *this - (right * quotient);
	return remainder;
}

const BigInteger BigInteger::operator-() const {
	BigInteger temp(*this);
	temp[temp.size_ - 1] *= -1;
	return temp;
}

bool BigInteger::operator==(const BigInteger& other) const {
	if (size_ != other.size_) {
		return false;
	}

	for (size_t i = 0; i < size_; i++) {
		if ((*this)[i] != other[i]) {
			return false;
		}
	}
	return true;
}

bool BigInteger::operator!=(const BigInteger& other) const {
	return !(*this == other);
}

bool BigInteger::operator>(const BigInteger& other) const {
	if (getSign() && !other.getSign()) {
		return true;
	}
	if (!getSign() && other.getSign()) {
		return false;
	}
	if (getSign() && other.getSign()) {
		if (size_ != other.size_) {
			return size_ > other.size_;
		}
		else {
			for (int i = size_ - 1; i >= 0; i--) {
				if ((*this)[i] != other[i]) {
					return (*this)[i] > other[i];
				}
			}
			return false;
		}
	}
	else {
		if (size_ != other.size_) {
			return size_ < other.size_;
		}
		else {
			for (int i = size_ - 1; i >= 0; i--) {
				if ((*this)[i] != other[i]) {
					return (*this)[i] < other[i];
				}
			}
			return false;
		}
	}
}

bool BigInteger::operator<(const BigInteger& other) const {
	return !((*this == other) || (*this > other));
}

int& BigInteger::operator[](size_t index) {
	if (index < 0 || index >= size_) {
		throw "Error: Index " + to_string(index) + " out of range";
	}
	return arr_[index];
}

int BigInteger::operator[](size_t index) const {
	if (index < 0 || index >= size_) {
		throw "Error: Index " + to_string(index) + " out of range";
	}
	return arr_[index];
}

bool BigInteger::getSign() const {
	return (*this)[size_ - 1] >= 0;
}

void BigInteger::resize(size_t size) {
	if (size < size_) {
		for (size_t i = size_ - 1; i >= size; i--) {
			(*this)[i] = 0;
		}
	}
	else if (size > size_) {
		reserve(size);
	}
	size_ = size;
}

void BigInteger::reserve(size_t capacity) {
	if (capacity > capacity_) {
		while (capacity > capacity_) {
			capacity_ *= 2;
		}

		int* temp = new int[capacity_] {0};
		for (size_t i = 0; i < size_; i++) {
			temp[i] = (*this)[i];
		}
		delete[] arr_;
		arr_ = temp;
	}
}

void BigInteger::checkCarry() {
	for (size_t i = 0; i < size_ - 1; i++) {
		if ((*this)[i] >= BigInteger::MAX_NUMBER) {
			(*this)[i + 1] += (*this)[i] / BigInteger::MAX_NUMBER;
			(*this)[i] %= BigInteger::MAX_NUMBER;
		}
	}
	if ((*this)[size_ - 1] >= BigInteger::MAX_NUMBER) {
		resize(size_ + 1);
		(*this)[size_ - 1] += (*this)[size_ - 2] / BigInteger::MAX_NUMBER;
		(*this)[size_ - 2] %= BigInteger::MAX_NUMBER;
	}
	while (size_ > 1 && (*this)[size_ - 1] == 0) {
		size_--;
	}
}

void BigInteger::checkBorrow() {
	for (size_t i = 0; i < size_ - 1; i++) {
		if ((*this)[i] < 0) {
			(*this)[i + 1] -= 1;
			(*this)[i] += BigInteger::MAX_NUMBER;
		}
	}
	while (size_ > 1 && (*this)[size_ - 1] == 0) {
		size_--;
	}
}

void BigInteger::setString(string bignum) {
	if (bignum.empty()) {
		return;
	}

	bool neg = false;
	if (bignum[0] == '-') {
		bignum = bignum.substr(1);
		neg = true;
	}
	while (bignum.size() > 1 && bignum[0] == '0') {
		bignum = bignum.substr(1);
	}
	resize((bignum.size() + BigInteger::DIGIT_PER_ELEMENT - 1) / BigInteger::DIGIT_PER_ELEMENT);

	int pos = 0;
	while (bignum.size() > BigInteger::DIGIT_PER_ELEMENT) {
		(*this)[pos++] = stoi(bignum.substr(bignum.size() - BigInteger::DIGIT_PER_ELEMENT));
		bignum = bignum.substr(0, bignum.size() - BigInteger::DIGIT_PER_ELEMENT);
	}
	(*this)[pos] = stoi(bignum);

	if (neg) {
		(*this)[size_ - 1] *= -1;
	}
}

ostream& operator<<(ostream& output, const BigInteger& other)
{
	output << other[other.size_ - 1];
	for (int i = other.size_ - 2; i >= 0; i--) {
		output << setw(BigInteger::DIGIT_PER_ELEMENT) << setfill('0') << other[i];
	}
	return output;
}

BigInteger pow(const BigInteger& base, const BigInteger& power) {
	if (power < 1) {
		return BigInteger(1);
	}

	BigInteger temp(power);
	string s;
	while (temp > 0) {
		if (temp % 2 == 0) {
			s += "0";
		}
		else {
			s += "1";
		}
		temp = temp / 2;
	}

	BigInteger product(base);
	for (int i = s.size() - 2; i >= 0; i--) {
		product = product * product;
		if (s[i] == '1') {
			product = product * base;
		}
	}
	return product;
}


int main() {
	string formula;
	map<char, int> precedence;
	precedence['+'] = 1;
	precedence['*'] = 2;
	precedence['$'] = 3;
	while (cin >> formula) {
		vector<char> ops;
		vector<BigInteger> numbers;
		for (size_t i = 0; i < formula.size() - 1; i++) {
			if (formula[i] == '*' && formula[i + 1] == '*') {
				formula = formula.replace(i, 2, "$");
			}
		}

		bool neg = false;
		while (!formula.empty()) {
			char first = formula[0];
			if (first >= '0' && first <= '9') {
				for (size_t i = 0; i <= formula.size(); i++) {
					if (i == formula.size() || formula[i] < '0' || formula[i] > '9') {
						if (neg) {
							numbers.push_back(-BigInteger(formula.substr(0, i)));
							neg = false;
						}
						else {
							numbers.push_back(BigInteger(formula.substr(0, i)));
						}
						formula = formula.substr(i);
						break;
					}
				}
			}
			else {
				if (first == '-') {
					first = '+';
					neg = true;
				}
				if (ops.empty()) {
					ops.push_back(first);
					formula = formula.substr(1);
				}
				else {
					if (precedence[ops.back()] > precedence[first]) {
						char op = ops.back();
						ops.pop_back();
						BigInteger b2 = numbers.back();
						numbers.pop_back();
						BigInteger b1 = numbers.back();
						numbers.pop_back();
						if (op == '*') {
							numbers.push_back(b1 * b2);
						}
						else {
							numbers.push_back(pow(b1, b2));
						}
					}
					else {
						ops.push_back(first);
						formula = formula.substr(1);
					}
				}
			}
		}

		while (!ops.empty()) {
			char op = ops.back();
			ops.pop_back();
			BigInteger b2 = numbers.back();
			numbers.pop_back();
			BigInteger b1 = numbers.back();
			numbers.pop_back();

			if (op == '+') {
				numbers.push_back(b1 + b2);
			}
			else if (op == '*') {
				numbers.push_back(b1 * b2);
			}
			else {
				numbers.push_back(pow(b1, b2));
			}
		}
		cout << numbers.back() << endl;
	}
	return 0;
}