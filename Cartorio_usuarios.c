#include <stdio.h> //biblioteca de comunicação
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de textod por região - idiomas
#include <string.h> //biblioteca de gerenciamento de strings

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //especificação do idioma portugues nos textos
	
	char cpf[40]; //definindo variaveis/strings
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char conteudo[200];
	
	printf("\tConsulte o usuário desejado.\n\n");
	printf("Digite o CPF do usuário: ");
	scanf("%s", cpf);
	
	system("cls"); //limpar mensagens anteriores para melhor visualização das seguintes
	
	FILE *file; //buscar o arquivo
	file = fopen(cpf, "r"); //lendo as informações em um arquivo 
	
	if(file == NULL)
	{
		printf("CPF inválido! Arquivo não existente.\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL) //salvando as informações em uma variavel
	{	
		sscanf(conteudo, "%[^,], %[^,], %[^,], %[^\n]", cpf, nome, sobrenome, cargo); //lendo os dados da string e formatando a partir da ,
        printf("\tInformações do usuário:\n\n");
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
	
	printf("\tRegistro de novo usuário.\n\n");
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
	
	printf("\tExcluir usuários.\n\n");
	printf("Digite o CPF do usúario: ");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	remove(cpf);
	
	if(file == NULL)
	{	
		printf("Usuário não encontrado no sistema.\n");
		system("pause");
	}
	else
	{
		printf("Usuario deletado!\n");
		system("pause");
	}
}

int main() //função principal 
{
	
	int opcao= 0; //definindo a variavel
	int repetir= 1;
	
	for(repetir=1; repetir=1;) //introduzindo repetição no programa
	{
	
		system("cls"); //limpar mensagens anteriores quando o programa recomeçar
		
		setlocale(LC_ALL, "Portuguese"); //especificação do idioma portugues nos textos

		printf("   PLATAFORMA DE GERENCIAMENTO DE USUÁRIOS - EBAC\n\n"); //inicio do menu
		printf("   Escolha uma das opções no menu:\n\n");
		printf("\t1: Consultar usuários\n");
		printf("\t2: Registro de usuários\n");
		printf("\t3: Exclusão de usuários\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //identificar a resposta do usuario e armazenar na variavel
	
		system("cls"); //limpar mensagens anteriores para melhor visualização das seguintes
		
		switch(opcao) //opereador logico para seleção das opções do menu
		{
			case 1: //inicio da seleção
			consulta();
			break;
			
			case 2:
			registro();
			break;
		
			case 3: 
			excluir();
			break; 
			
			default:
			printf("Essa opção não está disponivel!\n\n");
			system("pause");
			break;
		} //fim da seleção
	}
}
