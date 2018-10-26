#ifndef _INTERPRETADOR_H_
#define _INTERPRETADOR_H_

#include <iostream>
#include <string>

class Interpretador {
public:
	Interpretador(const string newPrompt = ">");
	string prompt();
	void setPrompt(string newPrompt);
private:
	string prompt;
};

#endif