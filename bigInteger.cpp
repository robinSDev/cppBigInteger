#include <iostream>
#include <vector>
using namespace std;

class BigInteger {

public:
	vector<short> number;

	BigInteger();

	BigInteger(size_t integer);

	unsigned int size() const;

	void setLength(unsigned int len);

	void setNumber(vector<short>& v);

	vector<short>& getNumber();

	BigInteger& operator = (size_t& integer);

	//BigInteger& operator = (BigInteger& b);

	BigInteger operator + (BigInteger& b);
};

std::ostream& operator << (std::ostream& os, BigInteger& a);

BigInteger::BigInteger() {
}

BigInteger::BigInteger(size_t integer) {
	while (integer) {
		number.push_back(integer % 10);
		integer /= 10;
	}
}

unsigned int BigInteger::size() const {
	return number.size();
}

void BigInteger::setLength(unsigned int len)
{
	vector<short> temp(len, 0);
	number = temp;
}

void BigInteger::setNumber(vector<short>& vec)
{
	number = vec;
}

vector<short>& BigInteger::getNumber() {
	return number;
}

BigInteger& BigInteger::operator = (size_t& integer) {
	while (integer) {
		number.push_back(integer % 10);
		integer /= 10;
	}
	return *this;
}
/*
BigInteger& BigInteger::operator = (BigInteger& b) {
	this->number = b.getNumber();
	return *this;
}*/

BigInteger BigInteger::operator + (BigInteger& secondNum) {
	unsigned int shorterLen, longerLen;

	if (this->size() < secondNum.size()) {
		shorterLen = this->size();
		longerLen = secondNum.size();
	}
	else {
		shorterLen = secondNum.size();
		longerLen = this->size();
	}

	const vector<short>& a = this->getNumber(), &b = secondNum.getNumber();
	const vector<short>& longer = this->size() > secondNum.size() ? this->getNumber() : secondNum.getNumber();
	vector<short> result(longerLen);


	short carry = 0;
	for (unsigned int i = 0; i < shorterLen; ++i) {
		short temp = a[i] + b[i] + carry;
		if (temp > 9) {
			carry = temp / 10;
			temp %= 10;
		}
		else
			carry = 0;
		result[i] = temp;
		//result.push_back(temp);
	}
	for (unsigned int i = shorterLen; i < longerLen; ++i) {
		short temp = longer[i] + carry;
		if (temp > 9) {
			carry = temp / 10;
			temp %= 10;
		}
		else
			carry = 0;
		result[i] = temp;
		//result.push_back(temp);
	}
	if (carry > 0)
		result.push_back(carry);
	BigInteger c;
	c.setNumber(result);
	return c;
}

std::ostream& operator << (std::ostream& os, BigInteger& a) {
	vector<short>& v = a.getNumber();
	for (vector<short>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i)
		os << *i;
	return os;
}

bool operator < ()

void fib(size_t n) {
	BigInteger a = 0;
	BigInteger b = 1;
	BigInteger result = 0;
	BigInteger c = 0;
	while (c < n) {
		if (!(c.getNumber()[0] % 2))
		{
		    result = result + c;
			cout << c << " ";
		}
		a = b;
		b = c;
	}
	cout << "\n" << result << "\n";
}
int main() {
	fib(100);
	return 0;
}
