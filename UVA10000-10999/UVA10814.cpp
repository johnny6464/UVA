#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;

class BigInteger {
	friend ostream& operator<<(ostream&, const BigInteger&);
	friend BigInteger gcd(const BigInteger&, const BigInteger&);
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

	int getDigits() const;
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
		while (bignum != 0) {
			(*this)[size_++] = bignum % BigInteger::MAX_NUMBER;
			bignum /= BigInteger::MAX_NUMBER;
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
	if (right == 2) {
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

	BigInteger low, high;
	int digitsDifference = getDigits() - right.getDigits();
	if (digitsDifference == 0) {
		low = 1;
		high = 9;
	}
	else {
		low = "1" + string(digitsDifference - 1, '0');
		high = string(digitsDifference + 1, '9');
	}
	BigInteger mid = (low + high) / 2;
	BigInteger product = mid * right;
	while (low < high) {
		if (product == *this) {
			break;
		}
		else {
			if (product < *this) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}
		mid = (low + high) / 2;
		product = mid * right;
	}
	if (product > * this) {
		mid = mid - 1;
	}
	return mid;
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

int BigInteger::getDigits() const {
	int digits = (size_ - 1) * BigInteger::DIGIT_PER_ELEMENT;
	int highest = (*this)[size_ - 1];
	while (highest > 0) {
		highest /= 10;
		digits++;
	}
	return digits;
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
}

ostream& operator<<(ostream& output, const BigInteger& other)
{
	output << other[other.size_ - 1];
	for (int i = other.size_ - 2; i >= 0; i--) {
		output << setw(BigInteger::DIGIT_PER_ELEMENT) << setfill('0') << other[i];
	}
	return output;
}

BigInteger gcd(const BigInteger& left, const BigInteger& right) {
	BigInteger temp1(left), temp2(right), temp3;
	while (temp1 % temp2 != 0) {
		temp3 = temp1;
		temp1 = temp2;
		temp2 = temp3 % temp2;
	}
	return temp2;
}


int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		string temp;
		cin >> temp;
		BigInteger b1(temp);
		cin >> temp >> temp;
		BigInteger b2(temp);
		BigInteger b3 = gcd(b1, b2);
		cout << (b1 / b3) << " / " << (b2 / b3) << endl;
	}
	return 0;
}