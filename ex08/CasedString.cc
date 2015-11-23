#include <iostream>
#include <cstdlib>
#include "CasedString.h"

using namespace std;

CasedString::CasedString() {
	cout << "	Default constructor()" << endl;
	str_ = NULL;
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
		free(this->str_)
	}	
	else {
		cout << "	Destructor(null)" << endl;
	}
	this->str_ = NULL;
}

// The copy constructor
CasedString::CasedString(const CasedString &other) : str_(NULL) {
	cout << "	Copy constructor(" << *(other.str_) << ")" << endl;
	this->str_ = new string(*(other.str_));
}

// The copy assignment operator
CasedString &CasedString::operator=(const CasedString &str) {
	cout << "	Copy assign(" << *(str.str_) << ")" << endl;
	this->str_ = new string(*(str.str_));
	return *this;
}

// The move constructor
CasedString::CasedString(CasedString &&other) noexcept : str_(NULL) {
	cout << "	Move constructor(" << *(other.str_) << ")" << endl;
	this->str_ = other.str_;
	other.str_ = NULL;
}

// The move assignment operator.
CasedString &CasedString::operator=(CasedString &&str) {
	cout << "	Move assign(" << *(str.str_) << ")" << endl;
	if (this != &str) {
      this->str_ = str.str_;
      str.str_ = NULL;
   }
   return *this;
}
