#include "mystring.h"
#include <cstring>
#include <istream>

using namespace stringexercise;

mystring::mystring() {
	occupied = 0;
	capacity = 1;
	sequence = new char[capacity] { '\0' };
}

mystring::mystring(const char str[]) {
	occupied = strlen(str);
	capacity = occupied + 1;

	// Initialize the sequence variable and copy the value of str to sequence.
	sequence = new char[capacity];
	strcpy(sequence, str);
}

mystring::mystring(const std::string str) {
	occupied = str.length();
	capacity = occupied + 1;
	sequence = new char[capacity];

	// Copy the string symbol by symbol and finish with the termination symbol.
	for (int i = 0; i < (signed)occupied; i++) {
		sequence[i] = str[i];
	}
	sequence[occupied] = '\0';

}

mystring::mystring(const mystring& source) {
	occupied = source.occupied;
	capacity = occupied + 1;
	sequence = new char[capacity];

	// Copy the string symbol by symbol and finish with the termination symbol.
	for (int i = 0; i < (signed)occupied; i++) {
		sequence[i] = source.sequence[i];
	}
	sequence[occupied] = '\0';
}

mystring::~mystring() {
	delete[] sequence;
}

mystring& mystring::operator+=(const mystring& addend) {
	occupied += addend.occupied;
	capacity = occupied + 1;

	char* temp = new char[capacity];
	strcpy(temp, sequence);

	delete[] sequence;

	strcat(temp, addend.sequence);
	sequence = temp;

	return *this;
}

mystring& mystring::operator+=(const char addend[]) {
	occupied += strlen(addend);
	capacity = occupied + 1;

	char* temp = new char[capacity];
	strcpy(temp, sequence);

	delete[] sequence;

	strcat(temp, addend);
	sequence = temp;

	return *this;
}

mystring& mystring::operator+=(const char addend) {
	occupied++;
	capacity = occupied + 1;

	char* temp = new char[capacity];
	strcpy(temp, sequence);

	delete[] sequence;

	temp[occupied - 1] = addend;
	temp[occupied] = '\0';
	sequence = temp;

	return *this;
}

mystring& mystring::operator=(const mystring& source) {
	if (this != &source) {
		occupied = source.occupied;
		capacity = source.capacity;

		delete[] sequence;

		sequence = new char[capacity];
		strcpy(sequence, source.sequence);

	}
	return *this;
}

const char& mystring::operator[](size_t position) const {
	if (position >= occupied) {
		throw std::out_of_range("The index position is out of range!");
	}

	return sequence[position];
}

char& mystring::operator[](size_t position) {
	if (position >= occupied) {
		throw std::out_of_range("The index position is out of range!");
	}

	return sequence[position];
}

void mystring::swap(mystring& str) {
	mystring temp = *this;
	*this = str;
	str = temp;
}

std::ostream& stringexercise::operator<<(std::ostream& outs, const mystring& source) {
	outs << source.sequence;
	return outs;
}

std::istream& stringexercise::operator>>(std::istream& ins, mystring& target) {
	int BUFFERSIZE = 100; // Initialize a buffer size variable for the getline method.

	// Delete the previous value of sequence.
	delete[] target.sequence;
	target.sequence = new char[BUFFERSIZE];

	// Get BUFFERSIZE characters from the buffer using the getline function.
	ins.getline(target.sequence, BUFFERSIZE);

	target.occupied = strlen(target.sequence);
	target.capacity = target.occupied + 1;

	return ins;
}

mystring stringexercise::operator+(const mystring& s1, const mystring& s2) {
	mystring str(s1);
	str += s2;
	return str;
}

mystring stringexercise::operator+(const mystring& s1, const char* s2) {
	mystring str(s1);
	str += s2;
	return str;
}

mystring stringexercise::operator+(const char* s1, const mystring& s2) {
	mystring str(s1);
	str += s2;
	return str;
}

bool stringexercise::operator==(const mystring& s1, const mystring& s2) {
	return strcmp(s1.sequence, s2.sequence) == 0;
}

bool stringexercise::operator!=(const mystring& s1, const mystring& s2) {
	return strcmp(s1.sequence, s2.sequence) != 0;
}

bool stringexercise::operator>=(const mystring& s1, const mystring& s2) {
	return strcmp(s1.sequence, s2.sequence) >= 0;
}

bool stringexercise::operator<=(const mystring& s1, const mystring& s2) {
	return strcmp(s1.sequence, s2.sequence) <= 0;
}

bool stringexercise::operator>(const mystring& s1, const mystring& s2) {
	return strcmp(s1.sequence, s2.sequence) > 0;
}

bool stringexercise::operator<(const mystring& s1, const mystring& s2) {
	return strcmp(s1.sequence, s2.sequence) < 0;
}