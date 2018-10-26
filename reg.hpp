#ifndef _REG_HPP_
#define _REG_HPP_

#include <iostream>
#include <cstdlib>
#include <cstdio>

class Reg {
public:
	Reg();
	Reg(int valor);
	void set(int val);
	int get() const;
	void exibir() const;
	friend const Reg operator +(const Reg &reg1, const Reg &reg2);
	friend const Reg operator -(const Reg &reg1, const Reg &reg2);
	friend const Reg operator /(const Reg &reg1, const Reg &reg2);
	const Reg operator ++();
	const Reg operator ++(int);
	const Reg operator --();
	const Reg operator --(int);
	friend const bool operator ==(const Reg &reg1, const Reg &reg2);
	friend std::ostream& operator <<(std::ostream &output, const Reg &reg);
	static const int TAMREG = 9999;
private:
	int valor;
};

#endif