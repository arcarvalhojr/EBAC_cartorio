#include <stdio.h> //biblioteca de comunica��o
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de textod por regi�o - idiomas
#include <string.h> //biblioteca de gerenciamento de strings

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //especifica��o do idioma portugues nos textos
	
	char cpf[40]; //definindo variaveis/strings
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char conteudo[200];
	
	printf("\tConsulte o usu�rio desejado.\n\n");
	printf("Digite o CPF do usu�rio: ");
	scanf("%s", cpf);
	
	system("cls"); //limpar mensagens anteriores para melhor visualiza��o das seguintes
	
	FILE *file; //buscar o arquivo
	file = fopen(cpf, "r"); //lendo as informa��es em um arquivo 
	
	if(file == NULL)
	{
		printf("CPF inv�lido! Arquivo n�o existente.\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL) //salvando as informa��es em uma variavel
	{	
		sscanf(conteudo, "%[^,], %[^,], %[^,], %[^\n]", cpf, nome, sobrenome, cargo); //lendo os dados da string e formatando a partir da ,
        printf("\tInforma��es do usu�rio:\n\n");
        printf("CPF: %s\n", cpf);
        printf("Nome: %s\n", nome);
        printf("Sobrenome: %s\n", sobrenome);
        printf("Cargo: %s\n", cargo);     	
	}
	
	system("pause");
	fclose(file);
}
int registro()
{
	char arquivo[40]; //definindo variaveis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\tRegistro de novo usu�rio.\n\n");
	printf("Preencha os campos a seguir.\n");
	
	printf("CPF: ");
	scanf("%s", cpf); //alocando a resposta do usuario na variavel/string
	strcpy(arquivo, cpf); //copia o valor das strings
	
	FILE *file; //buscar o arquivo
	file = fopen(arquivo, "w"); //criar o arquivo, escrever um arquivo novo
	fprintf(file, cpf); //salva o valor da string no arquivo criado
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza um arquivo ja criado
	fprintf(file, ", "); //separando cada valor com ,
	fclose(file);
	
	printf("Nome: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Sobrenome: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Cargo: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}
int excluir()
{
	char cpf[40];
	
	printf("\tExcluir usu�rios.\n\n");
	printf("Digite o CPF do us�ario: ");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	remove(cpf);
	
	if(file == NULL)
	{	
		printf("Usu�rio n�o encontrado no sistema.\n");
		system("pause");
	}
	else
	{
		printf("Usuario deletado!\n");
		system("pause");
	}
}

int main() //fun��o principal 
{
	
	int opcao= 0; //definindo a variavel
	int repetir= 1;
	
	for(repetir=1; repetir=1;) //introduzindo repeti��o no programa
	{
	
		system("cls"); //limpar mensagens anteriores quando o programa recome�ar
		
		setlocale(LC_ALL, "Portuguese"); //especifica��o do idioma portugues nos textos

		printf("   PLATAFORMA DE GERENCIAMENTO DE USU�RIOS - EBAC\n\n"); //inicio do menu
		printf("   Escolha uma das op��es no menu:\n\n");
		printf("\t1: Consultar usu�rios\n");
		printf("\t2: Registro de usu�rios\n");
		printf("\t3: Exclus�o de usu�rios\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //identificar a resposta do usuario e armazenar na variavel
	
		system("cls"); //limpar mensagens anteriores para melhor visualiza��o das seguintes
		
		switch(opcao) //opereador logico para sele��o das op��es do menu
		{
			case 1: //inicio da sele��o
			consulta();
			break;
			
			case 2:
			registro();
			break;
		
			case 3: 
			excluir();
			break; 
			
			default:
			printf("Essa op��o n�o est� disponivel!\n\n");
			system("pause");
			break;
		} //fim da sele��o
	}
}
