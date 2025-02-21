#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca para funcionamento de strings

//fun��es
//registro de usu�rios
int registro(){
	char arquivo[40];
	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Registro de nomes\n");
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	//copia os valores de uma string para outra string
	strcpy(arquivo,cpf);
	
	//cria o arquivo
	FILE *file;
	file = fopen(arquivo, "w");
	
	//salva o valor de cpf
	fprintf(file,cpf);
	//fecha o arquivo
	fclose(file);
	
	//separa por "."
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	//nome
	printf("\nDigite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	//salva o valor de nome
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fprintf(file,",");
	fclose(file);
	
	//sobrenome
	printf("\nDigite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fprintf(file,",");
	fclose(file);
	
	//cargo
	printf("\nDigite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}
int consulta(){
	setlocale(LC_ALL, "Portuguese");
	printf("Consulta de nomes\n\n");
	
	char cpf[40];
	char consulta[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Usu�rio n�o foi localizado.\n");
	}
	
	//ebqyabti tiver informa��o em file ele escreve na variavel consulta
	while(fgets(consulta, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", consulta);
		
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}
int remocao(){
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	printf("Remo��o de nomes\n");
	
	printf("Digite o CPF a ser removido: ");
	scanf("%s",cpf);
	
	//abre o arquivo
	FILE *file;
	file = fopen(cpf,"r");
	
	//localiza o usu�rio e informa se existe ou n�o e ent�o deleta
	if (file == NULL) {
		printf("\nO usu�rio n�o existe.\n");
	} else {
		remove(cpf);
		printf("\nUsu�rio deletado com sucesso!\n");
	}
	
	fclose(file);
	
	system("pause");
}

int main() {
	//defini��o de variaveis
	int opcao = 0;
	int x = 1;
	
	
	
	for ( x = 1; x = 1;){
		system("cls");
		//colocar caracteres brasileiros
		setlocale(LC_ALL, "Portuguese");
		
		//Menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha uma op��o no menu:\n");
		printf("\t(1) Registrar nome\n");
		printf("\t(2) Consultar os nomes\n");
		printf("\t(3) Remover nome\n");
		
		//rodap�
		printf("\nEsse Software � de livre uso.\n");
		
		printf("\nDigite o n�mero da op��o desejada: ");
		scanf("%d", &opcao);
		
		//limapa a tela
		system("cls");
		
		//op��es em switch
		switch(opcao) {
			case 1:
				registro();
				break;
			
			case 2:
				consulta();
				break;
				
			case 3:
				remocao();
				break;
			
			default:
				printf("O n�mero deve estar entre 1 e 3.\n");
				system("pause");
				break;
		}
		/*op��es
		if (opcao == 1) {
			printf("Registro de nomes\n");
			system("pause");
		}
		if (opcao == 2) {
			printf("Consulta de nomes\n");
			system("pause");
		}
		if (opcao == 3) {
			printf("Remo��o de nomes\n");
			system("pause");
		}
		if (opcao >= 4 || opcao <= 0) {
			printf("O n�mero deve estar entre 1 e 3.");
			system("pause");
		}
		*/
	}	
}
