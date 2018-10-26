#include "memoria.hpp"

using namespace std;

Memoria::Memoria() {
	const int tam = 100;

	tamanho = tam;
	cells = new int[tam];
	reset();
}

Memoria::Memoria(const Memoria &modelo) {
	tamanho = modelo.tamanho;
	cells = new int[tamanho];
}

Memoria::Memoria(int tam) {
	if(tam <= 0) {
		cerr << "Memoria(): Tamanho de memoria invalido";
		exit(EXIT_FAILURE);
	}

	tamanho = tam;
	cells = new int[tam];
	reset();
}

Memoria::~Memoria() {
	delete [] cells;
}

void Memoria::reset() {
	for( int i = 0 ; i < tamanho ; i++ )
		*(cells + i) = 0;
}

void Memoria::store(int endereco, int valor) {
	if(endereco >= 0 && endereco < tamanho) {
		if(valor <= Memoria::TAMPALAVRA)
			*(cells + endereco) = valor;
		else cerr << "Memoria::store(): Tamanho da palavra excedido\n";
	} else cerr << "Memoria::store(): Endereco invalido\n";
}

int Memoria::load(int endereco) const {
	if(endereco >= 0 && endereco < tamanho)
		return(*(cells + endereco));
	else cerr << "Memoria::load(): Endereco invalido\n";
}

void Memoria::exibir() const {
	const int NUM_LIN = tamanho / 5;
	cout.width(4);
	cout.setf(ios::showpos);
	cout.fill('*');
	cout << "===============< MEMORIA >===============\n"
		 << "\tTamanho: " << tamanho << endl;
	int LIM = tamanho < NUM_LIN ? tamanho : NUM_LIN;
	for( int i = 0 ; i < LIM ; i++ ) {
    	int pos = i;
    	while(pos <= tamanho) {
    		cout << *(cells + pos) << "\t";
    		pos += NUM_LIN;
    	}
    	cout << endl;
	}
	cout << "\n=========================================\n";
}

int Memoria::getTamanho() const {
	return(tamanho);
}

ostream& operator <<(ostream &output, const Memoria &mem) {
	const int NUM_LIN = mem.tamanho / 5;
	output.width(4);
	output.setf(ios::showpos);
	output.fill('0');
	output << "===============< MEMORIA >===============\n"
		 << "\tTamanho: " << mem.tamanho << endl;
	const int LIM = mem.tamanho < NUM_LIN ? mem.tamanho : NUM_LIN;
    for( int i = 0 ; i < LIM ; i++ ) {
    	int pos = i;
    	while(pos <= mem.tamanho) {
    		output << *(mem.cells + pos) << "\t";
    		pos += NUM_LIN;
    	}
    	output << endl;
	}
	output << "\n=========================================\n";
}