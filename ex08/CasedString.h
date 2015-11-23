/*
 * Copyright 2014 Steven Gribble, John Zahorjan
 *
 *  This file is part of the UW CSE 333 course project exercises.
 *  (333exer).
 *
 *  333exer is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  333exer is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 333proj.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CASEDSTRING_H
#define CASEDSTRING_H

#include <string>
#include <cctype>

class CasedString {
 private:
  std::string *str_;

 public:

  //-----------------------------------------------------------
  // You implement these, in file CasedString.cc
  //-----------------------------------------------------------

  // Empty constructor sets set_ to nullptr
  CasedString();

  // One-arg constructor (sets str_ to a string with value equal to str)
  CasedString(const std::string str);

  // Destructor deletes str_
  virtual ~CasedString();

  // The copy constructor
  CasedString(const CasedString &other);

  // The copy assignment operator
  CasedString &operator=(const CasedString &str);

  // The move constructor
  CasedString(CasedString &&other) noexcept;

  // The move assignment operator.
  CasedString &operator=(CasedString &&str);

  //-----------------------------------------------------------
  // I have implemented these (right here)
  //-----------------------------------------------------------

  // Accessor -- returns the string pointed at by str_, if str_ isn't null.
  //   Otherwise returns string with value "null".
  const std::string get() const { return str_ ? *str_ : "null"; }

  // Returns a copy of this CasedString, but with all alpha characters
  // converted to uppercase, using toupper from #include <cctype>
  CasedString UppercaseCopy() const {
    auto result(*this);
    for ( auto & el : *result.str_ )
      el = toupper(el);
    return result;
  }

  // Returns a copy of this CasedString, but with all alpha characters
  // converted to lowercase, using tolower from #include <cctype>
  CasedString LowercaseCopy() const {
    auto result(*this);
    for ( auto &el : *result.str_ )
      el = tolower(el);
    return result;
  }
};

#endif  // CASEDSTRING_H

