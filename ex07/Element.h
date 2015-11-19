// Your .h file here
#ifndef ELEMENT_H
#define ELEMENT_H

class Element {
  private:
  	char*	strptr_;

  	void _copyFrom(const Element &other);

  public:
  	Element(const char* strptr);
  	Element(const Element &other);
  	~Element();
  	char* toString();
  	Element &operator=(const Element &other);
  	int operator==(const Element &other);
};

#endif // ELEMENT_H