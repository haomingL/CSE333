#include "Element.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

// Your code here
Element::Element(const char* other) {
	this->strptr_ = strdup(other);
	if (this->strptr_) exit (EXIT_FAILURE);
}

Element::Element(const Element &other) : strptr_(NULL){
	_copyFrom(other);
}

void Element::_copyFrom(const Element &other) {
  // if the strdup() fails, leave this Element object unchanged
  char* strCopy = strdup(other.strptr_);
  if(strCopy) {
    if (this->strptr_) free(strptr_);
    this->strptr_ = strCopy;
  }
}

Element &Element::operator=(const Element &other) {
  _copyFrom(other);
  return *this;
}

int Element::operator==(const Element &other) {
	int result;
	result = strcmp(this->strptr_, other.strptr_);
	return !result;
}

char* Element::toString() {
	return this->strptr_;
}

Element::~Element() {
	free(strptr_);
}