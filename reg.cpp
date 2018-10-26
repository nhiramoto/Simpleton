#include "reg.hpp"

using namespace std;

Reg::Reg() {
	set(0);
}

Reg::Reg(int valor) {
	set(valor);
}

void Reg::set(int val) {
	if(val < -Reg::TAMREG)
		cerr << "Reg: Underflow";
	else if(val > Reg::TAMREG)
		cerr << "Reg: Overflow";
	else valor = val;
}

int Reg::get() const {
	return valor;
}

void Reg::exibir() const {
	printf("%3d", valor);
}

const Reg operator +(const Reg &reg1, const Reg &reg2) {
	return reg1.valor + reg2.valor;
}

const Reg operator -(const Reg &reg1, const Reg &reg2) {
	return reg1.valor - reg2.valor;
}

const Reg operator /(const Reg &reg1, const Reg &reg2) {
	if(reg2.valor == 0) cerr << "Erro fatal: Tentativa de divisão por zero." << endl;
	else return reg1.valor / reg2.valor;
}

const Reg Reg::operator ++() {
	valor++;
	return Reg(valor);
}

const Reg Reg::operator ++(int x) {
	int tmp = valor;
	valor++;
	return Reg(tmp);
}

const Reg Reg::operator --() {
	valor--;
	return Reg(valor);
}

const Reg Reg::operator --(int x) {
	int tmp = valor;
	valor--;
	return Reg(tmp);
}

const bool operator ==(const Reg &reg1, const Reg &reg2) {
	return reg1.valor == reg2.valor;
}

std::ostream& operator <<(std::ostream &output, const Reg &reg) {
	output << reg.valor;
	return output;
}