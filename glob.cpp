#include "glob.hpp"

using namespace std;

#ifdef _WIN32

void pause() {
	system("pause");
}

void limpaTela() {
	system("cls");
}

#elif linux

void pause() {
	system("echo \"[Enter] para continuar...\"");
	system("read a");
}

void limpaTela() {
	system("clear");
}

#endif

int stringToInt(const string numero) {
	static int i;
	i = numero.length() - 1;
	if(numero.empty()) return 0;
	else {
		char dig = numero.at(i);
		i--;
		if(isDigit(dig))
			return stringToInt(numero.substr(0, numero.length() - 1))*10 + charToDigit(dig);
		else return stringToInt(numero.substr(0, numero.length() - 1));
	}
}

bool isDigit(const char dig) {
	if(dig >= '0' && dig <= '9')
		return true;
	else return false;
}

int charToDigit(const char ch) {
	if(isDigit(ch))
		return static_cast<int>(ch - static_cast<int>('0'));
	else return 0;
}