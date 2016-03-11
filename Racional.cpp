#include "Racional.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::cout;
using std::stringstream;
using std::ostream;
using std::showpos;
using std::noshowpos;

Racional::Racional(int numerador,int denominador){
	if(denominador==0){
		denominador=1;
	}else if(denominador<0){
		denominador*=-1;
		numerador*=-1;
	}

	int menor,divisor=2,negativo=1;;
	if(numerador<denominador){
		if(numerador<0){
			negativo=-1;
			numerador*=-1;
		}
		menor=numerador;
	}else{
		menor=denominador;
	}	
	while(divisor<=menor){
		if(numerador%divisor==0 && denominador%divisor==0){
			numerador/=divisor;
			denominador/=divisor;
		}else{
			divisor++;
		}
	}
	numerador*=negativo;
	this->numerador=numerador;
	this->denominador=denominador;
}

Racional::Racional(const Racional& copia){
	int numerador=copia.numerador;
	int denominador=copia.denominador;
	if(denominador==0){
		denominador=1;
	}else if(denominador<0){
		denominador*=-1;
		numerador*=-1;
	}
	int menor,divisor=2;
	if(numerador<denominador){
		menor=numerador;
	}else{
		menor=denominador;
	}	
	while(divisor<=menor){
		if(numerador%divisor==0 && denominador%divisor==0){
			numerador/=divisor;
			denominador/=divisor;
		}else{
			divisor++;
		}
	}
	this->numerador=numerador;
	this->denominador=denominador;
}

Racional::~Racional(){

}

Racional Racional::operator+(const Racional& operando)const{
	int den=(denominador*operando.denominador);
	int num=(numerador*operando.denominador + operando.numerador*denominador);
	return Racional(num,den);
}

Racional Racional::operator-(const Racional& operando)const{
	int den=(denominador*operando.denominador);
	int num=(numerador*operando.denominador - operando.numerador*denominador);
	return Racional(num,den);
}

Racional Racional::operator*(const Racional& operando)const{
	return Racional(numerador*operando.numerador , denominador*operando.denominador);
}

Racional Racional::operator/(const Racional& operando)const{
	if(operando.numerador==0){
		throw "No es posible la división entre 0";
	}
	return Racional(numerador*operando.denominador , denominador*operando.numerador);
}

ostream& operator<<(ostream& output, const Racional& operando){
	if (operando.denominador == 1){
		output << operando.numerador;
	}else{
		if(operando.numerador==0){
			output << "0"; 
		}else{
			output <<showpos<<operando.numerador << "/" <<noshowpos<<operando.denominador;
		}	
	}
	output << noshowpos;
	return output;	
}
