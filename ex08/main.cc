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

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

#include "CasedString.h"

int main(int argc, char **argv) {
  cout << "-----------------------------------------" << endl;
  CasedString s("Test string!");
  cout << "1. string: " << s.get() << endl;
  cout << "-----------------------------------------" << endl;

  cout << "2. upper string: " << s.UppercaseCopy().get() << endl;
  cout << "-----------------------------------------" << endl;

  cout << "3. upper lower string: "
       << s.UppercaseCopy().LowercaseCopy().get()
       << endl;
  cout << "-----------------------------------------" << endl;

  CasedString y;
  y = s;
  cout << "4. copy assigned copy: " << y.get() << endl;
  cout << "-----------------------------------------" << endl;

  y = s.LowercaseCopy();
  cout << "5. move assigned copy: " << y.get() << endl;
  cout << "-----------------------------------------" << endl;

  // test copy assignment
  y = y;
  cout << "6. self-assign: " << y.get() << endl;
  cout << "-----------------------------------------" << endl;

  cout << "7. exit main" << endl;
  return EXIT_SUCCESS;
}
