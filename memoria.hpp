#ifndef _MEMORIA_H_
#define _MEMORIA_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

class Memoria {
public:
	Memoria();
	Memoria(const Memoria &modelo);
	Memoria(int tam);
	~Memoria();
	void reset();
	void store(int endereco, int valor);
	int load(int endereco) const;
	void exibir() const;
	int getTamanho() const;
	friend std::ostream& operator <<(std::ostream &output, const Memoria &mem);
	static const int TAMPALAVRA = 9999;
private:
	int *cells,
		tamanho;
};

#endif