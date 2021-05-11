#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 30

using namespace std;

int main() {
	
	typedef struct {
		char item[MAX];
		int topo;
	}PILHA;
	
	setlocale(LC_ALL, "Portuguese");
	char expressao[MAX];
	int posicaoParenteses = 0;
	PILHA pilhaParenteses;
	pilhaParenteses.topo = 0;
	
	cout << "**** VERIFICAR PARÊNTESES NA EXPRESSÃO ******\n";
	cout << "Insira a Expressão: ";
	gets (expressao);
	
	int tamanhoExpressao = strlen(expressao);
	
	for (int i=0; i<tamanhoExpressao; i++) {
		
		// Verifica se é parênteses/chaves
		if (expressao[i] != '(' && expressao[i] != ')' && 
			expressao[i] != '[' && expressao[i] != ']') {
			continue;
		}
		
		// Empilha
		if (expressao[i] == '(') {
			pilhaParenteses.item[posicaoParenteses] = '(';
			pilhaParenteses.topo++;
			posicaoParenteses++;
		}
		if (expressao[i] =='[') {
			pilhaParenteses.item[posicaoParenteses] = '[';
			pilhaParenteses.topo++;
			posicaoParenteses++;
		}
		
		// Desempilha
		if (expressao[i] == ')') {
			for (int i=0; i<tamanhoExpressao; i++) {
				if(pilhaParenteses.item[i] == '(') {
					pilhaParenteses.item[i] = ' ';
				}
				pilhaParenteses.topo--;
				posicaoParenteses--;
				break;
			}
		}
		if (expressao[i] == ']') {
			for (int i=0; i<tamanhoExpressao; i++) {
				if(pilhaParenteses.item[i] == ']') {
					pilhaParenteses.item[i] = ' ';
				}
				pilhaParenteses.topo--;
				posicaoParenteses--;
				break;
			}
		}
		
		// Verifica a ordem dos parênteses/chaves
		if ( (expressao[i] == '(' && expressao[i+1] == '[') || 
			 (expressao[i] == ']' && expressao[i+1] == ')') ) {
			pilhaParenteses.topo = -1;
		}
	}
	
	system("cls");
	cout << "**** VERIFICAR PARÊNTESES NA EXPRESSÃO ******\n";
	if (pilhaParenteses.topo == 0) {
		cout << "A expressão está correta!\n";
	} else {
		cout << "Há erro(s) na expressão!\n";
	}
	
	return 0;
}
