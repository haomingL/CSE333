// Haoming Liu
// 1332998

#include <iostream>
#include <cstdlib>
#include "CasedString.h"

using namespace std;

CasedString::CasedString() {
	cout << "	Default constructor()" << endl;
	str_ = nullptr;
}

// One-arg constructor (sets str_ to a string with value equal to str)
CasedString::CasedString(const std::string str) {
	cout << "	Constructor(" << str << ")" << endl;
	this->str_ = new string(str);
}

// Destructor deletes str_
CasedString::~CasedString() {
	if (this->str_) {
		cout << "	Destructor(" << *(this->str_) << ")" << endl;
		delete this->str_;
	}	
	else {
		cout << "	Destructor(null)" << endl;
	}
	this->str_ = nullptr;
}

// The copy constructor
CasedString::CasedString(const CasedString &other) : str_(nullptr) {
	cout << "	Copy constructor(" << *(other.str_) << ")" << endl;
	string* stringCopy = new string(*(other.str_));
	if (this->str_) delete this->str_;
	this->str_ = stringCopy;
	stringCopy = nullptr;
}

// The copy assignment operator
CasedString &CasedString::operator=(const CasedString &str) {
	cout << "	Copy assign(" << *(str.str_) << ")" << endl;
	string* stringCopy = new string(*(str.str_));
	if (this->str_) delete this->str_;
	this->str_ = stringCopy;
	stringCopy = nullptr;
	return *this;
}

// The move constructor
CasedString::CasedString(CasedString &&other) noexcept : str_(nullptr) {
	cout << "	Move constructor(" << *(other.str_) << ")" << endl;
	if (this->str_) delete this->str_;
	this->str_ = other.str_;
	other.str_ = nullptr;
}

// The move assignment operator.
CasedString &CasedString::operator=(CasedString &&str) {
	cout << "	Move assign(" << *(str.str_) << ")" << endl;
	if (this != &str) {
	  if (this->str_) delete this->str_;
      this->str_ = str.str_;
      str.str_ = nullptr;
   }
   return *this;
}
