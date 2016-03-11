#pragma once
#include <iostream>
#include <string>
#include <stringstream>

using std::string;
using std::ostream;

class Racional{
	int numerador;
	int denominador;
	
public:
	Racional(int,int);
	~Racional();
	string operator+(const &Racional)const;
	string operator-(const &Racional)const;
	string operator*(const &Racional)const;
	string operator/(const &Racional)const;
	friend ostream& operator<<(ostream&, const Racional&);
};



