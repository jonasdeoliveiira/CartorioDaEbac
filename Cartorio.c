#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //função responsável por cadastrar os usuários do sistema
{
	//inicio da criação de strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf);  //%s para salvar uma string
	
	strcpy(arquivo, cpf); //responsável por copíar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
			
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
	system("cls");
	
	int opcao=0;
	
	printf("Deseja registrar outro usuário?:\n"); 
	printf("\t1 - sim\n");
	printf("\t2 - não\n");
	printf("Opcao: ");
	
	scanf("%d", &opcao);
	
	system("cls");
	
	if(opcao == 1)
	{
		registrar();
	}
	
	if(opcao == 2)
	{
		return 0;
	}
	
}

int consultar()
{	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo. Não localizado!\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
	fclose(file);
	
	system("cls");
	
	int opcao=0;
	
	printf("Deseja consultar outro usuário?:\n\n"); 
	printf("\t1 - sim\n");
	printf("\t2 - não\n\n");
	printf("Opcao: ");
	
	scanf("%d", &opcao);
	
	system("cls");
	
	if(opcao == 1)
	{
		consultar();
	}
	
	if(opcao == 2)
	{
		return 0;
	}
	
}

int deletar()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	system("cls");
	
	if(file == NULL)
	{
		printf("O usuário não foi encontrado no sistema!\n");
		system("pause");
		
		system("cls");
		
		int opcao=0;
				
		printf("Deseja procurar outro usuário para deletar?:\n"); 
		printf("\t1 - sim\n");
		printf("\t2 - não\n\n");
		printf("Opcao: ");
			
		scanf("%d", &opcao);
		
		system("cls");
				
		if(opcao == 1)
		{
			deletar();
		}
		
		if(opcao == 2)
		{
			return 0;
		}
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário que será deletado: \n\n");
		printf("%s", conteudo);
		
		
		int opcao=0;
			
		printf("\n\nConfirmar exclusão?:\n"); 
		printf("\t1 - sim\n");
		printf("\t2 - não\n\n");
		printf("Opcao: ");
			
		scanf("%d", &opcao);
		
		fclose(file);
		system("cls");
		
		if(opcao == 1)
		{
			printf("O usuário foi deletado do sistema!\n");
			system("pause");
			
			system("cls");
			
			int opcao=0;
					
			printf("Deseja procurar outro usuário para deletar?:\n"); 
			printf("\t1 - sim\n");
			printf("\t2 - não\n\n");
			printf("Opcao: ");
						
			scanf("%d", &opcao);
				
			system("cls");
					
			if(opcao == 1)
			{
				deletar();
			}
			
			if(opcao == 2)
			{
				int main();
			}
									
		}
		
		if(opcao == 2)
		{
			printf("Usuário não deletado!\n");
			system("pause");
		}
		
	}
	fclose(file);
	remove(cpf);

}
	
int main() 
	{
	int opcao=0; //definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
		
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");	
		for (laco=1;laco=1;)
		{
				
			setlocale(LC_ALL, "Portuguese"); //definição da linguagem
			
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha as opções desejadas do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opcao: "); //fim do menu
				
			scanf("%d", &opcao); //armazenando a escolha do usuário
						
			system("cls"); //responsável por limpar a tela
			
			
			switch(opcao)
			{
				case 1:
				registrar();
				break;
		
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opcao está indisponível!\n");
				system("pause");
				break; //fim da seleção				
			}								
		}
	}
	
	else
	printf("Senha incorreta!");
	
}
	
