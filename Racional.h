#pragma once
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostream;
using std::stringstream;

class Racional{
	int numerador;
	int denominador;
	
public:
	Racional(int,int);
	Racional(const Racional&);
	~Racional();
	Racional operator+(const Racional&)const;
	Racional operator-(const Racional&)const;
	Racional operator*(const Racional&)const;
	Racional operator/(const Racional&)const;
	friend ostream& operator<< (ostream&, const Racional&);
};



