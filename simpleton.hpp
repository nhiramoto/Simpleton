#ifndef _SIMPLETON_HPP_
#define _SIMPLETON_HPP_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "memoria.hpp"
#include "glob.hpp"
#include "reg.hpp"

#define TAM_MEMORIA		100

//----------------- Operações ------------------//

#define READ        10
#define WRITE       11
#define LOAD        20
#define STORE       21
#define ADD         30
#define SUBTRACT    31
#define DIVIDE      32
#define MULTIPLY    33
#define BRANCH      40
#define BRANCHNEG   41
#define BRANCHZERO  42
#define HALT        43

//---------------------------------------------//

using namespace std;

class Simpleton {
public:
	Simpleton();
	Simpleton(const Simpleton &modelo);
	~Simpleton();
	void read(int endereco);
	void write(int endereco);
	void load(int endereco);
	void store(int endereco);
	void add(int endereco);
	void subtract(int endereco);
	void divide(int endereco);
	void multiply(int endereco);
	void branch(int endereco);
	void branchNeg(int endereco);
	void branchZero(int endereco);
	void halt();
	void reset();
	void executaPrograma(const string programa);
	void executaComando(string comando);
	bool carregaPrograma(const string arquivo);
	const Memoria& getMemoria() const;
	int getAcum() const;
	friend ostream& operator <<(ostream &output, const Simpleton &comp);
	void dump() const;
	void printMem() const;
private:
	Memoria *memoria;
	Reg acum,		// acumulador
		contInst,	// contador de instruções
		regInst,	// registrador de instruções
		operando;	// operando da instrução
	bool fHalt;
};

#endif