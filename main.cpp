#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	int quantidadeNumerosSorteados = 0;
	int maior = 0;
	
	cout << " ***** ORDENADOR ***** \n";
	cout << "Quantos números serão inseridos?\n";
	cout << "Quantidade: ";
	cin >> quantidadeNumerosSorteados;
	system("clear");
	
	int numerosSorteados[quantidadeNumerosSorteados];
	cout << " ***** ORDENADOR ***** \n";
	for (int i=0; i<quantidadeNumerosSorteados; i++){
		cout << " Insira o " << i+1 << "º número: "; 
		cin >> numerosSorteados[i];
		cout << endl;
	}
	system("clear");
	
	for (int i=0; i < quantidadeNumerosSorteados-1; i++) {
		for (int j=i+1; j < quantidadeNumerosSorteados; j++) {
			if (numerosSorteados[i] > numerosSorteados[j]) {
				maior = numerosSorteados[i];
				numerosSorteados[i] = numerosSorteados[j];
				numerosSorteados[j] = maior;
			}
		}
	}
	
    cout << "Os números em ordem crescente são: \n";
	for(int i=0; i<quantidadeNumerosSorteados; i++) {
		cout << numerosSorteados[i] << " ";
	}
	
	return 0;
}
