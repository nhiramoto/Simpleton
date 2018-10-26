#include "interpretador.hpp"

using namespace std;

Interpretador::Interpretador(const string newPrompt = ">") :
	prompt(newPrompt)
{}

string Interpretador::prompt() {}

void setPrompt(string newPrompt) {
	prompt = newPrompt;
}