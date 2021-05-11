/*O objetivo do projeto é fazer uso da criptografia de César com parâmetro 3, ou seja 
A = D, Z = C. 
O programa lê um arquivo .txt criptografado ou não e permite ao usuário descriptografar 
ou criptografar o mesmo, permitindo o acesso a informação contida no arquivo*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define PARAMETRO 3

using namespace std;

bool validaEscolha(int escolha);

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	FILE* arquivoOriginal;
	char textoASerLido[1000];
	char linha[1000];
	/* As letras "A" e "B" foram repetidos para caso haja algum "Y" ou "Z" não
	seja inserido um lixo de memória no lugar*/
	char alfabeto[29] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
	'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'A', 'B', 'C'};
	int escolha = 0;
	int validarEscolha = 0;
	int tamanhoTexto = 0;
	bool continuar = true;
	
	while (continuar) {
		system("cls");
		cout << " ***** Cifra de César *****\n";
		cout << " 1- Ler arquivo texto\n";
		cout << " 2- Criptografar\n";
		cout << " 3- Descriptografar\n";
		cout << " 9- Sair\n\n";
		cout << " Opção: ";
		cin >> escolha;
		
		validarEscolha = validaEscolha(escolha);
		
		system("cls");
		switch (escolha) {
			case 1: 
				cout << " ***** Cifra de César *****\n";
				cout << " Digite o nome do arquivo com a extensão: ";
				cin >> textoASerLido;
				arquivoOriginal = fopen(textoASerLido,"r");
				system("cls");
				
				if (arquivoOriginal==NULL) {
					cout << "\nOps! Arquivo não encontrado ou sem conteúdo.\n\n";
					system("pause");
					system("cls");
				} else{
					strcpy(textoASerLido,"");
					while(fgets(linha,1000,arquivoOriginal)!=NULL) {
						strcat(textoASerLido,linha);
					}
					cout << "Arquivo copiado com sucesso!\n\n";
					tamanhoTexto = strlen(textoASerLido);
					system("pause");
					fclose(arquivoOriginal);
				}
				break;
				
			case 2: 
				cout << " ***** Cifra de César *****\n";
				cout << " Texto Original: \n\n" << textoASerLido << "\n\n";
				
				//converte tudo para maiúsculo
				for (int i=0; i<tamanhoTexto; i++) {
					textoASerLido[i] = toupper(textoASerLido[i]);
				}

				//criptografa o texto
				for (int i=0; i<tamanhoTexto; i++) {
					for (int j=0; j<26; j++) {
						if (textoASerLido[i] == alfabeto[j]) {
							textoASerLido[i] = alfabeto[j+PARAMETRO];
							break;
						}
					}
				}
				
				cout << " Texto Criptografado: \n\n" << textoASerLido << "\n\n";
				system("pause");
				break;
				
			case 3:
				cout << " ***** Cifra de César *****\n";
				cout << " Texto Criptografado: \n\n" << textoASerLido << "\n\n";
				
				//Descriptografa o texto
				for (int i=0; i<tamanhoTexto; i++) {
					for (int j=0; j<26; j++) {
						if (textoASerLido[i] == alfabeto[j]) {
							textoASerLido[i] = alfabeto[j-PARAMETRO];
							break;
						}
					}
				}
				
				cout << " Texto Descriptografado: \n\n" << textoASerLido << "\n\n";
				system("pause");
				break;
				
			case 9:	
				continuar = false; 
				break;
		}
	}	
	
	return 0;
}

bool validaEscolha(int escolha) {
	if (escolha < 1 || (escolha > 3 && escolha != 9) ) {
		cout << "\n Insira uma opção válida!\n\n";
		system("pause");
	}
	return 1;
}
