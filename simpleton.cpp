#include "simpleton.hpp"

using namespace std;

Simpleton::Simpleton() : acum(0), contInst(0),
			 regInst(0), operando(0) {
	memoria = new Memoria(TAM_MEMORIA);
	fHalt = false;
}

Simpleton::Simpleton(const Simpleton &modelo) {
	acum = modelo.acum;
	contInst = modelo.contInst;
	regInst = modelo.regInst;
	operando = modelo.operando;
	fHalt = modelo.fHalt;
	memoria = new Memoria(*modelo.memoria);
}

Simpleton::~Simpleton() {
	delete memoria;
}

void Simpleton::read(int endereco) {
	int in;
	cout << "Insira um(proximo) numero:\n> ";
	cin >> in;
	acum.set(in);
	store(endereco);
}

void Simpleton::write(int endereco) {
	load(endereco);
	acum.exibir();
	cout << endl;
}

void Simpleton::load(int endereco) {
	acum.set(memoria->load(endereco));
}

void Simpleton::store(int endereco) {
	memoria->store(endereco, acum.get());
}

void Simpleton::add(int endereco) {
	acum.set(acum.get() + memoria->load(endereco));
}

void Simpleton::subtract(int endereco) {
	acum.set(acum.get() - memoria->load(endereco));
}

void Simpleton::divide(int endereco) {
	int div = memoria->load(endereco);
	if(div != 0) acum.set(acum.get() / div);
	else {
		cerr << "divide(): Erro fatal - Tentativa de divisão por zero.\n";
		acum.set(0);
	}
}

void Simpleton::multiply(int endereco) {
	acum.set(acum.get() * memoria->load(endereco));
}

void Simpleton::branch(int endereco) {
	if(endereco >= 0)
		contInst = endereco;
	else
		cerr << "branch(): Endereco invalido";
}

void Simpleton::branchNeg(int endereco) {
	if(acum.get() < 0)
		branch(endereco);
}

void Simpleton::branchZero(int endereco) {
	if(acum.get() == 0)
		branch(endereco);
}

void Simpleton::halt() {
	fHalt = true;
}

void Simpleton::reset() {
	memoria->reset();
	acum.set(0);
	contInst.set(0);
	regInst.set(0);
	operando.set(0);
	fHalt = false;
}

void Simpleton::executaPrograma(const string programa) {
	reset();

	if(!carregaPrograma(programa)) return;
	while(!fHalt) {
		executaComando(memoria->load(contInst.get()));
		contInst++;
	}
}

void Simpleton::executaComando(string comando) {
	regInst.set(stringToInt(comando));
	operando.set(regInst.get() % 100);
	int opcode = regInst.get() / 100;
	switch(opcode) {
		case READ: 		 read(operando.get());
			break;
		case WRITE: 	 write(operando.get());
			break;
		case LOAD: 		 load(operando.get());
			break;
		case STORE: 	 store(operando.get());
			break;
		case ADD: 		 add(operando.get());
			break;
		case SUBTRACT: 	 subtract(operando.get());
			break;
		case DIVIDE: 	 divide(operando.get());
			break;
		case MULTIPLY: 	 multiply(operando.get());
			break;
		case BRANCH:  	 branch(operando.get());
			break;
		case BRANCHNEG:  branchNeg(operando.get());
			break;
		case BRANCHZERO: branchZero(operando.get());
			break;
		case HALT: 		 halt();
			break;
	}
}

bool Simpleton::carregaPrograma(const string arquivo) {
	ifstream prog;
	string instrucao;
	int cont = 0;
	prog.open(arquivo.c_str());
	if(prog.fail()) {
		cerr << "Erro na abertura do arquivo.\n";
		return false;
	}
	while(1) {
		getline(prog, instrucao);
		if(prog.eof()) break;
		memoria->store(cont, stringToInt(instrucao));
		cont++;
	}
	prog.close();
	return true;
}

const Memoria& Simpleton::getMemoria() const {
	return *memoria;
}

int Simpleton::getAcum() const {
	return acum.get();
}

ostream& operator <<(ostream &output, const Simpleton &comp) {
	output.setf(ios::showpos);
	output << "Acumulador: " << comp.acum << endl;
	output << "Contador de Instrucoes: " << comp.contInst << endl;
	output << "Registrador de Instrucoes: " << comp.regInst << endl;
	output << "Operando: " << comp.operando << endl;
	output << comp.getMemoria();
	output << endl;
	return output;
}

void Simpleton::dump() const {
	cout << *this << endl;
}

void Simpleton::printMem() const {
	cout << *memoria << endl;
}