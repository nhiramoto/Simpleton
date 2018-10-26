#include "main.hpp"

using namespace std;

int main() {
	Simpleton comp;	
	string prog;

	limpaTela();
	cout << "\t==========================" << endl
		 << "\t| Bem vindo ao Simpleton |" << endl
		 << "\t==========================" << endl
		 << "Insira o nome do arquivo:\n> ";
	cin >> prog;

	comp.executaPrograma(prog);
	cout << endl;
	comp.dump();

	cout << endl;
	pause();
	return(EXIT_SUCCESS);
}