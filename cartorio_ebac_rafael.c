#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região (caracteres especiais (acentos))
#include <string.h> //biblioteca de reconhecimento de strings

int registrar() //definindo funções que serão chamadas ao decorrer do programa (cadastro de usuario)
{
	setlocale(LC_ALL, "Portuguese"); //localização de linguagem
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //localização de linguagem
	
	//início da criações das variáveis
	char arquivo[15]; //criando variável para abertura e alteração de arquivo de registro e 
	char cpf[15]; //criando variável para ser utilizada em string (mesmo que CPF sejam números, são varios caracteres)
	char nome[20]; //criando variável para ser utilizada em string
	char sobrenome[40]; //o número entre colchetes representa a quantidade máxima de caracteres que a string vai processar.
	char cargo[40];
	//final da criação das variáveis
	
	
	//coletando informações para registro
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	
	printf("\n ---{ Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s para escanear "string"
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string cpf para a string arquivo
	
	FILE *dados; //FILE = comando para acessar a função na biblioteca, *dados é o nome que eu dei para o parâmetro que será chamado por futuros comandos
	dados = fopen(arquivo, "w"); //cria um arquivo no banco de dados (nesse caso na pasta do sistema do cartório) (w = write)
	fprintf(dados," __CPF: "); //após criar o arquivo com o comando anteriror, salva o " CPF: " no arquivo
	fclose(dados); //fecha o arquivo
	dados = fopen(arquivo, "a");
	fprintf(dados,cpf); //após abrir para atualização o arquivo com o comando anteriror, salva o "cpf" registrado pelo scanf logo acima
	fclose(dados);
	dados = fopen(arquivo, "a");
	fprintf(dados,"   __NOME: "); //conforme o comando anterior, salva uma "automaticamente" o que está entre "" após o ultimo dado, nesse caso, após o cpf inserido pelo usuário
	fclose(dados);
	
	system("cls"); //comando que limpa a tela após uma função ser completa
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	
	printf("\n ---{ Digite o nome: ");
	scanf("%s",nome);
	dados = fopen(arquivo, "a"); // se guiando pela variavel arquivo, abre um arquivo real com base no cpf com "a" para atualizar o arquivo
	fprintf(dados,nome); //atualiza conforme o comando anterior, salvando o "nome" registrado pelo scanf logo acima
	fclose(dados);
	dados = fopen(arquivo, "a");
	fprintf(dados," ");
	fclose(dados);
	
	system("cls");
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	
	printf("\n ---{ Digite o sobrenome: ");
	scanf("%s",sobrenome);
	dados = fopen(arquivo, "a");
	fprintf(dados,sobrenome);
	fclose(dados);
	dados = fopen(arquivo, "a");
	fprintf(dados,"   __CARGO: ");
	fclose(dados);
	
	system("cls");
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	
	printf("\n ---{ Digite o cargo: ");
	scanf("%s",cargo);
	dados = fopen(arquivo, "a");
	fprintf(dados,cargo);
	fclose(dados);
	
	system("cls");
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	printf("          ---{ Registro armazenado com sucesso }---\n\n\n\n\n");
	system("pause"); //comando que pausa o sistema para o usuário ler, prossegue clicando em qualquer tecla
}

int consultar() //função de consulta
{
	setlocale(LC_ALL, "Portuguese"); //localização de linguagem
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //localização de linguagem
	
	//criação de variáveis
	char cpf[15]; 
	char conteudo[200];
	
	//coletando e analisando cpf para consulta
	printf("\n ---____---___--__---  CONSULTAR NOMES  ---__--___---____---\n\n\n\n");
	printf("\n ---{ Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	system("cls");
	FILE *dados; //referindo o arquivo
	dados = fopen(cpf,"r"); //abrindo arquivo referente a dados em modo leitura
	
	while(fgets(conteudo, 200, dados) != NULL) //puxando o conteúdo do arquivo enquanto ele for != de nulo, até que acabem as informações com uma maxima de 200 caracteres
	{
		printf("\n ---____---___--__---  CONSULTAR NOMES  ---__--___---____---\n\n\n\n");
		printf("\t      ---{ Informações registradas }---\n\n\n");
		printf("%s", conteudo); //entregando oconteúdo do arquivo ao usuário
		printf("\n\n\n\n\n\n\n");
	}
	
	if(dados == NULL) //para quando o CPF for digitado errado
	{
		printf("\n ---____---___--__---  CONSULTAR NOMES  ---__--___---____---\n\n\n\n");
		printf("\t\t---{ CPF não registrado }---\n\n\n\n\n");
	}
	system("pause");
	fclose(dados);
}

int deletar() //função de deletar
{
	setlocale(LC_ALL, "Portuguese");
	setlocale (LC_ALL, "Portuguese_Brasil.1252");// localização de linguagem
	
	char cpf[15]; //variável para localizar o arquivo que será deletado
	
	//função irrelevante para o siste, mas que com a próxima cria um senso maior de necessidade de atenção ao CPF digitado
	printf("\n ---____---___--__---  DELETAR NOMES  ---__--___---____---\n\n\n\n");
	printf("\n ---{ Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	system("cls");
	
	//coletando dados para realmente deletar o CPF solicitado
	printf("\n ---____---___--__---  DELETAR NOMES  ---__--___---____---\n\n\n\n");
	printf("\n ---{ Digite novamente para confirmar: ");
	scanf("%s",cpf);
	system("cls");
	
	FILE *dados; //referindo o arquivo com base no CPF coletado
	dados = fopen(cpf,"r"); //aprindo arquivo apenas para leitura
	fclose(dados);
	
	if(dados != NULL)
	{
		remove(cpf); //função para deletar do banco de dados o arquivo de mesmo nome do CPF lido pela função scanf acima
		
		printf("\n ---____---___--__---  DELETAR NOMES  ---__--___---____---\n\n\n\n");
		printf("\n\t ---{ Registro deletado com sucesso }---\n\n\n\n");
		system("pause");
	}
	
	if(dados == NULL) //para o caso do CPF ter sido digitado errado
	{
		printf("\n ---____---___--__---  DELETAR NOMES  ---__--___---____---\n\n\n\n");
		printf("\n\t ---{ Registro não encontrado }---\n\n\n\n");
		system("pause");
	}
}

int main() //função principal
{
	
	int opcao=0; //definindo nome e valor da variável de decisão (numero inteiro)
	int laco=1; //sistema de repetição de processos
	
	for(laco=1;laco==1;) //nesse caso o loop acontecerá infinitamente, pois com "laco=1;" defino seu valor, enquanto que, com "laco==1;", digo que sempre que o valor for 1 ele deve se repitir após o fim das instruções
	                    //Existem diversos exemplos, mas por ex: for(laco=0;laco=1;) ou for(laco=30;laco=1;) ou for(laco=1;laco!=1;) o loop nunca aconteceria porque as informações são divergentes
	                   //for(laco=1;laco!=5;) é outro exemplo onde o loop aconteceria infinitamente, porém se
	                  //for(laco=0;laco!=5;laco++) o loop aconteceria 5 vezes, pois eu defino "laco=0" e depois digo que se ele "laco!=5" ele deve acontecer, mas depois da ultimia instrução, o break;, laco++ faz com que "laco=0" se torne "laco=1" e isso continua ocorrendo até "laco=5", nesse momento "laco não é !=5", então ele não executa o loop ou suas instruções e vai para a função seguinte.
	{
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //comando para setar que os caracteres especiais usados serão os do português
		setlocale (LC_ALL, "Portuguese_Brasil.1252"); 
	
		printf("\n ]]]____]]]___]]__---  CARTÓRIO DA EBAC  ---__[[___[[[____[[["); //início do menu
		printf("\n                    ----______________----\n\n\n\n"); // "\n = avançar uma linha"
		printf("\t ---{ Escolha a opção desejada do menu }--- \n\n\n"); // "\t = espaço inicial"
		printf("\t 1. Registrar nomes \n\n");
		printf("\t 2. Consultar nomes \n\n");
		printf("\t 3. Deletar nomes \n\n");
		printf("\t 4. Sair do sistema \n\n\n\n");
		printf("\t ---{ Escolher opção: ");
		
		scanf("%d", &opcao);
		
		system("cls"); //limpeza de tela pós escolha do usuário
		
		switch(opcao)
		{
			case 1:
			registrar(); //chamando função diretamente ao invés de executar processos dentro da função principal
			break;
				
			case 2:
			consultar();
			break;
				
			case 3:
			deletar();
			break;
				
			case 4:
			printf("\n\n          ---{ Obrigado por utilizar o sistema }---\n\n\n\n\n");
			return 0;
			break;
				
			default:
			printf("\n ---____---___--__---  OPÇÃO INVÁLIDA  ---__--___---____---\n\n\n\n");
			system("pause");
			break;
		}
		
		printf("\n\n Software desenvolvido por Rafael G. Ribeiro em 14/07/2023");
	}
}
